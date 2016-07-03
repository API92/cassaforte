/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cstddef>
#include <new>

#include <cass/impexp.hpp>

namespace cass {

namespace detail {

struct CASSA_IMPEXP counter_type {
    static void * operator new(std::size_t sz, std::nothrow_t) noexcept;
    static void operator delete(void *p);

    size_t value;
};

} // namespace detail

template<typename T, void (*static_res_deleter)(T)>
class shared_res {
public:
    ~shared_res()
    {
        try {
            detach();
        }
        catch (...) {}
    }

    shared_res(T res, bool holds_start)
        : res(res)
    {
        init_cnt(holds_start);
    }

    shared_res(const shared_res &other)
        : res(other.res), cnt(other.cnt)
    {
        if (cnt)
            cnt->value += 2;
    }

    shared_res(shared_res &&other)
        : res(other.res), cnt(other.cnt)
    {
        other.cnt = nullptr;
    }

    shared_res & operator = (const shared_res &other)
    {
        if (this != &other) {
            detach();
            res = other.res;
            cnt = other.cnt;
            if (cnt)
                cnt->value += 2;
        }
        return *this;
    }

    shared_res & operator = (shared_res &&other)
    {
        if (this != &other) {
            detach();
            res = other.res;
            cnt = other.cnt;
            other.cnt = nullptr;
        }
        return *this;
    }

    T & get()
    {
        return res;
    }

    const T & get() const
    {
        return res;
    }

    template<typename U = T>
    U get() const noexcept
    {
        return reinterpret_cast<U>(res);
    }

    /** disown resource and decrement reference counter */
    void detach()
    {
        if (cnt) {
            if ((cnt->value -= 2) >= 2)
                cnt = nullptr;
            else {
                bool save_holds = cnt->value;
                delete cnt;
                cnt = nullptr;
                if (save_holds)
                    static_res_deleter(res);
            }
        }
    }

    /** resource shared to this object and not destructed. */
    bool holds() const
    {
        return cnt && (cnt->value & 1);
    }

    /** destruct resource and mark it destructed for other shares */
    void kill()
    {
        if (holds()) {
            if ((cnt->value -= 2) >= 2)
                cnt->value ^= 1;
            else
                delete cnt;
            cnt = nullptr;
            static_res_deleter(res);
        }
    }

    /** disown old resource and setup new resource */
    void reset(T new_res, bool holds_new)
    {
        detach();
        res = new_res;
        init_cnt(holds_new);
    }

private:
    void init_cnt(bool holds_start)
    {
        if (holds_start) {
            if ((cnt = new (std::nothrow) detail::counter_type)) {
                cnt->value = 2 | holds_start;
            }
            else {
                static_res_deleter(res);
                throw std::bad_alloc();
            }
        }
        else
            cnt = nullptr;
    }

    T res;
    /* cnt == nullptr means resource not shared to this object (but this object
     *     still may contain old resource value in res).
     * (cnt->value & 1) == 0 means resource destructed (but this object
     *     still may contain old resource value in res).
     */
    detail::counter_type *cnt;
};

} // namespace cass

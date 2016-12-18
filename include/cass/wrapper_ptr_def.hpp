/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include "wrapper_ptr.hpp"

#include <cassert>
#include <cstddef>
#include <new>

#include "impexp.hpp"

namespace cass {

namespace detail {

struct CASSA_IMPEXP counter_type {
    static void * operator new(std::size_t sz, std::nothrow_t) noexcept;
    static void operator delete(void *p);

    size_t value;
};

} // namespace detail

template<typename T>
inline void wrapper_ptr<T>::static_res_deleter(T *value)
{
    value->free();
}

template<typename T>
wrapper_ptr<T>::wrapper_ptr() : res(nullptr), cnt(nullptr) {}

template<typename T>
wrapper_ptr<T>::~wrapper_ptr()
{
    try {
        detach();
    }
    catch (...) {}
}

template<typename T>
template<typename U>
wrapper_ptr<T>::wrapper_ptr(U *res, bool holds_start)
    : res(res)
{
    init_cnt(holds_start);
}

template<typename T>
wrapper_ptr<T>::wrapper_ptr(wrapper_ptr const &other) :
    res(other.res), cnt(other.cnt)
{
    if (cnt)
        cnt->value += 2;
}

template<typename T>
wrapper_ptr<T>::wrapper_ptr(wrapper_ptr &&other)
    : res(other.res), cnt(other.cnt)
{
    other.cnt = nullptr;
}

template<typename T>
wrapper_ptr<T> & wrapper_ptr<T>::operator = (const wrapper_ptr &other)
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

template<typename T>
wrapper_ptr<T> & wrapper_ptr<T>::operator = (wrapper_ptr &&other)
{
    if (this != &other) {
        detach();
        res = other.res;
        cnt = other.cnt;
        other.cnt = nullptr;
    }
    return *this;
}

template<typename T>
wrapper_ptr<T>::operator bool () const
{
    return !!res;
}

template<typename T>
T * wrapper_ptr<T>::get() const
{
    return res;
}

template<typename T>
T * wrapper_ptr<T>::operator -> () const
{
    return res;
}

template<typename T>
T & wrapper_ptr<T>::operator * () const
{
    assert(holds());
    return *res;
}

/// Disown resource and decrement reference counter.
template<typename T>
void wrapper_ptr<T>::detach()
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

/// Resource shared to this object and not destructed.
template<typename T>
bool wrapper_ptr<T>::holds() const
{
    return cnt && (cnt->value & 1);
}

/// Destruct resource and mark it destructed for other shares.
template<typename T>
void wrapper_ptr<T>::kill()
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

/// Disown old resource and setup new resource.
template<typename T>
void wrapper_ptr<T>::reset(T * new_res, bool holds_new)
{
    detach();
    res = new_res;
    init_cnt(holds_new);
}

template<typename T>
void wrapper_ptr<T>::init_cnt(bool holds_start)
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

} // namespace cass

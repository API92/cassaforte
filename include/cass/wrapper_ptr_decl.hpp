/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

namespace cass {

namespace detail {

struct counter_type;

} // namespace detail

template<typename T>
class wrapper_ptr {
public:
    inline void static_res_deleter(T *value);

    wrapper_ptr();
    ~wrapper_ptr();

    template<typename U>
    wrapper_ptr(U *res, bool holds_start);

    wrapper_ptr(wrapper_ptr const &other);

    template<typename U>
    wrapper_ptr(const wrapper_ptr<U> &other);

    template<typename U>
    wrapper_ptr(wrapper_ptr<U> &&other);

    template<typename U>
    wrapper_ptr & operator = (const wrapper_ptr<U> &other);

    template<typename U>
    wrapper_ptr & operator = (wrapper_ptr<U> &&other);

    operator bool () const;

    T * get() const;

    T * operator -> () const;

    T & operator * () const;

    /// Disown resource and decrement reference counter.
    void detach();

    /// Resource shared to this object and not destructed.
    bool holds() const;

    /// Destruct resource and mark it destructed for other shares.
    void kill();

    /// Disown old resource and setup new resource.
    void reset(T * new_res, bool holds_new);

private:
    void init_cnt(bool holds_start);

    T *res;
    /* cnt == nullptr means resource not shared to this object (but this object
     *     still may contain old resource value in res).
     * (cnt->value & 1) == 0 means resource destructed (but this object
     *     still may contain old resource value in res).
     */
    detail::counter_type *cnt;
};

} // namespace cass

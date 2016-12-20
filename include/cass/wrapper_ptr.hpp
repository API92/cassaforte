/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

namespace cass {

template<typename T>
class wrapper_ptr {
public:
    wrapper_ptr();
    ~wrapper_ptr();

    explicit wrapper_ptr(T *res);

    wrapper_ptr(wrapper_ptr const &other) = delete;

    wrapper_ptr(wrapper_ptr &&other);

    wrapper_ptr & operator = (wrapper_ptr const &other) = delete;

    wrapper_ptr & operator = (wrapper_ptr &&other);

    operator bool () const;

    T * get() const;

    T * operator -> () const;

    T & operator * () const;

    void reset(T *new_p = nullptr);
    void release();

private:
    T *_p;
};

} // namespace cass

/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include "wrapper_ptr.hpp"

#include <cassert>
#include <cstddef>
#include <new>

namespace cass {

template<typename T>
wrapper_ptr<T>::wrapper_ptr() : _p(nullptr) {}

template<typename T>
wrapper_ptr<T>::~wrapper_ptr()
{
    reset();
}

template<typename T>
wrapper_ptr<T>::wrapper_ptr(T *res) : _p(res) {}

template<typename T>
wrapper_ptr<T>::wrapper_ptr(wrapper_ptr &&other)
    : _p(other._p)
{
    other._p = nullptr;
}

template<typename T>
wrapper_ptr<T> & wrapper_ptr<T>::operator = (wrapper_ptr &&other)
{
    if (this != &other) {
        reset(other._p);
        other._p = nullptr;
    }
    return *this;
}

template<typename T>
wrapper_ptr<T>::operator bool () const
{
    return !!_p;
}

template<typename T>
T * wrapper_ptr<T>::get() const
{
    return _p;
}

template<typename T>
T * wrapper_ptr<T>::operator -> () const
{
    return _p;
}

template<typename T>
T & wrapper_ptr<T>::operator * () const
{
    assert(_p);
    return *_p;
}

template<typename T>
void wrapper_ptr<T>::reset(T *new_p)
{
    if (_p)
        _p->free();
    _p = new_p;
}

} // namespace cass

/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassert>
#include <type_traits>

#include <cass/shared_res.hpp>

namespace cass {

template<typename T>
class wrapper_const_ptr : public shared_res<T, T::free> {
    typedef shared_res<T, T::free> parent_type;
public:
    using parent_type::shared_res;
    operator bool () const { return parent_type::get().backend() != nullptr; }
    T * get() { return &parent_type::get(); }
    T * operator -> ()
    {
        assert(*this);
        return &parent_type::get();
    }
    T & operator * ()
    {
        assert(*this);
        return T::get();
    }
};

template<typename T>
class wrapper_ptr : public wrapper_const_ptr<T> {
public:
    using wrapper_const_ptr<T>::wrapper_const_ptr;

    operator wrapper_const_ptr<T const> ()
    {
        return wrapper_const_ptr<T const>(**this, this->holds());
    }
};

template<typename T>
class dummy_ptr {
public:
    template<typename ... Args>
    dummy_ptr(Args ... args) : m(args...) {}
    operator bool () const { return m.backend() != nullptr; }
    T * get() const { return m.backend() ? &m : nullptr; }
    T * operator -> () const
    {
        assert(*this);
        return &m;
    }
    T & operator * () const
    {
        assert(*this);
        return m;
    }

private:
    T m;
};

} // namespace cass
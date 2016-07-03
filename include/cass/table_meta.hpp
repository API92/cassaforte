/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassert>

#include <cassandra.h>

namespace cass {

class table_meta {
public:
    explicit table_meta(::CassTableMeta const *p) : p(p) {}
    ::CassTableMeta const * backend() const { return p; }

private:
    ::CassTableMeta const *p;
};

class table_meta_const_ptr {
public:
    explicit table_meta_const_ptr(::CassTableMeta const *p) : m(p) {}
    operator bool () const { return m.backend() != nullptr; }
    table_meta const * get() const { return m.backend() ? &m : nullptr; }
    table_meta const * operator -> () const
    {
        assert(get());
        return get();
    }
    table_meta const & operator * () const
    {
        assert(get());
        return m;
    }

private:
    table_meta const m;
};

} // namespace cass

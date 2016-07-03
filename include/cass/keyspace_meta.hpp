/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassert>

#include <cassandra.h>

#include <cass/defs.hpp>
#include <cass/impexp.hpp>

namespace cass {

class keyspace_meta {
public:
    explicit keyspace_meta(::CassKeyspaceMeta const *p) : p(p) {}
    ::CassKeyspaceMeta const * backend() const { return p; }

    inline void name(char const **name, size_t *name_length) const;

    CASSA_IMPEXP table_meta_const_ptr table_by_name(
            char const *table) const;
    CASSA_IMPEXP table_meta_const_ptr table_by_name_n(
            char const *table, size_t table_length) const;

    CASSA_IMPEXP materialized_view_meta_const_ptr materialized_view_by_name(
            char const *view) const;
    CASSA_IMPEXP materialized_view_meta_const_ptr materialized_view_by_name_n(
            char const *view, size_t view_length) const;

private:
    ::CassKeyspaceMeta const *p;
};


class keyspace_meta_const_ptr {
public:
    keyspace_meta_const_ptr(::CassKeyspaceMeta const *p) : m(p) {}
    operator bool () const { return m.backend() != nullptr; }
    keyspace_meta const * get() const { return m.backend() ? &m : nullptr; }
    keyspace_meta const * operator -> () const
    {
        assert(get());
        return get();
    }
    keyspace_meta const & operator * () const
    {
        assert(get());
        return m;
    }

private:
    keyspace_meta const m;
};


///
/// keyspace_meta
///

inline void keyspace_meta::name(char const **name, size_t *name_length) const
{
    ::cass_keyspace_meta_name(p, name, name_length);
}

} // namespace cass

/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/defs.hpp>
#include <cass/impexp.hpp>
#include <cass/wrapper_ptr.hpp>

namespace cass {

class keyspace_meta {
public:
    static keyspace_meta const * ptr(::CassKeyspaceMeta const *p)
    {
        return reinterpret_cast<keyspace_meta const *>(p);
    }

    ::CassKeyspaceMeta const * backend() const
    {
        return reinterpret_cast<::CassKeyspaceMeta const *>(this);
    }

    inline void name(char const **name, size_t *name_length) const;

    CASSA_IMPEXP table_meta const * table_by_name(
            char const *table) const;
    CASSA_IMPEXP table_meta const * table_by_name_n(
            char const *table, size_t table_length) const;

    CASSA_IMPEXP materialized_view_meta const * materialized_view_by_name(
            char const *view) const;
    CASSA_IMPEXP materialized_view_meta const * materialized_view_by_name_n(
            char const *view, size_t view_length) const;

    CASSA_IMPEXP data_type const * user_type_by_name(char const *type) const;
    CASSA_IMPEXP data_type const * user_type_by_name_n(
            char const *type, size_t type_length) const;

    CASSA_IMPEXP function_meta const * function_by_name(char const *name,
            char const *arguments) const;
    CASSA_IMPEXP function_meta const * function_by_name_n(
            char const *name, size_t name_length,
            char const *arguments, size_t arguments_length) const;

    CASSA_IMPEXP aggregate_meta const * aggregate_by_name(char const *name,
            char const *arguments) const;
    CASSA_IMPEXP aggregate_meta const * aggregate_by_name_n(
            char const *name, size_t name_length,
            char const *arguments, size_t arguments_length) const;

    CASSA_IMPEXP value const * field_by_name(char const *name) const;
    CASSA_IMPEXP value const * field_by_name_n(char const *name,
            size_t name_length) const;
};


inline void keyspace_meta::name(char const **name, size_t *name_length) const
{
    ::cass_keyspace_meta_name(backend(), name, name_length);
}

} // namespace cass

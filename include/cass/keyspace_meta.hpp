/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/defs.hpp>
#include <cass/impexp.hpp>
#include <cass/wrapper_ptr.hpp>

namespace cass {

typedef dummy_ptr<class keyspace_meta const> keyspace_meta_const_ptr;

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

    CASSA_IMPEXP data_type_const_ptr user_type_by_name(char const *type) const;
    CASSA_IMPEXP data_type_const_ptr user_type_by_name_n(
            char const *type, size_t type_length) const;

    CASSA_IMPEXP function_meta_const_ptr function_by_name(char const *name,
            char const *arguments) const;
    CASSA_IMPEXP function_meta_const_ptr function_by_name_n(
            char const *name, size_t name_length,
            char const *arguments, size_t arguments_length) const;

    CASSA_IMPEXP aggregate_meta_const_ptr aggregate_by_name(char const *name,
            char const *arguments) const;
    CASSA_IMPEXP aggregate_meta_const_ptr aggregate_by_name_n(
            char const *name, size_t name_length,
            char const *arguments, size_t arguments_length) const;

    CASSA_IMPEXP value_const_ptr field_by_name(char const *name) const;
    CASSA_IMPEXP value_const_ptr field_by_name_n(char const *name,
            size_t name_length) const;

private:
    ::CassKeyspaceMeta const *p;
};


inline void keyspace_meta::name(char const **name, size_t *name_length) const
{
    ::cass_keyspace_meta_name(p, name, name_length);
}

} // namespace cass

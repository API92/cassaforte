/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include "delete_defaults.hpp"
#include "forward.hpp"
#include "impexp.hpp"

typedef struct CassKeyspaceMeta_ CassKeyspaceMeta;

namespace cass {

class CASSA_IMPEXP keyspace_meta : delete_defaults {
public:
    static keyspace_meta const * ptr(::CassKeyspaceMeta const *p);

    ::CassKeyspaceMeta const * backend() const;

    void name(char const **name, size_t *name_length) const;

    table_meta const * table_by_name(
            char const *table) const;
    table_meta const * table_by_name_n(
            char const *table, size_t table_length) const;

    materialized_view_meta const * materialized_view_by_name(
            char const *view) const;
    materialized_view_meta const * materialized_view_by_name_n(
            char const *view, size_t view_length) const;

    data_type const * user_type_by_name(char const *type) const;
    data_type const * user_type_by_name_n(
            char const *type, size_t type_length) const;

    function_meta const * function_by_name(char const *name,
            char const *arguments) const;
    function_meta const * function_by_name_n(
            char const *name, size_t name_length,
            char const *arguments, size_t arguments_length) const;

    aggregate_meta const * aggregate_by_name(char const *name,
            char const *arguments) const;
    aggregate_meta const * aggregate_by_name_n(
            char const *name, size_t name_length,
            char const *arguments, size_t arguments_length) const;

    value const * field_by_name(char const *name) const;
    value const * field_by_name_n(char const *name,
            size_t name_length) const;
};

} // namespace cass

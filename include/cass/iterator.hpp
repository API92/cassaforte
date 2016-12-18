/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include "delete_defaults.hpp"
#include "forward.hpp"
#include "impexp.hpp"

typedef struct CassIterator_ CassIterator;

namespace cass {

class CASSA_IMPEXP iterator : delete_defaults {
public:
    static iterator * ptr(::CassIterator *p);

    ::CassIterator * backend();
    ::CassIterator const * backend() const;

    void free();

    static iterator_ptr from_result(cass::result const *result);

    static iterator_ptr from_row(cass::row const *row);

    static iterator_ptr from_collection(cass::value const *value);

    static iterator_ptr from_map(cass::value const *value);

    static iterator_ptr from_tuple(cass::value const *value);

    static iterator_ptr fields_from_user_type(
            cass::value const *value);

    static iterator_ptr keyspaces_from_schema_meta(
            cass::schema_meta const *schema_meta);

    static iterator_ptr tables_from_keyspace_meta(
            cass::keyspace_meta const *keyspace_meta);

    static iterator_ptr materialized_views_from_keyspace_meta(
            cass::keyspace_meta const *keyspace_meta);

    static iterator_ptr user_types_from_keyspace_meta(
            cass::keyspace_meta const *keyspace_meta);

    static iterator_ptr functions_from_keyspace_meta(
            cass::keyspace_meta const *keyspace_meta);

    static iterator_ptr aggregates_from_keyspace_meta(
            cass::keyspace_meta const *keyspace_meta);

    static iterator_ptr fields_from_keyspace_meta(
            cass::keyspace_meta const *keyspace_meta);

    static iterator_ptr columns_from_table_meta(
            cass::table_meta const *table_meta);

    static iterator_ptr indexes_from_table_meta(
            cass::table_meta const *table_meta);

    static iterator_ptr materialized_views_from_table_meta(
            cass::table_meta const *table_meta);

    static iterator_ptr fields_from_table_meta(
            cass::table_meta const *table_meta);

    static iterator_ptr columns_from_materialized_view_meta(
            materialized_view_meta const *view_meta);

    static iterator_ptr fields_from_materialized_view_meta(
            materialized_view_meta const *view_meta);

    static iterator_ptr fields_from_column_meta(
            cass::column_meta const *column_meta);

    static iterator_ptr fields_from_index_meta(
            cass::index_meta const *index_meta);

    static iterator_ptr fields_from_function_meta(
            cass::function_meta const *function_meta);

    static iterator_ptr fields_from_aggregate_meta(
            cass::aggregate_meta const *aggregate_meta);

    iterator_type type();

    bool next();

    row const * get_row() const;

    value const * get_column() const;

    value const * get_value() const;

    value const * get_map_key() const;

    value const * get_map_value() const;

    error get_user_type_field_name(char const **name,
            size_t *name_length);

    value const * get_user_type_field_value();

    keyspace_meta const * get_keyspace_meta() const;

    table_meta const * get_table_meta() const;

    materialized_view_meta const * get_materialized_view_meta()
        const;

    data_type const * get_user_type() const;

    function_meta const * get_function_meta() const;

    aggregate_meta const * get_aggregate_meta() const;

    column_meta const * get_column_meta() const;

    index_meta const * get_index_meta() const;

    error get_meta_field_name(char const **name, size_t *name_length);

    value const * get_meta_field_value() const;
};

} // namespace cass

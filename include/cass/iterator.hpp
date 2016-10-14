/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/column_meta.hpp>
#include <cass/defs.hpp>
#include <cass/impexp.hpp>
#include <cass/wrapper_ptr.hpp>

namespace cass {

typedef wrapper_ptr<class iterator> iterator_ptr;

class iterator {
public:
    explicit iterator(::CassIterator *p) : p(p) {}
    ::CassIterator * backend() { return p; }

    inline static void free(iterator const i);

    CASSA_IMPEXP static iterator_ptr from_result(cass::result const *result);

    CASSA_IMPEXP static iterator_ptr from_row(cass::row const *row);

    CASSA_IMPEXP static iterator_ptr from_collection(cass::value const *value);

    CASSA_IMPEXP static iterator_ptr from_map(cass::value const *value);

    CASSA_IMPEXP static iterator_ptr from_tuple(cass::value const *value);

    CASSA_IMPEXP static iterator_ptr fields_from_user_type(
            cass::value const *value);

    CASSA_IMPEXP static iterator_ptr keyspaces_from_schema_meta(
            cass::schema_meta const *schema_meta);

    CASSA_IMPEXP static iterator_ptr tables_from_keyspace_meta(
            cass::keyspace_meta const *keyspace_meta);

    CASSA_IMPEXP static iterator_ptr materialized_views_from_keyspace_meta(
            cass::keyspace_meta const *keyspace_meta);

    CASSA_IMPEXP static iterator_ptr user_types_from_keyspace_meta(
            cass::keyspace_meta const *keyspace_meta);

    CASSA_IMPEXP static iterator_ptr functions_from_keyspace_meta(
            cass::keyspace_meta const *keyspace_meta);

    CASSA_IMPEXP static iterator_ptr aggregates_from_keyspace_meta(
            cass::keyspace_meta const *keyspace_meta);

    CASSA_IMPEXP static iterator_ptr fields_from_keyspace_meta(
            cass::keyspace_meta const *keyspace_meta);

    CASSA_IMPEXP static iterator_ptr columns_from_table_meta(
            cass::table_meta const *table_meta);

    CASSA_IMPEXP static iterator_ptr indexes_from_table_meta(
            cass::table_meta const *table_meta);

    CASSA_IMPEXP static iterator_ptr materialized_views_from_table_meta(
            cass::table_meta const *table_meta);

    CASSA_IMPEXP static iterator_ptr fields_from_table_meta(
            cass::table_meta const *table_meta);

    CASSA_IMPEXP static iterator_ptr columns_from_materialized_view_meta(
            materialized_view_meta const *view_meta);

    CASSA_IMPEXP static iterator_ptr fields_from_materialized_view_meta(
            materialized_view_meta const *view_meta);

    CASSA_IMPEXP static iterator_ptr fields_from_column_meta(
            cass::column_meta const *column_meta);

    CASSA_IMPEXP static iterator_ptr fields_from_index_meta(
            cass::index_meta const *index_meta);

    CASSA_IMPEXP static iterator_ptr fields_from_function_meta(
            cass::function_meta const *function_meta);

    CASSA_IMPEXP static iterator_ptr fields_from_aggregate_meta(
            cass::aggregate_meta const *aggregate_meta);

    inline iterator_type type();

    inline bool next();

    CASSA_IMPEXP row_const_ptr get_row() const;

    CASSA_IMPEXP value_const_ptr get_column() const;

    CASSA_IMPEXP value_const_ptr get_value() const;

    CASSA_IMPEXP value_const_ptr get_map_key() const;

    CASSA_IMPEXP value_const_ptr get_map_value() const;

    inline error get_user_type_field_name(char const **name,
            size_t *name_length);

    CASSA_IMPEXP value_const_ptr get_user_type_field_value();

    CASSA_IMPEXP keyspace_meta_const_ptr get_keyspace_meta() const;

    CASSA_IMPEXP table_meta_const_ptr get_table_meta() const;

    CASSA_IMPEXP materialized_view_meta_const_ptr get_materialized_view_meta()
        const;

    CASSA_IMPEXP data_type_const_ptr get_user_type() const;

    CASSA_IMPEXP function_meta_const_ptr get_function_meta() const;

    CASSA_IMPEXP aggregate_meta_const_ptr get_aggregate_meta() const;

    CASSA_IMPEXP column_meta_const_ptr get_column_meta() const;

    CASSA_IMPEXP index_meta_const_ptr get_index_meta() const;

    inline error get_meta_field_name(char const **name, size_t *name_length);

    CASSA_IMPEXP value_const_ptr get_meta_field_value() const;

private:
    ::CassIterator *p;
};

inline void iterator::free(iterator const i)
{
    ::cass_iterator_free(i.p);
}

inline iterator_type iterator::type()
{
    return ::cass_iterator_type(p);
}

inline bool iterator::next()
{
    return ::cass_iterator_next(p) == cass_true;
}

inline error iterator::get_user_type_field_name(char const **name,
        size_t *name_length)
{
    return (error)::cass_iterator_get_user_type_field_name(
            p, name, name_length);
}

inline error iterator::get_meta_field_name(char const **name,
        size_t *name_length)
{
    return (error)::cass_iterator_get_meta_field_name(p, name, name_length);
}

} // namespace cass

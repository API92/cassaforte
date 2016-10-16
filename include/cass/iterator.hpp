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

typedef wrapper_ptr<iterator> iterator_ptr;

class iterator : wrapper {
public:
    static iterator * ptr(::CassIterator *p)
    {
        return reinterpret_cast<iterator *>(p);
    }

    ::CassIterator * backend()
    {
        return reinterpret_cast<::CassIterator *>(this);
    }

    ::CassIterator const * backend() const
    {
        return reinterpret_cast<::CassIterator const *>(this);
    }

    inline void free();

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

    CASSA_IMPEXP row const * get_row() const;

    CASSA_IMPEXP value const * get_column() const;

    CASSA_IMPEXP value const * get_value() const;

    CASSA_IMPEXP value const * get_map_key() const;

    CASSA_IMPEXP value const * get_map_value() const;

    inline error get_user_type_field_name(char const **name,
            size_t *name_length);

    CASSA_IMPEXP value const * get_user_type_field_value();

    CASSA_IMPEXP keyspace_meta const * get_keyspace_meta() const;

    CASSA_IMPEXP table_meta const * get_table_meta() const;

    CASSA_IMPEXP materialized_view_meta const * get_materialized_view_meta()
        const;

    CASSA_IMPEXP data_type const * get_user_type() const;

    CASSA_IMPEXP function_meta const * get_function_meta() const;

    CASSA_IMPEXP aggregate_meta const * get_aggregate_meta() const;

    CASSA_IMPEXP column_meta const * get_column_meta() const;

    CASSA_IMPEXP index_meta const * get_index_meta() const;

    inline error get_meta_field_name(char const **name, size_t *name_length);

    CASSA_IMPEXP value const * get_meta_field_value() const;
};

inline void iterator::free()
{
    ::cass_iterator_free(backend());
}

inline iterator_type iterator::type()
{
    return ::cass_iterator_type(backend());
}

inline bool iterator::next()
{
    return ::cass_iterator_next(backend()) == cass_true;
}

inline error iterator::get_user_type_field_name(char const **name,
        size_t *name_length)
{
    return (error)::cass_iterator_get_user_type_field_name(
            backend(), name, name_length);
}

inline error iterator::get_meta_field_name(char const **name,
        size_t *name_length)
{
    return (error)::cass_iterator_get_meta_field_name(
            backend(), name, name_length);
}

} // namespace cass

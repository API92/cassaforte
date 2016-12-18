/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/iterator.hpp>

#include <cassandra.h>

#include <cass/aggregate_meta.hpp>
#include <cass/column_meta.hpp>
#include <cass/data_type.hpp>
#include <cass/function_meta.hpp>
#include <cass/index_meta.hpp>
#include <cass/keyspace_meta.hpp>
#include <cass/materialized_view_meta.hpp>
#include <cass/result.hpp>
#include <cass/row.hpp>
#include <cass/schema_meta.hpp>
#include <cass/table_meta.hpp>
#include <cass/value.hpp>
#include <cass/wrapper_ptr_def.hpp>

namespace cass {

iterator * iterator::ptr(::CassIterator *p)
{
    return reinterpret_cast<iterator *>(p);
}

::CassIterator * iterator::backend()
{
    return reinterpret_cast<::CassIterator *>(this);
}

::CassIterator const * iterator::backend() const
{
    return reinterpret_cast<::CassIterator const *>(this);
}

iterator_ptr iterator::from_result(cass::result const *result)
{
    return iterator_ptr(iterator::ptr(::cass_iterator_from_result(
                    result->backend())), true);
}

iterator_ptr iterator::from_row(cass::row const *row)
{
    return iterator_ptr(ptr(::cass_iterator_from_row(row->backend())), true);
}

iterator_ptr iterator::from_collection(cass::value const *value)
{
    ::CassIterator *it = ::cass_iterator_from_collection(value->backend());
    return iterator_ptr(ptr(it), it != nullptr);
}

iterator_ptr iterator::from_map(cass::value const *value)
{
    ::CassIterator *it = ::cass_iterator_from_map(value->backend());
    return iterator_ptr(ptr(it), it != nullptr);
}

iterator_ptr iterator::from_tuple(cass::value const *value)
{
    ::CassIterator *it = ::cass_iterator_from_tuple(value->backend());
    return iterator_ptr(ptr(it), it != nullptr);
}

iterator_ptr iterator::fields_from_user_type(cass::value const *value)
{
    ::CassIterator *it = ::cass_iterator_fields_from_user_type(
            value->backend());
    return iterator_ptr(ptr(it), it != nullptr);
}

iterator_ptr iterator::keyspaces_from_schema_meta(
        cass::schema_meta const *schema_meta)
{
    return iterator_ptr(ptr(::cass_iterator_keyspaces_from_schema_meta(
                    schema_meta->backend())), true);
}

iterator_ptr iterator::tables_from_keyspace_meta(
        cass::keyspace_meta const *keyspace_meta)
{
    return iterator_ptr(ptr(::cass_iterator_tables_from_keyspace_meta(
                    keyspace_meta->backend())), true);
}

iterator_ptr iterator::materialized_views_from_keyspace_meta(
        cass::keyspace_meta const *keyspace_meta)
{
    return iterator_ptr(ptr(
                ::cass_iterator_materialized_views_from_keyspace_meta(
                    keyspace_meta->backend())), true);
}

iterator_ptr iterator::user_types_from_keyspace_meta(
        cass::keyspace_meta const *keyspace_meta)
{
    return iterator_ptr(ptr(::cass_iterator_user_types_from_keyspace_meta(
                    keyspace_meta->backend())), true);
}

iterator_ptr iterator::functions_from_keyspace_meta(
        cass::keyspace_meta const *keyspace_meta)
{
    return iterator_ptr(ptr(::cass_iterator_functions_from_keyspace_meta(
                    keyspace_meta->backend())), true);
}

iterator_ptr iterator::aggregates_from_keyspace_meta(
        cass::keyspace_meta const *keyspace_meta)
{
    return iterator_ptr(ptr(::cass_iterator_aggregates_from_keyspace_meta(
                    keyspace_meta->backend())), true);
}

iterator_ptr iterator::fields_from_keyspace_meta(
        cass::keyspace_meta const *keyspace_meta)
{
    return iterator_ptr(ptr(::cass_iterator_fields_from_keyspace_meta(
                    keyspace_meta->backend())), true);
}

iterator_ptr iterator::columns_from_table_meta(
        cass::table_meta const *table_meta)
{
    return iterator_ptr(ptr(::cass_iterator_columns_from_table_meta(
                    table_meta->backend())), true);
}

iterator_ptr iterator::indexes_from_table_meta(
        cass::table_meta const *table_meta)
{
    return iterator_ptr(ptr(::cass_iterator_indexes_from_table_meta(
                    table_meta->backend())), true);
}

iterator_ptr iterator::materialized_views_from_table_meta(
        cass::table_meta const *table_meta)
{
    return iterator_ptr(ptr(
                ::cass_iterator_materialized_views_from_table_meta(
                    table_meta->backend())), true);
}

iterator_ptr iterator::fields_from_table_meta(
        cass::table_meta const *table_meta)
{
    return iterator_ptr(ptr(::cass_iterator_fields_from_table_meta(
                table_meta->backend())), true);
}

iterator_ptr iterator::columns_from_materialized_view_meta(
        materialized_view_meta const *view_meta)
{
    return iterator_ptr(ptr(::cass_iterator_columns_from_materialized_view_meta(
                view_meta->backend())), true);
}

iterator_ptr iterator::fields_from_materialized_view_meta(
        materialized_view_meta const *view_meta)
{
    return iterator_ptr(ptr(::cass_iterator_fields_from_materialized_view_meta(
                view_meta->backend())), true);
}

iterator_ptr iterator::fields_from_column_meta(
        cass::column_meta const *column_meta)
{
    return iterator_ptr(ptr(::cass_iterator_fields_from_column_meta(
                    column_meta->backend())), true);
}

iterator_ptr iterator::fields_from_index_meta(
        cass::index_meta const *index_meta)
{
    return iterator_ptr(ptr(::cass_iterator_fields_from_index_meta(
                    index_meta->backend())), true);
}

iterator_ptr iterator::fields_from_function_meta(
        cass::function_meta const *function_meta)
{
    return iterator_ptr(ptr(::cass_iterator_fields_from_function_meta(
                    function_meta->backend())), true);
}

iterator_ptr iterator::fields_from_aggregate_meta(
        cass::aggregate_meta const *aggregate_meta)
{
    return iterator_ptr(ptr(::cass_iterator_fields_from_aggregate_meta(
                    aggregate_meta->backend())), true);
}

row const * iterator::get_row() const
{
    return row::ptr(::cass_iterator_get_row(backend()));
}

value const * iterator::get_column() const
{
    return value::ptr(::cass_iterator_get_column(backend()));
}

value const * iterator::get_value() const
{
    return value::ptr(::cass_iterator_get_value(backend()));
}

value const * iterator::get_map_key() const
{
    return value::ptr(::cass_iterator_get_map_key(backend()));
}

value const * iterator::get_map_value() const
{
    return value::ptr(::cass_iterator_get_map_value(backend()));
}

value const * iterator::get_user_type_field_value()
{
    return value::ptr(::cass_iterator_get_user_type_field_value(backend()));
}

keyspace_meta const * iterator::get_keyspace_meta() const
{
    return keyspace_meta::ptr(::cass_iterator_get_keyspace_meta(backend()));
}

table_meta const * iterator::get_table_meta() const
{
    return table_meta::ptr(::cass_iterator_get_table_meta(backend()));
}

materialized_view_meta const * iterator::get_materialized_view_meta() const
{
    return materialized_view_meta::ptr(
            ::cass_iterator_get_materialized_view_meta(backend()));
}

data_type const * iterator::get_user_type() const
{
    return data_type::ptr(::cass_iterator_get_user_type(backend()));
}

function_meta const * iterator::get_function_meta() const
{
    return function_meta::ptr(::cass_iterator_get_function_meta(backend()));
}

aggregate_meta const * iterator::get_aggregate_meta() const
{
    return aggregate_meta::ptr(::cass_iterator_get_aggregate_meta(backend()));
}

column_meta const * iterator::get_column_meta() const
{
    return column_meta::ptr(::cass_iterator_get_column_meta(backend()));
}

index_meta const * iterator::get_index_meta() const
{
    return index_meta::ptr(::cass_iterator_get_index_meta(backend()));
}

value const * iterator::get_meta_field_value() const
{
    return value::ptr(::cass_iterator_get_meta_field_value(backend()));
}

void iterator::free()
{
    ::cass_iterator_free(backend());
}

iterator_type iterator::type()
{
    return (iterator_type)::cass_iterator_type(backend());
}

bool iterator::next()
{
    return ::cass_iterator_next(backend()) == cass_true;
}

error iterator::get_user_type_field_name(char const **name,
        size_t *name_length)
{
    return (error)::cass_iterator_get_user_type_field_name(
            backend(), name, name_length);
}

error iterator::get_meta_field_name(char const **name,
        size_t *name_length)
{
    return (error)::cass_iterator_get_meta_field_name(
            backend(), name, name_length);
}

template class wrapper_ptr<iterator>;

} // namespace cass

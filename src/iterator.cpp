/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/iterator.hpp>

#include <cass/keyspace_meta.hpp>
#include <cass/materialized_view_meta.hpp>
#include <cass/result.hpp>
#include <cass/row.hpp>
#include <cass/schema_meta.hpp>
#include <cass/table_meta.hpp>
#include <cass/value.hpp>

namespace cass {

iterator_ptr iterator::from_result(cass::result const *result)
{
    return iterator_ptr(iterator(::cass_iterator_from_result(
                    result->backend())), true);
}

iterator_ptr iterator::from_row(cass::row const *row)
{
    return iterator_ptr(iterator(::cass_iterator_from_row(
                    row->backend())), true);
}

iterator_ptr iterator::from_collection(cass::value const *value)
{
    return iterator_ptr(iterator(::cass_iterator_from_collection(
                    value->backend())), true);
}

iterator_ptr iterator::from_map(cass::value const *value)
{
    return iterator_ptr(iterator(::cass_iterator_from_map(
                    value->backend())), true);
}

iterator_ptr iterator::from_tuple(cass::value const *value)
{
    return iterator_ptr(iterator(::cass_iterator_from_tuple(
                    value->backend())), true);
}

iterator_ptr iterator::fields_from_user_type(
        cass::value const *value)
{
    return iterator_ptr(iterator(::cass_iterator_fields_from_user_type(
                    value->backend())), true);
}

iterator_ptr iterator::keyspaces_from_schema_meta(
        cass::schema_meta const *schema_meta)
{
    return iterator_ptr(iterator(::cass_iterator_keyspaces_from_schema_meta(
                    schema_meta->backend())), true);
}

iterator_ptr iterator::tables_from_keyspace_meta(
        cass::keyspace_meta const *keyspace_meta)
{
    return iterator_ptr(iterator(::cass_iterator_tables_from_keyspace_meta(
                    keyspace_meta->backend())), true);
}

iterator_ptr iterator::materialized_views_from_keyspace_meta(
        cass::keyspace_meta const *keyspace_meta)
{
    return iterator_ptr(iterator(
                ::cass_iterator_materialized_views_from_keyspace_meta(
                    keyspace_meta->backend())), true);
}

iterator_ptr iterator::user_types_from_keyspace_meta(
        cass::keyspace_meta const *keyspace_meta)
{
    return iterator_ptr(iterator(::cass_iterator_user_types_from_keyspace_meta(
                    keyspace_meta->backend())), true);
}

iterator_ptr iterator::functions_from_keyspace_meta(
        cass::keyspace_meta const *keyspace_meta)
{
    return iterator_ptr(iterator(::cass_iterator_functions_from_keyspace_meta(
                    keyspace_meta->backend())), true);
}

iterator_ptr iterator::aggregates_from_keyspace_meta(
        cass::keyspace_meta const *keyspace_meta)
{
    return iterator_ptr(iterator(::cass_iterator_aggregates_from_keyspace_meta(
                    keyspace_meta->backend())), true);
}

iterator_ptr iterator::fields_from_keyspace_meta(
        cass::keyspace_meta const *keyspace_meta)
{
    return iterator_ptr(iterator(::cass_iterator_fields_from_keyspace_meta(
                    keyspace_meta->backend())), true);
}

iterator_ptr iterator::columns_from_table_meta(
        cass::table_meta const *table_meta)
{
    return iterator_ptr(iterator(::cass_iterator_columns_from_table_meta(
                    table_meta->backend())), true);
}

iterator_ptr iterator::indexes_from_table_meta(
        cass::table_meta const *table_meta)
{
    return iterator_ptr(iterator(::cass_iterator_indexes_from_table_meta(
                    table_meta->backend())), true);
}

iterator_ptr iterator::materialized_views_from_table_meta(
        cass::table_meta const *table_meta)
{
    return iterator_ptr(iterator(
                ::cass_iterator_materialized_views_from_table_meta(
                    table_meta->backend())), true);
}

iterator_ptr iterator::fields_from_table_meta(
        cass::table_meta const *table_meta)
{
    return iterator_ptr(iterator(::cass_iterator_fields_from_table_meta(
                    table_meta->backend())), true);
}

iterator_ptr iterator::columns_from_materialized_view_meta(
        materialized_view_meta const *view_meta)
{
    return iterator_ptr(iterator(
                ::cass_iterator_columns_from_materialized_view_meta(
                    view_meta->backend())), true);
}

iterator_ptr iterator::fields_from_materialized_view_meta(
        materialized_view_meta const *view_meta)
{
    return iterator_ptr(iterator(
                ::cass_iterator_fields_from_materialized_view_meta(
                    view_meta->backend())), true);
}

iterator_ptr iterator::cass_iterator_fields_from_column_meta(
        cass::column_meta const *column_meta)
{
    return iterator_ptr(iterator(::cass_iterator_fields_from_column_meta(
                    column_meta->backend())), true);
}

} // namespace cass

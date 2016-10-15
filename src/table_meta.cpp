/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/table_meta.hpp>

#include <cass/column_meta.hpp>
#include <cass/index_meta.hpp>
#include <cass/materialized_view_meta.hpp>
#include <cass/value.hpp>

namespace cass {

column_meta const * table_meta::column_by_name(char const *column) const
{
    return column_meta::ptr(::cass_table_meta_column_by_name(
                backend(), column));
}

column_meta const * table_meta::column_by_name_n(
        char const *column, size_t column_length) const
{
    return column_meta::ptr(::cass_table_meta_column_by_name_n(
                backend(), column, column_length));
}

column_meta const * table_meta::column(size_t index) const
{
    return column_meta::ptr(::cass_table_meta_column(backend(), index));
}

index_meta const * table_meta::index_by_name(char const *index) const
{
    return index_meta::ptr(::cass_table_meta_index_by_name(
                backend(), index));
}

index_meta const * table_meta::index_by_name_n(char const *index,
        size_t index_length) const
{
    return index_meta::ptr(::cass_table_meta_index_by_name_n(
                backend(), index, index_length));
}

index_meta const * table_meta::index(size_t index) const
{
    return index_meta::ptr(::cass_table_meta_index(backend(), index));
}

materialized_view_meta const * table_meta::materialized_view_by_name(
        char const *view) const
{
    return materialized_view_meta::ptr(
            ::cass_table_meta_materialized_view_by_name(backend(), view));
}

materialized_view_meta const * table_meta::materialized_view_by_name_n(
        char const *view, size_t view_length) const
{
    return materialized_view_meta::ptr(
        ::cass_table_meta_materialized_view_by_name_n(
            backend(), view, view_length));
}

materialized_view_meta const * table_meta::materialized_view(
        size_t index) const
{
    return materialized_view_meta::ptr(
            ::cass_table_meta_materialized_view(backend(), index));
}

column_meta const * table_meta::partition_key(size_t index) const
{
    return column_meta::ptr(::cass_table_meta_partition_key(
                backend(), index));
}

column_meta const * table_meta::clustering_key(size_t index) const
{
    return column_meta::ptr(::cass_table_meta_clustering_key(
                backend(), index));
}

value const * table_meta::field_by_name(char const *name)
{
    return value::ptr(::cass_table_meta_field_by_name(backend(), name));
}

value const * table_meta::field_by_name_n(char const *name,
        size_t name_length)
{
    return value::ptr(::cass_table_meta_field_by_name_n(
                backend(), name, name_length));
}

} // namespace cass

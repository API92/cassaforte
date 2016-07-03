/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/materialized_view_meta.hpp>

#include <cass/column_meta.hpp>
#include <cass/table_meta.hpp>
#include <cass/value.hpp>

namespace cass {

column_meta_const_ptr materialized_view_meta::column_by_name(
        char const *column) const
{
    return column_meta_const_ptr(::cass_materialized_view_meta_column_by_name(
                p, column));
}

column_meta_const_ptr materialized_view_meta::column_by_name_n(
        char const *column, size_t column_length) const
{
    return column_meta_const_ptr(::cass_materialized_view_meta_column_by_name_n(
                p, column, column_length));
}

table_meta_const_ptr materialized_view_meta::base_table() const
{
    return table_meta_const_ptr(::cass_materialized_view_meta_base_table(p));
}

column_meta_const_ptr materialized_view_meta::column(size_t index) const
{
    return column_meta_const_ptr(::cass_materialized_view_meta_column(
                p, index));
}

column_meta_const_ptr materialized_view_meta::partition_key(size_t index) const
{
    return column_meta_const_ptr(::cass_materialized_view_meta_partition_key(
                p, index));
}

column_meta_const_ptr materialized_view_meta::clustering_key(size_t index) const
{
    return column_meta_const_ptr(::cass_materialized_view_meta_clustering_key(
                p, index));
}

value_const_ptr materialized_view_meta::field_by_name(char const *name) const
{
    return value_const_ptr(::cass_materialized_view_meta_field_by_name(
                p, name));
}

value_const_ptr materialized_view_meta::field_by_name_n(
        char const *name, size_t name_length) const
{
    return value_const_ptr(::cass_materialized_view_meta_field_by_name_n(
                p, name, name_length));
}

} // namespace cass

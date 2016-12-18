/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/materialized_view_meta.hpp>

#include <cassandra.h>

#include <cass/column_meta.hpp>
#include <cass/table_meta.hpp>
#include <cass/value.hpp>

namespace cass {

materialized_view_meta const * materialized_view_meta::ptr(
        ::CassMaterializedViewMeta const *p)
{
    return reinterpret_cast<materialized_view_meta const *>(p);
}

::CassMaterializedViewMeta const * materialized_view_meta::backend() const
{
    return reinterpret_cast<::CassMaterializedViewMeta const *>(this);
}

void materialized_view_meta::name(
        char const **name, size_t *name_length) const
{
    ::cass_materialized_view_meta_name(backend(), name, name_length);
}

size_t materialized_view_meta::column_count() const
{
    return ::cass_materialized_view_meta_column_count(backend());
}

size_t materialized_view_meta::partition_key_count() const
{
    return ::cass_materialized_view_meta_partition_key_count(backend());
}

size_t materialized_view_meta::clustering_key_count() const
{
    return ::cass_materialized_view_meta_clustering_key_count(backend());
}

clustering_order materialized_view_meta::clustering_key_order(
        size_t index) const
{
    return (clustering_order)::cass_materialized_view_meta_clustering_key_order(
            backend(), index);
}

column_meta const * materialized_view_meta::column_by_name(
        char const *column) const
{
    return column_meta::ptr(::cass_materialized_view_meta_column_by_name(
                backend(), column));
}

column_meta const * materialized_view_meta::column_by_name_n(
        char const *column, size_t column_length) const
{
    return column_meta::ptr(::cass_materialized_view_meta_column_by_name_n(
                backend(), column, column_length));
}

table_meta const * materialized_view_meta::base_table() const
{
    return table_meta::ptr(::cass_materialized_view_meta_base_table(backend()));
}

column_meta const * materialized_view_meta::column(size_t index) const
{
    return column_meta::ptr(::cass_materialized_view_meta_column(
                backend(), index));
}

column_meta const * materialized_view_meta::partition_key(size_t index) const
{
    return column_meta::ptr(::cass_materialized_view_meta_partition_key(
                backend(), index));
}

column_meta const * materialized_view_meta::clustering_key(size_t index) const
{
    return column_meta::ptr(::cass_materialized_view_meta_clustering_key(
                backend(), index));
}

value const * materialized_view_meta::field_by_name(char const *name) const
{
    return value::ptr(::cass_materialized_view_meta_field_by_name(
                backend(), name));
}

value const * materialized_view_meta::field_by_name_n(
        char const *name, size_t name_length) const
{
    return value::ptr(::cass_materialized_view_meta_field_by_name_n(
                backend(), name, name_length));
}

} // namespace cass

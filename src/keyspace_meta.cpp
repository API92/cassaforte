/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/keyspace_meta.hpp>
#include <cass/materialized_view_meta.hpp>
#include <cass/table_meta.hpp>

namespace cass {

table_meta_const_ptr keyspace_meta::table_by_name(
        char const *table) const
{
    return table_meta_const_ptr(::cass_keyspace_meta_table_by_name(p, table));
}

table_meta_const_ptr keyspace_meta::table_by_name_n(
        char const *table, size_t table_length) const
{
    return table_meta_const_ptr(::cass_keyspace_meta_table_by_name_n(p, table,
                table_length));
}

materialized_view_meta_const_ptr keyspace_meta::materialized_view_by_name(
        char const *view) const
{
    return materialized_view_meta_const_ptr(
            ::cass_keyspace_meta_materialized_view_by_name(p, view));
}

materialized_view_meta_const_ptr keyspace_meta::materialized_view_by_name_n(
        char const *view, size_t view_length) const
{
    return materialized_view_meta_const_ptr(
        ::cass_keyspace_meta_materialized_view_by_name_n(p, view, view_length));
}

} // namespace cass

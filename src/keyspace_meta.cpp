/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/aggregate_meta.hpp>
#include <cass/data_type.hpp>
#include <cass/function_meta.hpp>
#include <cass/keyspace_meta.hpp>
#include <cass/materialized_view_meta.hpp>
#include <cass/table_meta.hpp>
#include <cass/value.hpp>

namespace cass {

table_meta const * keyspace_meta::table_by_name(
        char const *table) const
{
    return table_meta::ptr(::cass_keyspace_meta_table_by_name(backend(), table));
}

table_meta const * keyspace_meta::table_by_name_n(
        char const *table, size_t table_length) const
{
    return table_meta::ptr(::cass_keyspace_meta_table_by_name_n(backend(), table,
                table_length));
}

materialized_view_meta const * keyspace_meta::materialized_view_by_name(
        char const *view) const
{
    return materialized_view_meta::ptr(
            ::cass_keyspace_meta_materialized_view_by_name(backend(), view));
}

materialized_view_meta const * keyspace_meta::materialized_view_by_name_n(
        char const *view, size_t view_length) const
{
    return materialized_view_meta::ptr(
        ::cass_keyspace_meta_materialized_view_by_name_n(backend(), view, view_length));
}

data_type const * keyspace_meta::user_type_by_name(char const *type) const
{
    return data_type::ptr(::cass_keyspace_meta_user_type_by_name(
                backend(), type));
}

function_meta const * keyspace_meta::function_by_name(char const *name,
        char const *arguments) const
{
    return function_meta::ptr(::cass_keyspace_meta_function_by_name(
                backend(), name, arguments));
}

function_meta const * keyspace_meta::function_by_name_n(
        char const *name, size_t name_length,
        char const *arguments, size_t arguments_length) const
{
    return function_meta::ptr(::cass_keyspace_meta_function_by_name_n(
                backend(), name, name_length, arguments, arguments_length));
}

aggregate_meta const * keyspace_meta::aggregate_by_name(char const *name,
        char const *arguments) const
{
    return aggregate_meta::ptr(::cass_keyspace_meta_aggregate_by_name(
                backend(), name, arguments));
}

aggregate_meta const * keyspace_meta::aggregate_by_name_n(
        char const *name, size_t name_length,
        char const *arguments, size_t arguments_length) const
{
    return aggregate_meta::ptr(::cass_keyspace_meta_aggregate_by_name_n(
                backend(), name, name_length, arguments, arguments_length));
}

value const * keyspace_meta::field_by_name(char const *name) const
{
    return value::ptr(::cass_keyspace_meta_field_by_name(backend(), name));
}

value const * keyspace_meta::field_by_name_n(char const *name,
        size_t name_length) const
{
    return value::ptr(::cass_keyspace_meta_field_by_name_n(
                backend(), name, name_length));
}

} // namespace cass

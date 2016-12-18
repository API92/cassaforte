/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/aggregate_meta.hpp>

#include <cassandra.h>

#include <cass/data_type.hpp>
#include <cass/function_meta.hpp>
#include <cass/value.hpp>

namespace cass {

aggregate_meta const * aggregate_meta::ptr(::CassAggregateMeta const *p)
{
    return reinterpret_cast<aggregate_meta const *>(p);
}

::CassAggregateMeta const * aggregate_meta::backend() const
{
    return reinterpret_cast<::CassAggregateMeta const *>(this);
}

data_type const * aggregate_meta::argument_type(size_t index) const
{
    return data_type::ptr(
                ::cass_aggregate_meta_argument_type(backend(), index));
}

data_type const * aggregate_meta::return_type() const
{
    return data_type::ptr(
                ::cass_aggregate_meta_return_type(backend()));
}

data_type const * aggregate_meta::state_type() const
{
    return data_type::ptr(
                ::cass_aggregate_meta_state_type(backend()));
}

function_meta const * aggregate_meta::state_func() const
{
    return function_meta::ptr(::cass_aggregate_meta_state_func(backend()));
}

function_meta const * aggregate_meta::final_func() const
{
    return function_meta::ptr(::cass_aggregate_meta_final_func(backend()));
}

value const * aggregate_meta::init_cond() const
{
    return value::ptr(::cass_aggregate_meta_init_cond(backend()));
}

value const * aggregate_meta::field_by_name(char const *name) const
{
    return value::ptr(::cass_aggregate_meta_field_by_name(backend(), name));
}

value const * aggregate_meta::field_by_name_n(char const *name,
        size_t name_length) const
{
    return value::ptr(::cass_aggregate_meta_field_by_name_n(
                backend(), name, name_length));
}

void aggregate_meta::name(char const **name, size_t *name_length) const
{
    ::cass_aggregate_meta_name(backend(), name, name_length);
}

void aggregate_meta::full_name(char const **full_name,
        size_t *full_name_length) const
{
    ::cass_aggregate_meta_full_name(backend(), full_name, full_name_length);
}

size_t aggregate_meta::argument_count() const
{
    return ::cass_aggregate_meta_argument_count(backend());
}

} // namespace cass

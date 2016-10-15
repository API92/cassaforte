/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/aggregate_meta.hpp>

#include <cass/data_type.hpp>
#include <cass/function_meta.hpp>
#include <cass/value.hpp>

namespace cass {

data_type_const_ptr aggregate_meta::argument_type(size_t index) const
{
    return data_type_const_ptr(data_type(::cass_aggregate_meta_argument_type(
                    backend(), index)), false);
}

data_type_const_ptr aggregate_meta::return_type() const
{
    return data_type_const_ptr(data_type(
                ::cass_aggregate_meta_return_type(backend())), false);
}

data_type_const_ptr aggregate_meta::state_type() const
{
    return data_type_const_ptr(data_type(
                ::cass_aggregate_meta_state_type(backend())), false);
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

} // namespace cass

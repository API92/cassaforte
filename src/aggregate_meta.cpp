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
                    p, index)), false);
}

data_type_const_ptr aggregate_meta::return_type() const
{
    return data_type_const_ptr(data_type(::cass_aggregate_meta_return_type(p)),
            false);
}

data_type_const_ptr aggregate_meta::state_type() const
{
    return data_type_const_ptr(data_type(::cass_aggregate_meta_state_type(p)),
            false);
}

function_meta_const_ptr aggregate_meta::state_func() const
{
    return function_meta_const_ptr(::cass_aggregate_meta_state_func(p));
}

function_meta_const_ptr aggregate_meta::final_func() const
{
    return function_meta_const_ptr(::cass_aggregate_meta_final_func(p));
}

value_const_ptr aggregate_meta::init_cond() const
{
    return value_const_ptr(::cass_aggregate_meta_init_cond(p));
}

value_const_ptr aggregate_meta::field_by_name(char const *name) const
{
    return value_const_ptr(::cass_aggregate_meta_field_by_name(p, name));
}

value_const_ptr aggregate_meta::field_by_name_n(char const *name,
        size_t name_length) const
{
    return value_const_ptr(::cass_aggregate_meta_field_by_name_n(
                p, name, name_length));
}

} // namespace cass

/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/function_meta.hpp>

#include <cass/data_type.hpp>
#include <cass/value.hpp>

namespace cass {

data_type const * function_meta::argument_type_by_name(
        char const *name) const
{
    return data_type::ptr(
                ::cass_function_meta_argument_type_by_name(backend(), name));
}

data_type const * function_meta::argument_type_by_name_n(
        char const *name, size_t name_length) const
{
    return data_type::ptr(::cass_function_meta_argument_type_by_name_n(
                backend(), name, name_length));
}

data_type const * function_meta::return_type() const
{
    return data_type::ptr(::cass_function_meta_return_type(backend()));
}

value const * function_meta::field_by_name(char const *name) const
{
    return value::ptr(
            ::cass_function_meta_field_by_name(backend(), name));
}

value const * function_meta::field_by_name_n(char const *name,
        size_t name_length) const
{
    return value::ptr(::cass_function_meta_field_by_name_n(backend(), name,
                name_length));
}

} // namespace cass

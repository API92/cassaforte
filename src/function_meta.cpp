/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/function_meta.hpp>

#include <cass/data_type.hpp>
#include <cass/value.hpp>

namespace cass {

error function_meta::argument(size_t index, char const **name,
        size_t *name_length, data_type_const_ptr *type) const
{
    ::CassDataType const *t = nullptr;
    error res = (error)::cass_function_meta_argument(
            backend(), index, name, name_length, &t);
    type->detach();
    type->get()->set_backend(t);
    return res;
}

data_type_const_ptr function_meta::argument_type_by_name(
        char const *name) const
{
    return data_type_const_ptr(data_type(
                ::cass_function_meta_argument_type_by_name(backend(), name)),
            false);
}

data_type_const_ptr function_meta::argument_type_by_name_n(
        char const *name, size_t name_length) const
{
    return data_type_const_ptr(data_type(
                ::cass_function_meta_argument_type_by_name_n(
                    backend(), name, name_length)), false);
}

data_type_const_ptr function_meta::return_type() const
{
    return data_type_const_ptr(data_type(
                ::cass_function_meta_return_type(backend())),
            false);
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

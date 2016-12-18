/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/function_meta.hpp>

#include <cassandra.h>

#include <cass/data_type.hpp>
#include <cass/value.hpp>

namespace cass {

function_meta const * function_meta::ptr(::CassFunctionMeta const *p)
{
    return reinterpret_cast<function_meta const *>(p);
}

::CassFunctionMeta const * function_meta::backend() const
{
    return reinterpret_cast<::CassFunctionMeta const *>(this);
}

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

void function_meta::name(char const **name, size_t *name_length) const
{
    ::cass_function_meta_name(backend(), name, name_length);
}

void function_meta::full_name(char const **full_name,
        size_t *full_name_length) const
{
    ::cass_function_meta_full_name(backend(), full_name, full_name_length);
}

void function_meta::body(char const **body, size_t *body_length) const
{
    ::cass_function_meta_body(backend(), body, body_length);
}

void function_meta::language(char const **language,
        size_t *language_length) const
{
    ::cass_function_meta_language(backend(), language, language_length);
}

bool function_meta::called_on_null_input() const
{
    return ::cass_function_meta_called_on_null_input(backend()) == cass_true;
}

size_t function_meta::argument_count() const
{
    return ::cass_function_meta_argument_count(backend());
}

error function_meta::argument(size_t index, char const **name,
        size_t *name_length, data_type const **type) const
{
    return error(::cass_function_meta_argument(
            backend(), index, name, name_length,
            reinterpret_cast<::CassDataType const **>(type)));
}

} // namespace cass

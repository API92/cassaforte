/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/value.hpp>

#include <cassandra.h>

#include <cass/custom.hpp>
#include <cass/data_type.hpp>
#include <cass/decimal.hpp>
#include <cass/inet.hpp>
#include <cass/uuid.hpp>

namespace cass {

value const * value::ptr(::CassValue const *p)
{
    return reinterpret_cast<value const *>(p);
}

::CassValue const * value::backend() const
{
    return reinterpret_cast<::CassValue const *>(this);
}

error value::get(int8_t *output) const
{
    return error(::cass_value_get_int8(backend(), output));
}

error value::get(int16_t *output) const
{
    return error(::cass_value_get_int16(backend(), output));
}

error value::get(int32_t *output) const
{
    return error(::cass_value_get_int32(backend(), output));
}

error value::get(uint32_t *output) const
{
    return error(::cass_value_get_uint32(backend(), output));
}

error value::get(int64_t *output) const
{
    return error(::cass_value_get_int64(backend(), output));
}

error value::get(float *output) const
{
    return error(::cass_value_get_float(backend(), output));
}

error value::get(double *output) const
{
    return error(::cass_value_get_double(backend(), output));
}

error value::get(bool *output) const
{
    cass_bool_t out;
    error res = error(::cass_value_get_bool(backend(), &out));
    *output = out == cass_true;
    return res;
}

error value::get(uuid *output) const
{
    return (error)::cass_value_get_uuid(backend(), output->backend());
}

error value::get(inet *output) const
{
    return error(::cass_value_get_inet(backend(), output->backend()));
}

error value::get(std::experimental::string_view *output) const
{
    char const *output_s = nullptr;
    size_t size = 0;
    ::CassError res = ::cass_value_get_string(backend(), &output_s, &size);
    if (res == ::CASS_OK)
        *output = std::experimental::string_view(output_s, size);
    return (error)res;
}

error value::get(bytes_view *output) const
{
    byte_t const *output_s = nullptr;
    size_t size = 0;
    ::CassError res = ::cass_value_get_bytes(backend(), &output_s, &size);
    if (res == ::CASS_OK)
        *output = bytes_view(output_s, size);
    return (error)res;
}

error value::get(decimal *output) const
{
    return error(::cass_value_get_decimal(
            backend(), &output->varint, &output->varint_size, &output->scale));
}

value_type value::type() const
{
    return (value_type)::cass_value_type(backend());
}

bool value::is_null() const
{
    return ::cass_value_is_null(backend()) == cass_true;
}

bool value::is_collection() const
{
    return ::cass_value_is_collection(backend()) == cass_true;
}

size_t value::item_count() const
{
    return ::cass_value_item_count(backend());
}

value_type value::primary_sub_type() const
{
    return (value_type)::cass_value_primary_sub_type(backend());
}

value_type value::secondary_sub_type() const
{
    return (value_type)::cass_value_secondary_sub_type(backend());
}

data_type const * value::data_type() const
{
    return cass::data_type::ptr(::cass_value_data_type(backend()));
}

} // namespace cass

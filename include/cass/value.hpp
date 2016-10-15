/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/defs.hpp>
#include <cass/impexp.hpp>
#include <cass/inet.hpp>
#include <cass/uuid.hpp>
#include <cass/wrapper_ptr.hpp>

namespace cass {

class value {
public:
    static value const * ptr(::CassValue const *p)
    {
        return reinterpret_cast<value const *>(p);
    }

    ::CassValue const * backend() const
    {
        return reinterpret_cast<::CassValue const *>(this);
    }

    CASSA_IMPEXP data_type_const_ptr data_type() const;

    inline error get_int8(int8_t *output) const;

    inline error get_int16(int16_t *output) const;

    inline error get_int32(int32_t *output) const;

    inline error get_uint32(uint32_t *output) const;

    inline error get_int64(int64_t *output) const;

    inline error get_float(float *output) const;

    inline error get_double(double *output) const;

    inline error get_bool(bool *output) const;

    inline error get_uuid(uuid *output) const;

    inline error get_inet(inet *output) const;

    inline error get_string(char const **output, size_t *output_size) const;

    inline error get_bytes(byte_t const **output, size_t *output_size) const;

    inline error get_decimal(byte_t const **varint, size_t *varint_size,
            int32_t *scale) const;

    inline value_type type() const;

    inline bool is_null() const;

    inline bool is_collection() const;

    inline size_t item_count() const;

    inline value_type primary_sub_type() const;

    inline value_type secondary_sub_type() const;
};

inline error value::get_int8(int8_t *output) const
{
    return error(::cass_value_get_int8(backend(), output));
}

inline error value::get_int16(int16_t *output) const
{
    return error(::cass_value_get_int16(backend(), output));
}

inline error value::get_int32(int32_t *output) const
{
    return error(::cass_value_get_int32(backend(), output));
}

inline error value::get_uint32(uint32_t *output) const
{
    return error(::cass_value_get_uint32(backend(), output));
}

inline error value::get_int64(int64_t *output) const
{
    return error(::cass_value_get_int64(backend(), output));
}

inline error value::get_float(float *output) const
{
    return error(::cass_value_get_float(backend(), output));
}

inline error value::get_double(double *output) const
{
    return error(::cass_value_get_double(backend(), output));
}

inline error value::get_bool(bool *output) const
{
    cass_bool_t out;
    error res = error(::cass_value_get_bool(backend(), &out));
    *output = out == cass_true;
    return res;
}

inline error value::get_uuid(uuid *output) const
{
    return error(::cass_value_get_uuid(backend(), output));
}

inline error value::get_inet(inet *output) const
{
    return error(::cass_value_get_inet(backend(), output));
}

inline error value::get_string(char const **output, size_t *output_size) const
{
    return error(::cass_value_get_string(backend(), output, output_size));
}

inline error value::get_bytes(byte_t const **output, size_t *output_size) const
{
    return error(::cass_value_get_bytes(backend(), output, output_size));
}

inline error value::get_decimal(byte_t const **varint, size_t *varint_size,
            int32_t *scale) const
{
    return error(::cass_value_get_decimal(backend(), varint, varint_size, scale));
}

inline value_type value::type() const
{
    return ::cass_value_type(backend());
}

inline bool value::is_null() const
{
    return ::cass_value_is_null(backend()) == cass_true;
}

inline bool value::is_collection() const
{
    return ::cass_value_is_collection(backend()) == cass_true;
}

inline size_t value::item_count() const
{
    return ::cass_value_item_count(backend());
}

inline value_type value::primary_sub_type() const
{
    return ::cass_value_primary_sub_type(backend());
}

inline value_type value::secondary_sub_type() const
{
    return ::cass_value_secondary_sub_type(backend());
}

} // namespace cass

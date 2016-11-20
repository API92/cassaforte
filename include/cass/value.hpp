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

class value : wrapper {
public:
    static value const * ptr(::CassValue const *p)
    {
        return reinterpret_cast<value const *>(p);
    }

    ::CassValue const * backend() const
    {
        return reinterpret_cast<::CassValue const *>(this);
    }

    CASSA_IMPEXP cass::data_type const * data_type() const;

    inline error get(int8_t *output) const;
    inline error get(int16_t *output) const;
    inline error get(int32_t *output) const;
    inline error get(uint32_t *output) const;
    inline error get(int64_t *output) const;
    inline error get(float *output) const;
    inline error get(double *output) const;
    inline error get(bool *output) const;
    inline error get(uuid *output) const;
    inline error get(inet *output) const;
    inline error get(std::experimental::string_view *output) const;
    inline error get(bytes_view *output) const;
    inline error get(decimal *output) const;

    inline value_type type() const;

    inline bool is_null() const;

    inline bool is_collection() const;

    inline size_t item_count() const;

    inline value_type primary_sub_type() const;

    inline value_type secondary_sub_type() const;
};

inline error value::get(int8_t *output) const
{
    return error(::cass_value_get_int8(backend(), output));
}

inline error value::get(int16_t *output) const
{
    return error(::cass_value_get_int16(backend(), output));
}

inline error value::get(int32_t *output) const
{
    return error(::cass_value_get_int32(backend(), output));
}

inline error value::get(uint32_t *output) const
{
    return error(::cass_value_get_uint32(backend(), output));
}

inline error value::get(int64_t *output) const
{
    return error(::cass_value_get_int64(backend(), output));
}

inline error value::get(float *output) const
{
    return error(::cass_value_get_float(backend(), output));
}

inline error value::get(double *output) const
{
    return error(::cass_value_get_double(backend(), output));
}

inline error value::get(bool *output) const
{
    cass_bool_t out;
    error res = error(::cass_value_get_bool(backend(), &out));
    *output = out == cass_true;
    return res;
}

inline error value::get(uuid *output) const
{
    return error(::cass_value_get_uuid(backend(), output));
}

inline error value::get(inet *output) const
{
    return error(::cass_value_get_inet(backend(), output));
}

inline error value::get(std::experimental::string_view *output) const
{
    char const *output_s = nullptr;
    size_t size = 0;
    error res = error(::cass_value_get_string(backend(), &output_s, &size));
    if (res == OK)
        *output = std::experimental::string_view(output_s, size);
    return res;
}

inline error value::get(bytes_view *output) const
{
    byte_t const *output_s = nullptr;
    size_t size = 0;
    error res = error(::cass_value_get_bytes(backend(), &output_s, &size));
    if (res == OK)
        *output = bytes_view(output_s, size);
    return res;
}

inline error value::get(decimal *output) const
{
    return error(::cass_value_get_decimal(
            backend(), &output->varint, &output->varint_size, &output->scale));
}

inline value_type value::type() const
{
    return (value_type)::cass_value_type(backend());
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
    return (value_type)::cass_value_primary_sub_type(backend());
}

inline value_type value::secondary_sub_type() const
{
    return (value_type)::cass_value_secondary_sub_type(backend());
}

} // namespace cass

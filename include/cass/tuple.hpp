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

typedef wrapper_ptr<tuple> tuple_ptr;

class tuple : wrapper {
public:
    static tuple * ptr(::CassTuple *p)
    {
        return reinterpret_cast<tuple *>(p);
    }

    ::CassTuple * backend()
    {
        return reinterpret_cast<::CassTuple *>(this);
    }

    ::CassTuple const * backend() const
    {
        return reinterpret_cast<::CassTuple const *>(this);
    }

    inline void free();
    inline static tuple_ptr new_ptr(size_t item_count);

    CASSA_IMPEXP static tuple_ptr new_from_data_type(
            cass::data_type const *data_type);

    CASSA_IMPEXP cass::data_type const * data_type() const;

    inline error set(size_t index, std::nullptr_t);
    inline error set(size_t index, int8_t value);
    inline error set(size_t index, int16_t value);
    inline error set(size_t index, int32_t value);
    inline error set(size_t index, uint32_t value);
    inline error set(size_t index, int64_t value);
    inline error set(size_t index, float value);
    inline error set(size_t index, double value);
    inline error set(size_t index, bool value);
    inline error set(size_t index, char const *value);
    inline error set(size_t index, std::experimental::string_view value);
    inline error set(size_t index, bytes_view value);
    inline error set(size_t index, custom c);
    inline error set(size_t index, uuid value);
    inline error set(size_t index, inet value);
    inline error set(size_t index, decimal d);
    inline error set(size_t index, tuple const *value);
    CASSA_IMPEXP error set(size_t index, collection const *value);
    CASSA_IMPEXP error set(size_t index, user_type const *value);

    inline error set_custom(size_t index, char const *class_name,
            byte_t const *value, size_t value_size);
};

inline void tuple::free()
{
    ::cass_tuple_free(backend());
}

inline tuple_ptr tuple::new_ptr(size_t item_count)
{
    return tuple_ptr(tuple::ptr(::cass_tuple_new(item_count)), true);
}

inline error tuple::set(size_t index, std::nullptr_t)
{
    return error(::cass_tuple_set_null(backend(), index));
}

inline error tuple::set(size_t index, int8_t value)
{
    return error(::cass_tuple_set_int8(backend(), index, value));
}

inline error tuple::set(size_t index, int16_t value)
{
    return error(::cass_tuple_set_int16(backend(), index, value));
}

inline error tuple::set(size_t index, int32_t value)
{
    return error(::cass_tuple_set_int32(backend(), index, value));
}

inline error tuple::set(size_t index, uint32_t value)
{
    return error(::cass_tuple_set_uint32(backend(), index, value));
}

inline error tuple::set(size_t index, int64_t value)
{
    return error(::cass_tuple_set_int64(backend(), index, value));
}

inline error tuple::set(size_t index, float value)
{
    return error(::cass_tuple_set_float(backend(), index, value));
}

inline error tuple::set(size_t index, double value)
{
    return error(::cass_tuple_set_double(backend(), index, value));
}

inline error tuple::set(size_t index, bool value)
{
    return error(::cass_tuple_set_bool(
                backend(), index, value ? cass_true : cass_false));
}

inline error tuple::set(size_t index, char const *value)
{
    return error(::cass_tuple_set_string(backend(), index, value));
}

inline error tuple::set(size_t index, std::experimental::string_view value)
{
    return error(::cass_tuple_set_string_n(
                backend(), index, value.data(), value.size()));
}

inline error tuple::set(size_t index, bytes_view value)
{
    return error(::cass_tuple_set_bytes(
                backend(), index, value.data(), value.size()));
}

inline error tuple::set_custom(size_t index, char const *class_name,
        byte_t const *value, size_t value_size)
{
    return error(::cass_tuple_set_custom(
                backend(), index, class_name, value, value_size));
}

inline error tuple::set(size_t index, custom c)
{
    return error(::cass_tuple_set_custom_n(
                backend(), index, c.class_name.data(), c.class_name.size(),
                c.value.data(), c.value.size()));
}

inline error tuple::set(size_t index, uuid value)
{
    return error(::cass_tuple_set_uuid(backend(), index, value));
}

inline error tuple::set(size_t index, inet value)
{
    return error(::cass_tuple_set_inet(backend(), index, value));
}

inline error tuple::set(size_t index, decimal d)
{
    return error(::cass_tuple_set_decimal(
                backend(), index, d.varint, d.varint_size, d.scale));
}

inline error tuple::set(size_t index, tuple const *value)
{
    return error(::cass_tuple_set_tuple(backend(), index, value->backend()));
}

} // namespace cass

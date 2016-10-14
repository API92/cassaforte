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

typedef wrapper_ptr<class tuple> tuple_ptr;

class tuple {
public:
    explicit tuple(::CassTuple *p) : p(p) {}
    ::CassTuple * backend() { return p; }
    ::CassTuple const * backend() const { return p; }

    inline static void free(tuple const t);
    inline static tuple_ptr new_ptr(size_t item_count);

    CASSA_IMPEXP static tuple_ptr new_from_data_type(
            cass::data_type const *data_type);

    CASSA_IMPEXP data_type_const_ptr data_type() const;

    inline error set_null(size_t index);

    inline error set_int8(size_t index, int8_t value);

    inline error set_int16(size_t index, int16_t value);

    inline error set_int32(size_t index, int32_t value);

    inline error set_uint32(size_t index, uint32_t value);

    inline error set_int64(size_t index, int64_t value);

    inline error set_float(size_t index, float value);

    inline error set_double(size_t index, double value);

    inline error set_bool(size_t index, bool value);

    inline error set_string(size_t index, char const *value);
    inline error set_string_n(size_t index, char const *value,
            size_t value_length);

    inline error set_bytes(size_t index, byte_t const *value,
            size_t value_size);

    inline error set_custom(size_t index, char const *class_name,
            byte_t const *value, size_t value_size);
    inline error set_custom_n(size_t index, char const *class_name,
            size_t class_name_length, byte_t const *value, size_t value_size);

    inline error set_uuid(size_t index, uuid value);

    inline error set_inet(size_t index, inet value);

    inline error set_decimal(size_t index, byte_t const *varint,
            size_t varint_size, int32_t scale);

    CASSA_IMPEXP error set_collection(size_t index, collection const *value);

    inline error set_tuple(size_t index, tuple const *value);

    CASSA_IMPEXP error set_user_type(size_t index, user_type const *value);

private:
    ::CassTuple *p;
};

inline void tuple::free(tuple const t)
{
    ::cass_tuple_free(t.p);
}

inline tuple_ptr tuple::new_ptr(size_t item_count)
{
    return tuple_ptr(tuple(::cass_tuple_new(item_count)), true);
}

inline error tuple::set_null(size_t index)
{
    return error(::cass_tuple_set_null(p, index));
}

inline error tuple::set_int8(size_t index, int8_t value)
{
    return error(::cass_tuple_set_int8(p, index, value));
}

inline error tuple::set_int16(size_t index, int16_t value)
{
    return error(::cass_tuple_set_int16(p, index, value));
}

inline error tuple::set_int32(size_t index, int32_t value)
{
    return error(::cass_tuple_set_int32(p, index, value));
}

inline error tuple::set_uint32(size_t index, uint32_t value)
{
    return error(::cass_tuple_set_uint32(p, index, value));
}

inline error tuple::set_int64(size_t index, int64_t value)
{
    return error(::cass_tuple_set_int64(p, index, value));
}

inline error tuple::set_float(size_t index, float value)
{
    return error(::cass_tuple_set_float(p, index, value));
}

inline error tuple::set_double(size_t index, double value)
{
    return error(::cass_tuple_set_double(p, index, value));
}

inline error tuple::set_bool(size_t index, bool value)
{
    return error(::cass_tuple_set_bool(
                p, index, value ? cass_true : cass_false));
}

inline error tuple::set_string(size_t index, char const *value)
{
    return error(::cass_tuple_set_string(p, index, value));
}

inline error tuple::set_string_n(size_t index, char const *value,
        size_t value_length)
{
    return error(::cass_tuple_set_string_n(p, index, value, value_length));
}

inline error tuple::set_bytes(size_t index, byte_t const *value,
        size_t value_size)
{
    return error(::cass_tuple_set_bytes(p, index, value, value_size));
}

inline error tuple::set_custom(size_t index, char const *class_name,
        byte_t const *value, size_t value_size)
{
    return error(::cass_tuple_set_custom(
                p, index, class_name, value, value_size));
}

inline error tuple::set_custom_n(size_t index, char const *class_name,
        size_t class_name_length, byte_t const *value, size_t value_size)
{
    return error(::cass_tuple_set_custom_n(
                p, index, class_name, class_name_length, value, value_size));
}

inline error tuple::set_uuid(size_t index, uuid value)
{
    return error(::cass_tuple_set_uuid(p, index, value));
}

inline error tuple::set_inet(size_t index, inet value)
{
    return error(::cass_tuple_set_inet(p, index, value));
}

inline error tuple::set_decimal(size_t index, byte_t const *varint,
        size_t varint_size, int32_t scale)
{
    return error(::cass_tuple_set_decimal(
                p, index, varint, varint_size, scale));
}

inline error tuple::set_tuple(size_t index, tuple const *value)
{
    return error(::cass_tuple_set_tuple(p, index, value->backend()));
}

} // namespace cass

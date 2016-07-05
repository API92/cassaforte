/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/defs.hpp>
#include <cass/impexp.hpp>
#include <cass/wrapper_ptr.hpp>

namespace cass {

typedef wrapper_ptr<class user_type> user_type_ptr;

class user_type {
public:
    explicit user_type(::CassUserType *p) : p(p) {}
    ::CassUserType * backend() { return p; }
    ::CassUserType const * backend() const { return p; }

    inline static void free(user_type const u);

    CASSA_IMPEXP user_type_ptr new_from_data_type(
            cass::data_type const *data_type);

    CASSA_IMPEXP data_type_const_ptr data_type() const;

    inline error set_null(size_t index);
    inline error set_null_by_name(char const *name);
    inline error set_null_by_name_n(char const *name, size_t name_length);

    inline error set_int8(size_t index, int8_t value);
    inline error set_int8_by_name(char const *name, int8_t value);
    inline error set_int8_by_name_n(char const *name, size_t name_length,
            int8_t value);

    inline error set_int16(size_t index, int16_t value);
    inline error set_int16_by_name(char const *name, int16_t value);
    inline error set_int16_by_name_n(char const *name, size_t name_length,
            int16_t value);

    inline error set_int32(size_t index, int32_t value);
    inline error set_int32_by_name(char const *name, int32_t value);
    inline error set_int32_by_name_n(char const *name, size_t name_length,
            int32_t value);

    inline error set_uint32(size_t index, uint32_t value);
    inline error set_uint32_by_name(char const *name, uint32_t value);
    inline error set_uint32_by_name_n(char const *name, size_t name_length,
            uint32_t value);

    inline error set_int64(size_t index, int64_t value);
    inline error set_int64_by_name(char const *name, int64_t value);
    inline error set_int64_by_name_n(char const *name, size_t name_length,
            int64_t value);

    inline error set_float(size_t index, float value);
    inline error set_float_by_name(char const *name, float value);
    inline error set_float_by_name_n(char const *name, size_t name_length,
            float value);

    inline error set_double(size_t index, double value);
    inline error set_double_by_name(char const *name, double value);
    inline error set_double_by_name_n(char const *name, size_t name_length,
            double value);

    inline error set_bool(size_t index, bool value);
    inline error set_bool_by_name(char const *name, bool value);
    inline error set_bool_by_name_n(char const *name, size_t name_length,
            bool value);

    inline error set_string(size_t index, char const *value);
    inline error set_string_n(size_t index, char const *value,
            size_t value_length);
    inline error set_string_by_name(char const *name, char const *value);
    inline error set_string_by_name_n(char const *name, size_t name_length,
            char const *value, size_t value_length);

    inline error set_bytes(size_t index, byte_t const *value,
            size_t value_size);
    inline error set_bytes_by_name(char const *name, byte_t const *value,
            size_t value_size);
    inline error set_bytes_by_name_n(char const *name, size_t name_length,
            byte_t const *value, size_t value_size);

    inline error set_custom(size_t index, char const *class_name,
            byte_t const *value, size_t value_size);
    inline error set_custom_n(size_t index, char const *class_name,
            size_t class_name_length, byte_t const *value, size_t value_size);
    inline error set_custom_by_name(char const *name, char const *class_name,
            byte_t const *value, size_t value_size);
    inline error set_custom_by_name_n(char const *name, size_t name_length,
            char const *class_name, size_t class_name_length,
            byte_t const *value, size_t value_size);

    inline error set_uuid(size_t index, uuid value);
    inline error set_uuid_by_name(char const *name, uuid value);
    inline error set_uuid_by_name_n(char const *name, size_t name_length,
            uuid value);

    inline error set_inet(size_t index, inet value);
    inline error set_inet_by_name(char const *name, inet value);
    inline error set_inet_by_name_n(char const *name, size_t name_length,
            inet value);

    inline error set_decimal(size_t index, byte_t const *varint,
            size_t varint_size, int scale);
    inline error set_decimal_by_name(char const *name, byte_t const *varint,
            size_t varint_size, int scale);
    inline error set_decimal_by_name_n(char const *name, size_t name_length,
            byte_t const *varint, size_t varint_size, int scale);

    CASSA_IMPEXP error set_collection(size_t index, collection const *value);
    CASSA_IMPEXP error set_collection_by_name(char const *name,
            collection const *value);
    CASSA_IMPEXP error set_collection_by_name_n(char const *name,
            size_t name_length, collection const *value);

    CASSA_IMPEXP error set_tuple(size_t index, tuple const *value);
    CASSA_IMPEXP error set_tuple_by_name(char const *name, tuple const *value);
    CASSA_IMPEXP error set_tuple_by_name_n(char const *name, size_t name_length,
            tuple const *value);

    inline error set_user_type(size_t index, user_type const *value);
    inline error set_user_type_by_name(char const *name,
            user_type const *value);
    inline error set_user_type_by_name_n(char const *name, size_t name_length,
            user_type const *value);

private:
    ::CassUserType *p;
};

inline void user_type::free(user_type const u)
{
    ::cass_user_type_free(u.p);
}

inline error user_type::set_null(size_t index)
{
    return ::cass_user_type_set_null(p, index);
}

inline error user_type::set_null_by_name(char const *name)
{
    return ::cass_user_type_set_null_by_name(p, name);
}

inline error user_type::set_null_by_name_n(char const *name, size_t name_length)
{
    return ::cass_user_type_set_null_by_name_n(p, name, name_length);
}

inline error user_type::set_int8(size_t index, int8_t value)
{
    return ::cass_user_type_set_int8(p, index, value);
}

inline error user_type::set_int8_by_name(char const *name, int8_t value)
{
    return ::cass_user_type_set_int8_by_name(p, name, value);
}

inline error user_type::set_int8_by_name_n(char const *name, size_t name_length,
        int8_t value)
{
    return ::cass_user_type_set_int8_by_name_n(p, name, name_length, value);
}

inline error user_type::set_int16(size_t index, int16_t value)
{
    return ::cass_user_type_set_int16(p, index, value);
}

inline error user_type::set_int16_by_name(char const *name, int16_t value)
{
    return ::cass_user_type_set_int16_by_name(p, name, value);
}

inline error user_type::set_int16_by_name_n(char const *name,
        size_t name_length, int16_t value)
{
    return ::cass_user_type_set_int16_by_name_n(p, name, name_length, value);
}

inline error user_type::set_int32(size_t index, int32_t value)
{
    return ::cass_user_type_set_int32(p, index, value);
}

inline error user_type::set_int32_by_name(char const *name, int32_t value)
{
    return ::cass_user_type_set_int32_by_name(p, name, value);
}

inline error user_type::set_int32_by_name_n(char const *name,
        size_t name_length, int32_t value)
{
    return ::cass_user_type_set_int32_by_name_n(p, name, name_length, value);
}

inline error user_type::set_uint32(size_t index, uint32_t value)
{
    return ::cass_user_type_set_uint32(p, index, value);
}

inline error user_type::set_uint32_by_name(char const *name, uint32_t value)
{
    return ::cass_user_type_set_uint32_by_name(p, name, value);
}

inline error user_type::set_uint32_by_name_n(char const *name,
        size_t name_length, uint32_t value)
{
    return ::cass_user_type_set_uint32_by_name_n(p, name, name_length, value);
}

inline error user_type::set_int64(size_t index, int64_t value)
{
    return ::cass_user_type_set_int64(p, index, value);
}

inline error user_type::set_int64_by_name(char const *name, int64_t value)
{
    return ::cass_user_type_set_int64_by_name(p, name, value);
}

inline error user_type::set_int64_by_name_n(char const *name,
        size_t name_length, int64_t value)
{
    return ::cass_user_type_set_int64_by_name_n(p, name, name_length, value);
}

inline error user_type::set_float(size_t index, float value)
{
    return ::cass_user_type_set_float(p, index, value);
}

inline error user_type::set_float_by_name(char const *name, float value)
{
    return ::cass_user_type_set_float_by_name(p, name, value);
}

inline error user_type::set_float_by_name_n(char const *name, size_t name_length,
        float value)
{
    return ::cass_user_type_set_float_by_name_n(p, name, name_length, value);
}

inline error user_type::set_double(size_t index, double value)
{
    return ::cass_user_type_set_double(p, index, value);
}

inline error user_type::set_double_by_name(char const *name, double value)
{
    return ::cass_user_type_set_double_by_name(p, name, value);
}

inline error user_type::set_double_by_name_n(char const *name,
        size_t name_length, double value)
{
    return ::cass_user_type_set_double_by_name_n(p, name, name_length, value);
}

inline error user_type::set_bool(size_t index, bool value)
{
    return ::cass_user_type_set_bool(p, index, value ? cass_true : cass_false);
}

inline error user_type::set_bool_by_name(char const *name, bool value)
{
    return ::cass_user_type_set_bool_by_name(p, name,
            value ? cass_true : cass_false);
}

inline error user_type::set_bool_by_name_n(char const *name, size_t name_length,
        bool value)
{
    return ::cass_user_type_set_bool_by_name_n(p, name, name_length,
            value ? cass_true : cass_false);
}

inline error user_type::set_string(size_t index, char const *value)
{
    return ::cass_user_type_set_string(p, index, value);
}

inline error user_type::set_string_n(size_t index, char const *value,
        size_t value_length)
{
    return ::cass_user_type_set_string_n(p, index, value, value_length);
}

inline error user_type::set_string_by_name(char const *name, char const *value)
{
    return ::cass_user_type_set_string_by_name(p, name, value);
}

inline error user_type::set_string_by_name_n(char const *name,
        size_t name_length, char const *value, size_t value_length)
{
    return ::cass_user_type_set_string_by_name_n(p, name, name_length, value,
            value_length);
}

inline error user_type::set_bytes(size_t index, byte_t const *value,
        size_t value_size)
{
    return ::cass_user_type_set_bytes(p, index, value, value_size);
}

inline error user_type::set_bytes_by_name(char const *name, byte_t const *value,
        size_t value_size)
{
    return ::cass_user_type_set_bytes_by_name(p, name, value, value_size);
}

inline error user_type::set_bytes_by_name_n(char const *name,
        size_t name_length, byte_t const *value, size_t value_size)
{
    return ::cass_user_type_set_bytes_by_name_n(p, name, name_length,
            value, value_size);
}

inline error user_type::set_custom(size_t index, char const *class_name,
        byte_t const *value, size_t value_size)
{
    return ::cass_user_type_set_custom(p, index, class_name, value, value_size);
}

inline error user_type::set_custom_n(size_t index, char const *class_name,
        size_t class_name_length, byte_t const *value, size_t value_size)
{
    return ::cass_user_type_set_custom_n(p, index, class_name,
            class_name_length, value, value_size);
}

inline error user_type::set_custom_by_name(char const *name,
        char const *class_name, byte_t const *value, size_t value_size)
{
    return ::cass_user_type_set_custom_by_name(p, name, class_name, value,
            value_size);
}

inline error user_type::set_custom_by_name_n(char const *name,
        size_t name_length, char const *class_name, size_t class_name_length,
        byte_t const *value, size_t value_size)
{
    return ::cass_user_type_set_custom_by_name_n(p, name, name_length,
            class_name, class_name_length, value, value_size);
}

inline error user_type::set_uuid(size_t index, uuid value)
{
    return ::cass_user_type_set_uuid(p, index, value);
}

inline error user_type::set_uuid_by_name(char const *name, uuid value)
{
    return ::cass_user_type_set_uuid_by_name(p, name, value);
}

inline error user_type::set_uuid_by_name_n(char const *name, size_t name_length,
        uuid value)
{
    return ::cass_user_type_set_uuid_by_name_n(p, name, name_length, value);
}

inline error user_type::set_inet(size_t index, inet value)
{
    return ::cass_user_type_set_inet(p, index, value);
}

inline error user_type::set_inet_by_name(char const *name, inet value)
{
    return ::cass_user_type_set_inet_by_name(p, name, value);
}

inline error user_type::set_inet_by_name_n(char const *name, size_t name_length,
        inet value)
{
    return ::cass_user_type_set_inet_by_name_n(p, name, name_length, value);
}

inline error user_type::set_decimal(size_t index, byte_t const *varint,
        size_t varint_size, int scale)
{
    return ::cass_user_type_set_decimal(p, index, varint, varint_size, scale);
}

inline error user_type::set_decimal_by_name(char const *name,
        byte_t const *varint, size_t varint_size, int scale)
{
    return ::cass_user_type_set_decimal_by_name(p, name, varint, varint_size,
            scale);
}

inline error user_type::set_decimal_by_name_n(char const *name,
        size_t name_length, byte_t const *varint, size_t varint_size, int scale)
{
    return ::cass_user_type_set_decimal_by_name_n(p, name, name_length, varint,
            varint_size, scale);
}

inline error user_type::set_user_type(size_t index, user_type const *value)
{
    return ::cass_user_type_set_user_type(p, index, value->backend());
}

inline error user_type::set_user_type_by_name(char const *name,
        user_type const *value)
{
    return ::cass_user_type_set_user_type_by_name(p, name, value->backend());
}

inline error user_type::set_user_type_by_name_n(char const *name,
        size_t name_length, user_type const *value)
{
    return ::cass_user_type_set_user_type_by_name_n(p, name, name_length,
            value->backend());
}

} // namespace cass

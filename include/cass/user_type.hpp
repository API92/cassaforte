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

typedef wrapper_ptr<user_type> user_type_ptr;

class user_type : wrapper {
public:
    static user_type * ptr(::CassUserType *p)
    {
        return reinterpret_cast<user_type *>(p);
    }

    ::CassUserType * backend()
    {
        return reinterpret_cast<::CassUserType *>(this);
    }

    ::CassUserType const * backend() const
    {
        return reinterpret_cast<::CassUserType const *>(this);
    }

    inline void free();

    CASSA_IMPEXP user_type_ptr new_from_data_type(
            cass::data_type const *data_type);

    CASSA_IMPEXP cass::data_type const * data_type() const;

    inline error set(size_t index, nullptr_t);
    inline error set_by_name(char const *name, nullptr_t);
    inline error set_by_name_n(char const *name, size_t name_length, nullptr_t);

    inline error set(size_t index, int8_t value);
    inline error set_by_name(char const *name, int8_t value);
    inline error set_by_name_n(char const *name, size_t name_length,
            int8_t value);

    inline error set(size_t index, int16_t value);
    inline error set_by_name(char const *name, int16_t value);
    inline error set_by_name_n(char const *name,
            size_t name_length, int16_t value);

    inline error set(size_t index, int32_t value);
    inline error set_by_name(char const *name, int32_t value);
    inline error set_by_name_n(char const *name,
            size_t name_length, int32_t value);

    inline error set(size_t index, uint32_t value);
    inline error set_by_name(char const *name, uint32_t value);
    inline error set_by_name_n(char const *name,
            size_t name_length, uint32_t value);

    inline error set(size_t index, int64_t value);
    inline error set_by_name(char const *name, int64_t value);
    inline error set_by_name_n(char const *name,
            size_t name_length, int64_t value);

    inline error set(size_t index, float value);
    inline error set_by_name(char const *name, float value);
    inline error set_by_name_n(
            char const *name, size_t name_length, float value);

    inline error set(size_t index, double value);
    inline error set_by_name(char const *name, double value);
    inline error set_by_name_n(char const *name,
            size_t name_length, double value);

    inline error set(size_t index, bool value);
    inline error set_by_name(char const *name, bool value);
    inline error set_by_name_n(char const *name, size_t name_length,
            bool value);

    inline error set(size_t index, char const *value);
    inline error set(size_t index, std::experimental::string_view value);
    inline error set_by_name(char const *name, char const *value);
    inline error set_by_name_n(char const *name,
            size_t name_length, std::experimental::string_view value);

    inline error set(size_t index, bytes_view value);
    inline error set_by_name(char const *name, bytes_view value);
    inline error set_by_name_n(char const *name,
            size_t name_length, bytes_view value);

    inline error set(size_t index, custom c);
    inline error set_by_name_n(char const *name, size_t name_length, custom c);

    inline error set(size_t index, uuid value);
    inline error set_by_name(char const *name, uuid value);
    inline error set_by_name_n(char const *name, size_t name_length,
            uuid value);

    inline error set(size_t index, inet value);
    inline error set_by_name(char const *name, inet value);
    inline error set_by_name_n(char const *name, size_t name_length,
            inet value);

    inline error set(size_t index, decimal d);
    inline error set_by_name(char const *name, decimal d);
    inline error set_by_name_n(char const *name, size_t name_length,
            decimal d);

    inline error set(size_t index, user_type const *value);
    inline error set_by_name(char const *name, user_type const *value);
    inline error set_by_name_n(char const *name,
            size_t name_length, user_type const *value);

    CASSA_IMPEXP error set(size_t index, collection const *value);
    CASSA_IMPEXP error set_by_name(char const *name, collection const *value);
    CASSA_IMPEXP error set_by_name_n(char const *name,
            size_t name_length, collection const *value);

    CASSA_IMPEXP error set(size_t index, tuple const *value);
    CASSA_IMPEXP error set_by_name(char const *name, tuple const *value);
    CASSA_IMPEXP error set_by_name_n(
            char const *name, size_t name_length, tuple const *value);

    template<typename T>
    error set_by_name(std::experimental::string_view name, T value)
    {
        return set_by_name_n(name.data(), name.size(), value);
    }

    inline error set_custom(size_t index, char const *class_name,
            byte_t const *value, size_t value_size);
    inline error set_custom_by_name(char const *name, char const *class_name,
            byte_t const *value, size_t value_size);
};

inline void user_type::free()
{
    ::cass_user_type_free(backend());
}

inline error user_type::set(size_t index, nullptr_t)
{
    return (error)::cass_user_type_set_null(backend(), index);
}

inline error user_type::set_by_name(char const *name, nullptr_t)
{
    return (error)::cass_user_type_set_null_by_name(backend(), name);
}

inline error user_type::set_by_name_n(
        char const *name, size_t name_length, nullptr_t)
{
    return (error)::cass_user_type_set_null_by_name_n(
            backend(), name, name_length);
}

inline error user_type::set(size_t index, int8_t value)
{
    return (error)::cass_user_type_set_int8(backend(), index, value);
}

inline error user_type::set_by_name(char const *name, int8_t value)
{
    return (error)::cass_user_type_set_int8_by_name(backend(), name, value);
}

inline error user_type::set_by_name_n(char const *name, size_t name_length,
        int8_t value)
{
    return (error)::cass_user_type_set_int8_by_name_n(
            backend(), name, name_length, value);
}

inline error user_type::set(size_t index, int16_t value)
{
    return (error)::cass_user_type_set_int16(backend(), index, value);
}

inline error user_type::set_by_name(char const *name, int16_t value)
{
    return (error)::cass_user_type_set_int16_by_name(backend(), name, value);
}

inline error user_type::set_by_name_n(char const *name,
        size_t name_length, int16_t value)
{
    return (error)::cass_user_type_set_int16_by_name_n(
            backend(), name, name_length, value);
}

inline error user_type::set(size_t index, int32_t value)
{
    return (error)::cass_user_type_set_int32(backend(), index, value);
}

inline error user_type::set_by_name(char const *name, int32_t value)
{
    return (error)::cass_user_type_set_int32_by_name(backend(), name, value);
}

inline error user_type::set_by_name_n(char const *name,
        size_t name_length, int32_t value)
{
    return (error)::cass_user_type_set_int32_by_name_n(
            backend(), name, name_length, value);
}

inline error user_type::set(size_t index, uint32_t value)
{
    return (error)::cass_user_type_set_uint32(backend(), index, value);
}

inline error user_type::set_by_name(char const *name, uint32_t value)
{
    return (error)::cass_user_type_set_uint32_by_name(backend(), name, value);
}

inline error user_type::set_by_name_n(char const *name,
        size_t name_length, uint32_t value)
{
    return (error)::cass_user_type_set_uint32_by_name_n(
            backend(), name, name_length, value);
}

inline error user_type::set(size_t index, int64_t value)
{
    return (error)::cass_user_type_set_int64(backend(), index, value);
}

inline error user_type::set_by_name(char const *name, int64_t value)
{
    return (error)::cass_user_type_set_int64_by_name(backend(), name, value);
}

inline error user_type::set_by_name_n(char const *name,
        size_t name_length, int64_t value)
{
    return (error)::cass_user_type_set_int64_by_name_n(
            backend(), name, name_length, value);
}

inline error user_type::set(size_t index, float value)
{
    return (error)::cass_user_type_set_float(backend(), index, value);
}

inline error user_type::set_by_name(char const *name, float value)
{
    return (error)::cass_user_type_set_float_by_name(backend(), name, value);
}

inline error user_type::set_by_name_n(
        char const *name, size_t name_length, float value)
{
    return (error)::cass_user_type_set_float_by_name_n(
            backend(), name, name_length, value);
}

inline error user_type::set(size_t index, double value)
{
    return (error)::cass_user_type_set_double(backend(), index, value);
}

inline error user_type::set_by_name(char const *name, double value)
{
    return (error)::cass_user_type_set_double_by_name(backend(), name, value);
}

inline error user_type::set_by_name_n(char const *name,
        size_t name_length, double value)
{
    return (error)::cass_user_type_set_double_by_name_n(
            backend(), name, name_length, value);
}

inline error user_type::set(size_t index, bool value)
{
    return (error)::cass_user_type_set_bool(
            backend(), index, value ? cass_true : cass_false);
}

inline error user_type::set_by_name(char const *name, bool value)
{
    return (error)::cass_user_type_set_bool_by_name(backend(), name,
            value ? cass_true : cass_false);
}

inline error user_type::set_by_name_n(char const *name, size_t name_length,
        bool value)
{
    return (error)::cass_user_type_set_bool_by_name_n(
            backend(), name, name_length, value ? cass_true : cass_false);
}

inline error user_type::set(size_t index, char const *value)
{
    return (error)::cass_user_type_set_string(backend(), index, value);
}

inline error user_type::set(size_t index, std::experimental::string_view value)
{
    return (error)::cass_user_type_set_string_n(
            backend(), index, value.data(), value.size());
}

inline error user_type::set_by_name(char const *name, char const *value)
{
    return (error)::cass_user_type_set_string_by_name(backend(), name, value);
}

inline error user_type::set_by_name_n(char const *name,
        size_t name_length, std::experimental::string_view value)
{
    return (error)::cass_user_type_set_string_by_name_n(
            backend(), name, name_length, value.data(), value.size());
}

inline error user_type::set(size_t index, bytes_view value)
{
    return (error)::cass_user_type_set_bytes(
            backend(), index, value.data(), value.size());
}

inline error user_type::set_by_name(char const *name, bytes_view value)
{
    return (error)::cass_user_type_set_bytes_by_name(
            backend(), name, value.data(), value.size());
}

inline error user_type::set_by_name_n(char const *name,
        size_t name_length, bytes_view value)
{
    return (error)::cass_user_type_set_bytes_by_name_n(
            backend(), name, name_length, value.data(), value.size());
}

inline error user_type::set_custom(size_t index, char const *class_name,
        byte_t const *value, size_t value_size)
{
    return (error)::cass_user_type_set_custom(
            backend(), index, class_name, value, value_size);
}

inline error user_type::set(size_t index, custom c)
{
    return (error)::cass_user_type_set_custom_n(backend(), index,
            c.class_name.data(), c.class_name.size(),
            c.value.data(), c.value.size());
}

inline error user_type::set_custom_by_name(char const *name,
        char const *class_name, byte_t const *value, size_t value_size)
{
    return (error)::cass_user_type_set_custom_by_name(backend(), name,
            class_name, value, value_size);
}

inline error user_type::set_by_name_n(char const *name, size_t name_length,
        custom c)
{
    return (error)::cass_user_type_set_custom_by_name_n(backend(),
            name, name_length,
            c.class_name.data(), c.class_name.size(),
            c.value.data(), c.value.size());
}

inline error user_type::set(size_t index, uuid value)
{
    return (error)::cass_user_type_set_uuid(backend(), index, value);
}

inline error user_type::set_by_name(char const *name, uuid value)
{
    return (error)::cass_user_type_set_uuid_by_name(backend(), name, value);
}

inline error user_type::set_by_name_n(char const *name, size_t name_length,
        uuid value)
{
    return (error)::cass_user_type_set_uuid_by_name_n(
            backend(), name, name_length, value);
}

inline error user_type::set(size_t index, inet value)
{
    return (error)::cass_user_type_set_inet(backend(), index, value);
}

inline error user_type::set_by_name(char const *name, inet value)
{
    return (error)::cass_user_type_set_inet_by_name(backend(), name, value);
}

inline error user_type::set_by_name_n(char const *name, size_t name_length,
        inet value)
{
    return (error)::cass_user_type_set_inet_by_name_n(
            backend(), name, name_length, value);
}

inline error user_type::set(size_t index, decimal d)
{
    return (error)::cass_user_type_set_decimal(
            backend(), index, d.varint, d.varint_size, d.scale);
}

inline error user_type::set_by_name(char const *name, decimal d)
{
    return (error)::cass_user_type_set_decimal_by_name(
            backend(), name, d.varint, d.varint_size, d.scale);
}

inline error user_type::set_by_name_n(char const *name, size_t name_length,
        decimal d)
{
    return (error)::cass_user_type_set_decimal_by_name_n(
            backend(), name, name_length, d.varint, d.varint_size, d.scale);
}

inline error user_type::set(size_t index, user_type const *value)
{
    return (error)::cass_user_type_set_user_type(
            backend(), index, value->backend());
}

inline error user_type::set_by_name(char const *name,
        user_type const *value)
{
    return (error)::cass_user_type_set_user_type_by_name(
            backend(), name, value->backend());
}

inline error user_type::set_by_name_n(char const *name,
        size_t name_length, user_type const *value)
{
    return (error)::cass_user_type_set_user_type_by_name_n(
            backend(), name, name_length, value->backend());
}

} // namespace cass

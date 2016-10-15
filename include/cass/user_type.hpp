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

    template<typename T>
    error set(size_t index, T value);

    template<typename T>
    error set_by_name(char const *name, T value);

    template<typename T>
    error set_by_name_n(char const *name, size_t name_length, T value);

    template<typename T>
    error set_by_name(std::experimental::string_view name, T value)
    {
        return set_by_name_n(name.data(), name.size(), value);
    }

    inline error set_custom(size_t index, char const *class_name,
            byte_t const *value, size_t value_size);
    inline error set_custom_by_name(char const *name, char const *class_name,
            byte_t const *value, size_t value_size);

private:
    ::CassUserType *p;
};

inline void user_type::free(user_type const u)
{
    ::cass_user_type_free(u.p);
}

template<>
inline error user_type::set(size_t index, nullptr_t)
{
    return (error)::cass_user_type_set_null(p, index);
}

template<>
inline error user_type::set_by_name(char const *name, nullptr_t)
{
    return (error)::cass_user_type_set_null_by_name(p, name);
}

template<>
inline error user_type::set_by_name_n(
        char const *name, size_t name_length, nullptr_t)
{
    return (error)::cass_user_type_set_null_by_name_n(p, name, name_length);
}

template<>
inline error user_type::set(size_t index, int8_t value)
{
    return (error)::cass_user_type_set_int8(p, index, value);
}

template<>
inline error user_type::set_by_name(char const *name, int8_t value)
{
    return (error)::cass_user_type_set_int8_by_name(p, name, value);
}

template<>
inline error user_type::set_by_name_n(char const *name, size_t name_length,
        int8_t value)
{
    return (error)::cass_user_type_set_int8_by_name_n(
            p, name, name_length, value);
}

template<>
inline error user_type::set(size_t index, int16_t value)
{
    return (error)::cass_user_type_set_int16(p, index, value);
}

template<>
inline error user_type::set_by_name(char const *name, int16_t value)
{
    return (error)::cass_user_type_set_int16_by_name(p, name, value);
}

template<>
inline error user_type::set_by_name_n(char const *name,
        size_t name_length, int16_t value)
{
    return (error)::cass_user_type_set_int16_by_name_n(
            p, name, name_length, value);
}

template<>
inline error user_type::set(size_t index, int32_t value)
{
    return (error)::cass_user_type_set_int32(p, index, value);
}

template<>
inline error user_type::set_by_name(char const *name, int32_t value)
{
    return (error)::cass_user_type_set_int32_by_name(p, name, value);
}

template<>
inline error user_type::set_by_name_n(char const *name,
        size_t name_length, int32_t value)
{
    return (error)::cass_user_type_set_int32_by_name_n(
            p, name, name_length, value);
}

template<>
inline error user_type::set(size_t index, uint32_t value)
{
    return (error)::cass_user_type_set_uint32(p, index, value);
}

template<>
inline error user_type::set_by_name(char const *name, uint32_t value)
{
    return (error)::cass_user_type_set_uint32_by_name(p, name, value);
}

template<>
inline error user_type::set_by_name_n(char const *name,
        size_t name_length, uint32_t value)
{
    return (error)::cass_user_type_set_uint32_by_name_n(
            p, name, name_length, value);
}

template<>
inline error user_type::set(size_t index, int64_t value)
{
    return (error)::cass_user_type_set_int64(p, index, value);
}

template<>
inline error user_type::set_by_name(char const *name, int64_t value)
{
    return (error)::cass_user_type_set_int64_by_name(p, name, value);
}

template<>
inline error user_type::set_by_name_n(char const *name,
        size_t name_length, int64_t value)
{
    return (error)::cass_user_type_set_int64_by_name_n(
            p, name, name_length, value);
}

template<>
inline error user_type::set(size_t index, float value)
{
    return (error)::cass_user_type_set_float(p, index, value);
}

template<>
inline error user_type::set_by_name(char const *name, float value)
{
    return (error)::cass_user_type_set_float_by_name(p, name, value);
}

template<>
inline error user_type::set_by_name_n(
        char const *name, size_t name_length, float value)
{
    return (error)::cass_user_type_set_float_by_name_n(
            p, name, name_length, value);
}

template<>
inline error user_type::set(size_t index, double value)
{
    return (error)::cass_user_type_set_double(p, index, value);
}

template<>
inline error user_type::set_by_name(char const *name, double value)
{
    return (error)::cass_user_type_set_double_by_name(p, name, value);
}

template<>
inline error user_type::set_by_name_n(char const *name,
        size_t name_length, double value)
{
    return (error)::cass_user_type_set_double_by_name_n(
            p, name, name_length, value);
}

template<>
inline error user_type::set(size_t index, bool value)
{
    return (error)::cass_user_type_set_bool(
            p, index, value ? cass_true : cass_false);
}

template<>
inline error user_type::set_by_name(char const *name, bool value)
{
    return (error)::cass_user_type_set_bool_by_name(p, name,
            value ? cass_true : cass_false);
}

template<>
inline error user_type::set_by_name_n(char const *name, size_t name_length,
        bool value)
{
    return (error)::cass_user_type_set_bool_by_name_n(p, name, name_length,
            value ? cass_true : cass_false);
}

template<>
inline error user_type::set(size_t index, char const *value)
{
    return (error)::cass_user_type_set_string(p, index, value);
}

template<>
inline error user_type::set(size_t index, std::experimental::string_view value)
{
    return (error)::cass_user_type_set_string_n(
            p, index, value.data(), value.size());
}

template<>
inline error user_type::set_by_name(char const *name, char const *value)
{
    return (error)::cass_user_type_set_string_by_name(p, name, value);
}

template<>
inline error user_type::set_by_name_n(char const *name,
        size_t name_length, std::experimental::string_view value)
{
    return (error)::cass_user_type_set_string_by_name_n(
            p, name, name_length, value.data(), value.size());
}

template<>
inline error user_type::set(size_t index, bytes_view value)
{
    return (error)::cass_user_type_set_bytes(
            p, index, value.data(), value.size());
}

template<>
inline error user_type::set_by_name(char const *name, bytes_view value)
{
    return (error)::cass_user_type_set_bytes_by_name(
            p, name, value.data(), value.size());
}

template<>
inline error user_type::set_by_name_n(char const *name,
        size_t name_length, bytes_view value)
{
    return (error)::cass_user_type_set_bytes_by_name_n(
            p, name, name_length, value.data(), value.size());
}

inline error user_type::set_custom(size_t index, char const *class_name,
        byte_t const *value, size_t value_size)
{
    return (error)::cass_user_type_set_custom(
            p, index, class_name, value, value_size);
}

template<>
inline error user_type::set(size_t index, custom c)
{
    return (error)::cass_user_type_set_custom_n(p, index, c.class_name.data(),
            c.class_name.size(), c.value.data(), c.value.size());
}

inline error user_type::set_custom_by_name(char const *name,
        char const *class_name, byte_t const *value, size_t value_size)
{
    return (error)::cass_user_type_set_custom_by_name(p, name, class_name,
            value, value_size);
}

template<>
inline error user_type::set_by_name_n(char const *name, size_t name_length,
        custom c)
{
    return (error)::cass_user_type_set_custom_by_name_n(p, name, name_length,
            c.class_name.data(), c.class_name.size(),
            c.value.data(), c.value.size());
}

template<>
inline error user_type::set(size_t index, uuid value)
{
    return (error)::cass_user_type_set_uuid(p, index, value);
}

template<>
inline error user_type::set_by_name(char const *name, uuid value)
{
    return (error)::cass_user_type_set_uuid_by_name(p, name, value);
}

template<>
inline error user_type::set_by_name_n(char const *name, size_t name_length,
        uuid value)
{
    return (error)::cass_user_type_set_uuid_by_name_n(
            p, name, name_length, value);
}

template<>
inline error user_type::set(size_t index, inet value)
{
    return (error)::cass_user_type_set_inet(p, index, value);
}

template<>
inline error user_type::set_by_name(char const *name, inet value)
{
    return (error)::cass_user_type_set_inet_by_name(p, name, value);
}

template<>
inline error user_type::set_by_name_n(char const *name, size_t name_length,
        inet value)
{
    return (error)::cass_user_type_set_inet_by_name_n(
            p, name, name_length, value);
}

template<>
inline error user_type::set(size_t index, decimal d)
{
    return (error)::cass_user_type_set_decimal(
            p, index, d.varint, d.varint_size, d.scale);
}

template<>
inline error user_type::set_by_name(char const *name, decimal d)
{
    return (error)::cass_user_type_set_decimal_by_name(
            p, name, d.varint, d.varint_size, d.scale);
}

template<>
inline error user_type::set_by_name_n(char const *name, size_t name_length,
        decimal d)
{
    return (error)::cass_user_type_set_decimal_by_name_n(
            p, name, name_length, d.varint, d.varint_size, d.scale);
}

template<>
inline error user_type::set(size_t index, user_type const *value)
{
    return (error)::cass_user_type_set_user_type(p, index, value->backend());
}

template<>
inline error user_type::set_by_name(char const *name,
        user_type const *value)
{
    return (error)::cass_user_type_set_user_type_by_name(
            p, name, value->backend());
}

template<>
inline error user_type::set_by_name_n(char const *name,
        size_t name_length, user_type const *value)
{
    return (error)::cass_user_type_set_user_type_by_name_n(p, name, name_length,
            value->backend());
}

template<>
CASSA_IMPEXP error user_type::set(size_t index, collection const *value);

template<>
CASSA_IMPEXP error user_type::set_by_name(char const *name,
        collection const *value);

template<>
CASSA_IMPEXP error user_type::set_by_name_n(char const *name,
        size_t name_length, collection const *value);

template<>
CASSA_IMPEXP error user_type::set(size_t index, tuple const *value);

template<>
CASSA_IMPEXP error user_type::set_by_name(char const *name, tuple const *value);

template<>
CASSA_IMPEXP error user_type::set_by_name_n(
        char const *name, size_t name_length, tuple const *value);

} // namespace cass

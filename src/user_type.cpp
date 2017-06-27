/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/user_type.hpp>

#include <cassandra.h>

#include <cass/collection.hpp>
#include <cass/custom.hpp>
#include <cass/data_type.hpp>
#include <cass/decimal.hpp>
#include <cass/inet.hpp>
#include <cass/tuple.hpp>
#include <cass/uuid.hpp>
#include <cass/wrapper_ptr_def.hpp>

namespace cass {

user_type * user_type::ptr(::CassUserType *p)
{
    return reinterpret_cast<user_type *>(p);
}

::CassUserType * user_type::backend()
{
    return reinterpret_cast<::CassUserType *>(this);
}

::CassUserType const * user_type::backend() const
{
    return reinterpret_cast<::CassUserType const *>(this);
}

void user_type::free()
{
    ::cass_user_type_free(backend());
}

error user_type::set(size_t index, std::nullptr_t)
{
    return (error)::cass_user_type_set_null(backend(), index);
}

error user_type::set_by_name(char const *name, std::nullptr_t)
{
    return (error)::cass_user_type_set_null_by_name(backend(), name);
}

error user_type::set_by_name_n(
        char const *name, size_t name_length, std::nullptr_t)
{
    return (error)::cass_user_type_set_null_by_name_n(
            backend(), name, name_length);
}

error user_type::set(size_t index, int8_t value)
{
    return (error)::cass_user_type_set_int8(backend(), index, value);
}

error user_type::set_by_name(char const *name, int8_t value)
{
    return (error)::cass_user_type_set_int8_by_name(backend(), name, value);
}

error user_type::set_by_name_n(char const *name, size_t name_length,
        int8_t value)
{
    return (error)::cass_user_type_set_int8_by_name_n(
            backend(), name, name_length, value);
}

error user_type::set(size_t index, int16_t value)
{
    return (error)::cass_user_type_set_int16(backend(), index, value);
}

error user_type::set_by_name(char const *name, int16_t value)
{
    return (error)::cass_user_type_set_int16_by_name(backend(), name, value);
}

error user_type::set_by_name_n(char const *name,
        size_t name_length, int16_t value)
{
    return (error)::cass_user_type_set_int16_by_name_n(
            backend(), name, name_length, value);
}

error user_type::set(size_t index, int32_t value)
{
    return (error)::cass_user_type_set_int32(backend(), index, value);
}

error user_type::set_by_name(char const *name, int32_t value)
{
    return (error)::cass_user_type_set_int32_by_name(backend(), name, value);
}

error user_type::set_by_name_n(char const *name,
        size_t name_length, int32_t value)
{
    return (error)::cass_user_type_set_int32_by_name_n(
            backend(), name, name_length, value);
}

error user_type::set(size_t index, uint32_t value)
{
    return (error)::cass_user_type_set_uint32(backend(), index, value);
}

error user_type::set_by_name(char const *name, uint32_t value)
{
    return (error)::cass_user_type_set_uint32_by_name(backend(), name, value);
}

error user_type::set_by_name_n(char const *name,
        size_t name_length, uint32_t value)
{
    return (error)::cass_user_type_set_uint32_by_name_n(
            backend(), name, name_length, value);
}

error user_type::set(size_t index, int64_t value)
{
    return (error)::cass_user_type_set_int64(backend(), index, value);
}

error user_type::set_by_name(char const *name, int64_t value)
{
    return (error)::cass_user_type_set_int64_by_name(backend(), name, value);
}

error user_type::set_by_name_n(char const *name,
        size_t name_length, int64_t value)
{
    return (error)::cass_user_type_set_int64_by_name_n(
            backend(), name, name_length, value);
}

error user_type::set(size_t index, float value)
{
    return (error)::cass_user_type_set_float(backend(), index, value);
}

error user_type::set_by_name(char const *name, float value)
{
    return (error)::cass_user_type_set_float_by_name(backend(), name, value);
}

error user_type::set_by_name_n(
        char const *name, size_t name_length, float value)
{
    return (error)::cass_user_type_set_float_by_name_n(
            backend(), name, name_length, value);
}

error user_type::set(size_t index, double value)
{
    return (error)::cass_user_type_set_double(backend(), index, value);
}

error user_type::set_by_name(char const *name, double value)
{
    return (error)::cass_user_type_set_double_by_name(backend(), name, value);
}

error user_type::set_by_name_n(char const *name,
        size_t name_length, double value)
{
    return (error)::cass_user_type_set_double_by_name_n(
            backend(), name, name_length, value);
}

error user_type::set(size_t index, bool value)
{
    return (error)::cass_user_type_set_bool(
            backend(), index, value ? cass_true : cass_false);
}

error user_type::set_by_name(char const *name, bool value)
{
    return (error)::cass_user_type_set_bool_by_name(backend(), name,
            value ? cass_true : cass_false);
}

error user_type::set_by_name_n(char const *name, size_t name_length,
        bool value)
{
    return (error)::cass_user_type_set_bool_by_name_n(
            backend(), name, name_length, value ? cass_true : cass_false);
}

error user_type::set(size_t index, char const *value)
{
    return (error)::cass_user_type_set_string(backend(), index, value);
}

error user_type::set(size_t index, std::string_view value)
{
    return (error)::cass_user_type_set_string_n(
            backend(), index, value.data(), value.size());
}

error user_type::set_by_name(char const *name, char const *value)
{
    return (error)::cass_user_type_set_string_by_name(backend(), name, value);
}

error user_type::set_by_name_n(char const *name, size_t name_length,
        std::string_view value)
{
    return (error)::cass_user_type_set_string_by_name_n(
            backend(), name, name_length, value.data(), value.size());
}

error user_type::set(size_t index, bytes_view value)
{
    return (error)::cass_user_type_set_bytes(
            backend(), index, (cass_byte_t const *)value.data(), value.size());
}

error user_type::set_by_name(char const *name, bytes_view value)
{
    return (error)::cass_user_type_set_bytes_by_name(
            backend(), name, (cass_byte_t const *)value.data(), value.size());
}

error user_type::set_by_name_n(char const *name,
        size_t name_length, bytes_view value)
{
    return (error)::cass_user_type_set_bytes_by_name_n(backend(),
            name, name_length, (cass_byte_t const *)value.data(), value.size());
}

error user_type::set_custom(size_t index, char const *class_name,
        std::byte const *value, size_t value_size)
{
    return (error)::cass_user_type_set_custom(backend(), index, class_name,
            (cass_byte_t const *)value, value_size);
}

error user_type::set(size_t index, custom c)
{
    return (error)::cass_user_type_set_custom_n(backend(), index,
            c.class_name.data(), c.class_name.size(),
            (cass_byte_t const *)c.value.data(), c.value.size());
}

error user_type::set_custom_by_name(char const *name,
        char const *class_name, std::byte const *value, size_t value_size)
{
    return (error)::cass_user_type_set_custom_by_name(backend(), name,
            class_name, (cass_byte_t const *)value, value_size);
}

error user_type::set_by_name_n(char const *name, size_t name_length,
        custom c)
{
    return (error)::cass_user_type_set_custom_by_name_n(backend(),
            name, name_length,
            c.class_name.data(), c.class_name.size(),
            (cass_byte_t const *)c.value.data(), c.value.size());
}

error user_type::set(size_t index, uuid const &value)
{
    return (error)::cass_user_type_set_uuid(backend(), index, *value.backend());
}

error user_type::set_by_name(char const *name, uuid const &value)
{
    return (error)::cass_user_type_set_uuid_by_name(backend(), name,
            *value.backend());
}

error user_type::set_by_name_n(char const *name, size_t name_length,
        uuid const &value)
{
    return (error)::cass_user_type_set_uuid_by_name_n(
            backend(), name, name_length, *value.backend());
}

error user_type::set(size_t index, inet const &value)
{
    return (error)::cass_user_type_set_inet(backend(), index, *value.backend());
}

error user_type::set_by_name(char const *name, inet const &value)
{
    return (error)::cass_user_type_set_inet_by_name(backend(), name,
            *value.backend());
}

error user_type::set_by_name_n(char const *name, size_t name_length,
        inet const &value)
{
    return (error)::cass_user_type_set_inet_by_name_n(
            backend(), name, name_length, *value.backend());
}

error user_type::set(size_t index, decimal d)
{
    return (error)::cass_user_type_set_decimal(backend(), index,
            (cass_byte_t const *)d.varint, d.varint_size, d.scale);
}

error user_type::set_by_name(char const *name, decimal d)
{
    return (error)::cass_user_type_set_decimal_by_name(backend(), name,
            (cass_byte_t const *)d.varint, d.varint_size, d.scale);
}

error user_type::set_by_name_n(char const *name, size_t name_length,
        decimal d)
{
    return (error)::cass_user_type_set_decimal_by_name_n(backend(), name,
            name_length, (cass_byte_t const *)d.varint, d.varint_size, d.scale);
}

error user_type::set(size_t index, user_type const *value)
{
    return (error)::cass_user_type_set_user_type(
            backend(), index, value->backend());
}

error user_type::set_by_name(char const *name,
        user_type const *value)
{
    return (error)::cass_user_type_set_user_type_by_name(
            backend(), name, value->backend());
}

error user_type::set_by_name_n(char const *name,
        size_t name_length, user_type const *value)
{
    return (error)::cass_user_type_set_user_type_by_name_n(
            backend(), name, name_length, value->backend());
}

user_type_ptr user_type::new_from_data_type(cass::data_type const *data_type)
{
    ::CassUserType * t = ::cass_user_type_new_from_data_type(
            data_type->backend());
    return user_type_ptr(ptr(t));
}

data_type const * user_type::data_type() const
{
    return cass::data_type::ptr(::cass_user_type_data_type(backend()));
}

error user_type::set(size_t index, collection const *value)
{
    return (error)::cass_user_type_set_collection(
            backend(), index, value->backend());
}

error user_type::set_by_name(char const *name,
        collection const *value)
{
    return (error)::cass_user_type_set_collection_by_name(
            backend(), name, value->backend());
}

error user_type::set_by_name_n(char const *name,
        size_t name_length, collection const *value)
{
    return (error)::cass_user_type_set_collection_by_name_n(
            backend(), name, name_length, value->backend());
}

error user_type::set(size_t index, tuple const *value)
{
    return (error)::cass_user_type_set_tuple(
            backend(), index, value->backend());
}

error user_type::set_by_name(char const *name, tuple const *value)
{
    return (error)::cass_user_type_set_tuple_by_name(
            backend(), name, value->backend());
}

error user_type::set_by_name_n(char const *name, size_t name_length,
        tuple const *value)
{
    return (error)::cass_user_type_set_tuple_by_name_n(
            backend(), name, name_length, value->backend());
}

template class wrapper_ptr<user_type>;

} // namespace cass

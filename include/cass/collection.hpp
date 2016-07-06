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

typedef wrapper_ptr<class collection> collection_ptr;

class collection {
public:
    explicit collection(::CassCollection *p) : p(p) {}
    ::CassCollection * backend() { return p; }
    ::CassCollection const * backend() const { return p; }

    inline static void free(collection const c);
    inline static collection_ptr new_ptr(colletion_type type,
            size_t item_count);

    CASSA_IMPEXP static collection_ptr new_from_data_type(
            cass::data_type const *data_type, size_t item_count);

    CASSA_IMPEXP data_type_const_ptr data_type() const;

    inline error append_int8(int8_t value);

    inline error append_int16(int16_t value);

    inline error append_int32(int32_t value);

    inline error append_uint32(uint32_t value);

    inline error append_int64(int64_t value);

    inline error append_float(float value);

    inline error append_double(double value);

    inline error append_bool(bool value);

    inline error append_string(char const *value);
    inline error append_string_n(char const *value, size_t value_length);

    inline error append_bytes(byte_t const *value, size_t value_size);

    inline error append_custom(char const *class_name, byte_t const *value,
            size_t value_size);
    inline error append_custom_n(char const *class_name,
            size_t class_name_length, byte_t const *value, size_t value_size);

    inline error append_uuid(uuid value);

    inline error append_inet(inet value);

    inline error append_decimal(byte_t const *varint, size_t varint_size,
            int32_t scale);

    inline error append_collection(collection const *value);

    CASSA_IMPEXP error append_tuple(tuple const *value);

    CASSA_IMPEXP error append_user_type(user_type const *value);

private:
    ::CassCollection *p;
};

inline void collection::free(collection const c)
{
    ::cass_collection_free(c.p);
}

inline collection_ptr collection::new_ptr(colletion_type type,
        size_t item_count)
{
    return collection_ptr(collection(::cass_collection_new(type, item_count)),
            true);
}

inline error collection::append_int8(int8_t value)
{
    return ::cass_collection_append_int8(p, value);
}

inline error collection::append_int16(int16_t value)
{
    return ::cass_collection_append_int16(p, value);
}

inline error collection::append_int32(int32_t value)
{
    return ::cass_collection_append_int32(p, value);
}

inline error collection::append_uint32(uint32_t value)
{
    return ::cass_collection_append_uint32(p, value);
}

inline error collection::append_int64(int64_t value)
{
    return ::cass_collection_append_int64(p, value);
}

inline error collection::append_float(float value)
{
    return ::cass_collection_append_float(p, value);
}

inline error collection::append_double(double value)
{
    return ::cass_collection_append_double(p, value);
}

inline error collection::append_bool(bool value)
{
    return ::cass_collection_append_bool(p, value ? cass_true : cass_false);
}

inline error collection::append_string(char const *value)
{
    return ::cass_collection_append_string(p, value);
}

inline error collection::append_string_n(char const *value, size_t value_length)
{
    return ::cass_collection_append_string_n(p, value, value_length);
}

inline error collection::append_bytes(byte_t const *value, size_t value_size)
{
    return ::cass_collection_append_bytes(p, value, value_size);
}

inline error collection::append_custom(char const *class_name,
        byte_t const *value, size_t value_size)
{
    return ::cass_collection_append_custom(p, class_name, value, value_size);
}

inline error collection::append_custom_n(char const *class_name,
        size_t class_name_length, byte_t const *value, size_t value_size)
{
    return ::cass_collection_append_custom_n(p, class_name, class_name_length,
            value, value_size);
}

inline error collection::append_uuid(uuid value)
{
    return ::cass_collection_append_uuid(p, value);
}

inline error collection::append_inet(inet value)
{
    return ::cass_collection_append_inet(p, value);
}

inline error collection::append_decimal(byte_t const *varint,
        size_t varint_size, int32_t scale)
{
    return ::cass_collection_append_decimal(p, varint, varint_size, scale);
}

inline error collection::append_collection(collection const *value)
{
    return ::cass_collection_append_collection(p, value->backend());
}

} // namespace cass

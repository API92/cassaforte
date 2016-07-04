/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/defs.hpp>
#include <cass/impexp.hpp>
#include <cass/wrapper_ptr.hpp>

namespace cass {

typedef wrapper_ptr<class statement> statement_ptr;

class statement {
public:
    explicit statement(::CassStatement *p) : p(p) {}
    ::CassStatement * backend() { return p; }
    ::CassStatement const * backend() const { return p; }

    inline static void free(statement const s);

    inline static statement_ptr new_ptr(char const *query,
            size_t parameter_count);
    inline static statement_ptr new_n_ptr(char const *query,
            size_t query_length, size_t parameter_count);

    inline error reset_parameters(size_t count);

    inline error add_key_index(size_t index);

    inline error set_keyspace(char const *keyspace);
    inline error set_keyspace_n(char const *keyspace, size_t keyspace_length);

    inline error set_consistency(cass::consistency consistency);

    inline error set_serial_consistency(cass::consistency serial_consistency);

    inline error set_paging_size(int page_size);

    CASSA_IMPEXP error set_paging_state(cass::result const *result);

    inline error set_paging_state_token(char const *paging_state,
            size_t paging_state_size);

    inline error set_timestamp(int64_t timestamp);

    inline error set_request_timeout(uint64_t timeout_ms);

    CASSA_IMPEXP error set_retry_policy(cass::retry_policy *retry_policy);

    CASSA_IMPEXP error set_custom_payload(custom_payload const *payload);

    inline error bind_null(size_t index);

    inline error bind_null_by_name(char const *name);
    inline error bind_null_by_name_n(char const *name, size_t name_length);

    inline error bind_int8(size_t index, int8_t value);
    inline error bind_int8_by_name(char const *name, int8_t value);
    inline error bind_int8_by_name_n(char const *name, size_t name_length,
            int8_t value);

    inline error bind_int16(size_t index, int16_t value);
    inline error bind_int16_by_name(char const *name, int16_t value);
    inline error bind_int16_by_name_n(char const *name, size_t name_length,
            int16_t value);

    inline error bind_int32(size_t index, int32_t value);
    inline error bind_int32_by_name(char const *name, int32_t value);
    inline error bind_int32_by_name_n(char const *name, size_t name_length,
            int32_t value);

    inline error bind_uint32(size_t index, uint32_t value);
    inline error bind_uint32_by_name(char const *name, uint32_t value);
    inline error bind_uint32_by_name_n(char const *name, size_t name_length,
            uint32_t value);

    inline error bind_int64(size_t index, int64_t value);
    inline error bind_int64_by_name(char const *name, int64_t value);
    inline error bind_int64_by_name_n(char const *name, size_t name_length,
            int64_t value);

    inline error bind_float(size_t index, float value);
    inline error bind_float_by_name(char const *name, float value);
    inline error bind_float_by_name_n(char const *name, size_t name_length,
            float value);

    inline error bind_double(size_t index, double value);
    inline error bind_double_by_name(char const *name, double value);
    inline error bind_double_by_name_n(char const *name, size_t name_length,
            double value);

    inline error bind_bool(size_t index, bool value);
    inline error bind_bool_by_name(char const *name, bool value);
    inline error bind_bool_by_name_n(char const *name, size_t name_length,
            bool value);

    inline error bind_string(size_t index, char const *value);
    inline error bind_string_n(size_t index, char const *value,
            size_t value_length);
    inline error bind_string_by_name(char const *name, char const *value);
    inline error bind_string_by_name_n(char const *name, size_t name_length,
            char const *value, size_t value_length);

    inline error bind_bytes(size_t index, byte_t const *value,
            size_t value_size);
    inline error bind_bytes_by_name(char const *name, byte_t const *value,
            size_t value_size);
    inline error bind_bytes_by_name_n(char const *name, size_t name_length,
            byte_t const *value, size_t value_size);

    inline error bind_custom(size_t index, char const *class_name,
            byte_t const *value, size_t value_size);
    inline error bind_custom_n(size_t index, char const *class_name,
            size_t class_name_length, byte_t const *value, size_t value_size);
    inline error bind_custom_by_name(char const *name, char const *class_name,
            byte_t const *value, size_t value_size);
    inline error bind_custom_by_name_n(char const *name, size_t name_length,
            char const *class_name, size_t class_name_length,
            byte_t const *value, size_t value_size);

    inline error bind_uuid(size_t index, uuid value);
    inline error bind_uuid_by_name(char const *name, uuid value);
    inline error bind_uuid_by_name_n(char const *name, size_t name_length,
            uuid value);

    inline error bind_inet(size_t index, inet value);
    inline error bind_inet_by_name(char const *name, inet value);
    inline error bind_inet_by_name_n(char const *name, size_t name_length,
            inet value);

    inline error bind_decimal(size_t index, byte_t const *varint,
            size_t varint_size, int32_t scale);
    inline error bind_decimal_by_name(char const *name, byte_t const * varint,
            size_t varint_size, int32_t scale);
    inline error bind_decimal_by_name_n(char const *name, size_t name_length,
            byte_t const * varint, size_t varint_size, int32_t scale);

    CASSA_IMPEXP error bind_collection(size_t index,
            cass::collection const *collection);
    CASSA_IMPEXP error bind_collection_by_name(char const *name,
            cass::collection const *collection);
    CASSA_IMPEXP error bind_collection_by_name_n(char const *name,
            size_t name_length, cass::collection const *collection);

    CASSA_IMPEXP error bind_tuple(size_t index, cass::tuple const *tuple);
    CASSA_IMPEXP error bind_tuple_by_name(char const *name,
            cass::tuple const *tuple);
    CASSA_IMPEXP error bind_tuple_by_name_n(char const *name,
            size_t name_length, cass::tuple const *tuple);

    CASSA_IMPEXP error bind_user_type(size_t index,
            cass::user_type const *user_type);
    CASSA_IMPEXP error bind_user_type_by_name(char const *name,
            cass::user_type const *user_type);
    CASSA_IMPEXP error bind_user_type_by_name_n(char const *name,
            size_t name_length, cass::user_type const *user_type);

private:
    ::CassStatement *p;
};

inline void statement::free(statement const s)
{
    ::cass_statement_free(s.p);
}

inline statement_ptr statement::new_ptr(char const *query,
        size_t parameter_count)
{
    return statement_ptr(statement(::cass_statement_new(
                    query, parameter_count)), true);
}

inline statement_ptr statement::new_n_ptr(char const *query,
        size_t query_length, size_t parameter_count)
{
    return statement_ptr(statement(::cass_statement_new_n(
                    query, query_length, parameter_count)), true);
}

inline error statement::reset_parameters(size_t count)
{
    return ::cass_statement_reset_parameters(p, count);
}

inline error statement::add_key_index(size_t index)
{
    return ::cass_statement_add_key_index(p, index);
}

inline error statement::set_keyspace(char const *keyspace)
{
    return ::cass_statement_set_keyspace(p, keyspace);
}

inline error statement::set_keyspace_n(char const *keyspace,
        size_t keyspace_length)
{
    return ::cass_statement_set_keyspace_n(p, keyspace, keyspace_length);
}

inline error statement::set_consistency(cass::consistency consistency)
{
    return ::cass_statement_set_consistency(p, consistency);
}

inline error statement::set_serial_consistency(
        cass::consistency serial_consistency)
{
    return ::cass_statement_set_serial_consistency(p, serial_consistency);
}

inline error statement::set_paging_size(int page_size)
{
    return ::cass_statement_set_paging_size(p, page_size);
}

inline error statement::set_paging_state_token(char const *paging_state,
        size_t paging_state_size)
{
    return ::cass_statement_set_paging_state_token(p, paging_state,
            paging_state_size);
}

inline error statement::set_timestamp(int64_t timestamp)
{
    return ::cass_statement_set_timestamp(p, timestamp);
}

inline error statement::set_request_timeout(uint64_t timeout_ms)
{
    return ::cass_statement_set_request_timeout(p, timeout_ms);
}

inline error statement::bind_null(size_t index)
{
    return ::cass_statement_bind_null(p, index);
}

inline error statement::bind_null_by_name(char const *name)
{
    return ::cass_statement_bind_null_by_name(p, name);
}

inline error statement::bind_null_by_name_n(
        char const *name, size_t name_length)
{
    return ::cass_statement_bind_null_by_name_n(p, name, name_length);
}

inline error statement::bind_int8(size_t index, int8_t value)
{
    return ::cass_statement_bind_int8(p, index, value);
}

inline error statement::bind_int8_by_name(char const *name, int8_t value)
{
    return ::cass_statement_bind_int8_by_name(p, name, value);
}

inline error statement::bind_int8_by_name_n(char const *name,
        size_t name_length, int8_t value)
{
    return ::cass_statement_bind_int8_by_name_n(p, name, name_length, value);
}

inline error statement::bind_int16(size_t index, int16_t value)
{
    return ::cass_statement_bind_int16(p, index, value);
}

inline error statement::bind_int16_by_name(char const *name, int16_t value)
{
    return ::cass_statement_bind_int16_by_name(p, name, value);
}

inline error statement::bind_int16_by_name_n(char const *name,
        size_t name_length, int16_t value)
{
    return ::cass_statement_bind_int16_by_name_n(p, name, name_length, value);
}

inline error statement::bind_int32(size_t index, int32_t value)
{
    return ::cass_statement_bind_int32(p, index, value);
}

inline error statement::bind_int32_by_name(char const *name, int32_t value)
{
    return ::cass_statement_bind_int32_by_name(p, name, value);
}

inline error statement::bind_int32_by_name_n(char const *name,
        size_t name_length, int32_t value)
{
    return ::cass_statement_bind_int32_by_name_n(p, name, name_length, value);
}

inline error statement::bind_uint32(size_t index, uint32_t value)
{
    return ::cass_statement_bind_uint32(p, index, value);
}

inline error statement::bind_uint32_by_name(char const *name, uint32_t value)
{
    return ::cass_statement_bind_uint32_by_name(p, name, value);
}

inline error statement::bind_uint32_by_name_n(char const *name,
        size_t name_length, uint32_t value)
{
    return ::cass_statement_bind_uint32_by_name_n(p, name, name_length, value);
}

inline error statement::bind_int64(size_t index, int64_t value)
{
    return ::cass_statement_bind_int64(p, index, value);
}

inline error statement::bind_int64_by_name(char const *name, int64_t value)
{
    return ::cass_statement_bind_int64_by_name(p, name, value);
}

inline error statement::bind_int64_by_name_n(char const *name,
        size_t name_length, int64_t value)
{
    return ::cass_statement_bind_int64_by_name_n(p, name, name_length, value);
}

inline error statement::bind_float(size_t index, float value)
{
    return ::cass_statement_bind_float(p, index, value);
}

inline error statement::bind_float_by_name(char const *name, float value)
{
    return ::cass_statement_bind_float_by_name(p, name, value);
}

inline error statement::bind_float_by_name_n(char const *name,
        size_t name_length, float value)
{
    return ::cass_statement_bind_float_by_name_n(p, name, name_length, value);
}

inline error statement::bind_double(size_t index, double value)
{
    return ::cass_statement_bind_double(p, index, value);
}

inline error statement::bind_double_by_name(char const *name, double value)
{
    return ::cass_statement_bind_double_by_name(p, name, value);
}

inline error statement::bind_double_by_name_n(char const *name,
        size_t name_length, double value)
{
    return ::cass_statement_bind_double_by_name_n(p, name, name_length, value);
}

inline error statement::bind_bool(size_t index, bool value)
{
    return ::cass_statement_bind_bool(p, index, value ? cass_true : cass_false);
}

inline error statement::bind_bool_by_name(char const *name, bool value)
{
    return ::cass_statement_bind_bool_by_name(p, name,
            value ? cass_true : cass_false);
}

inline error statement::bind_bool_by_name_n(char const *name,
        size_t name_length, bool value)
{
    return ::cass_statement_bind_bool_by_name_n(p, name, name_length,
            value ? cass_true : cass_false);
}

inline error statement::bind_string(size_t index, char const *value)
{
    return ::cass_statement_bind_string(p, index, value);
}

inline error statement::bind_string_n(size_t index, char const *value,
        size_t value_length)
{
    return ::cass_statement_bind_string_n(p, index, value, value_length);
}

inline error statement::bind_string_by_name(char const *name, char const *value)
{
    return ::cass_statement_bind_string_by_name(p, name, value);
}

inline error statement::bind_string_by_name_n(char const *name,
        size_t name_length, char const *value, size_t value_length)
{
    return ::cass_statement_bind_string_by_name_n(p, name, name_length, value,
            value_length);
}

inline error statement::bind_bytes(size_t index, byte_t const *value,
        size_t value_size)
{
    return ::cass_statement_bind_bytes(p, index, value, value_size);
}

inline error statement::bind_bytes_by_name(char const *name,
        byte_t const *value, size_t value_size)
{
    return ::cass_statement_bind_bytes_by_name(p, name, value, value_size);
}

inline error statement::bind_bytes_by_name_n(char const *name,
        size_t name_length, byte_t const *value, size_t value_size)
{
    return ::cass_statement_bind_bytes_by_name_n(p, name, name_length,
            value, value_size);
}

inline error statement::bind_custom(size_t index, char const *class_name,
        byte_t const *value, size_t value_size)
{
    return ::cass_statement_bind_custom(p, index, class_name, value,
            value_size);
}

inline error statement::bind_custom_n(size_t index, char const *class_name,
        size_t class_name_length, byte_t const *value, size_t value_size)
{
    return ::cass_statement_bind_custom_n(p, index, class_name,
            class_name_length, value, value_size);
}

inline error statement::bind_custom_by_name(char const *name,
        char const *class_name, byte_t const *value, size_t value_size)
{
    return ::cass_statement_bind_custom_by_name(p, name, class_name, value,
            value_size);
}

inline error statement::bind_custom_by_name_n(char const *name,
        size_t name_length, char const *class_name, size_t class_name_length,
        byte_t const *value, size_t value_size)
{
    return ::cass_statement_bind_custom_by_name_n(p, name, name_length,
            class_name, class_name_length, value, value_size);
}

inline error statement::bind_uuid(size_t index, uuid value)
{
    return ::cass_statement_bind_uuid(p, index, value);
}

inline error statement::bind_uuid_by_name(char const *name, uuid value)
{
    return ::cass_statement_bind_uuid_by_name(p, name, value);
}

inline error statement::bind_uuid_by_name_n(char const *name,
        size_t name_length, uuid value)
{
    return ::cass_statement_bind_uuid_by_name_n(p, name, name_length, value);
}

inline error statement::bind_inet(size_t index, inet value)
{
    return ::cass_statement_bind_inet(p, index, value);
}

inline error statement::bind_inet_by_name(char const *name, inet value)
{
    return ::cass_statement_bind_inet_by_name(p, name, value);
}

inline error statement::bind_inet_by_name_n(char const *name,
        size_t name_length, inet value)
{
    return ::cass_statement_bind_inet_by_name_n(p, name, name_length, value);
}

inline error statement::bind_decimal(size_t index, byte_t const *varint,
        size_t varint_size, int32_t scale)
{
    return ::cass_statement_bind_decimal(p, index, varint, varint_size, scale);
}

inline error statement::bind_decimal_by_name(char const *name,
        byte_t const * varint, size_t varint_size, int32_t scale)
{
    return ::cass_statement_bind_decimal_by_name(p, name, varint, varint_size,
            scale);
}

inline error statement::bind_decimal_by_name_n(char const *name,
        size_t name_length, byte_t const * varint, size_t varint_size,
        int32_t scale)
{
    return ::cass_statement_bind_decimal_by_name_n(p, name, name_length,
            varint, varint_size, scale);
}

} // namespace cass

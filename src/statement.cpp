/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/statement.hpp>

#include <cassandra.h>

#include <cass/collection.hpp>
#include <cass/custom_payload.hpp>
#include <cass/custom.hpp>
#include <cass/decimal.hpp>
#include <cass/inet.hpp>
#include <cass/result.hpp>
#include <cass/retry_policy.hpp>
#include <cass/tuple.hpp>
#include <cass/uuid.hpp>
#include <cass/user_type.hpp>
#include <cass/wrapper_ptr_def.hpp>

namespace cass {

statement * statement::ptr(::CassStatement *p)
{
    return reinterpret_cast<statement *>(p);
}

::CassStatement * statement::backend()
{
    return reinterpret_cast<::CassStatement *>(this);
}

::CassStatement const * statement::backend() const
{
    return reinterpret_cast<::CassStatement const *>(this);
}

void statement::free()
{
    ::cass_statement_free(backend());
}

statement_ptr statement::new_ptr(char const *query,
        size_t parameter_count)
{
    return statement_ptr(statement::ptr(::cass_statement_new(
                    query, parameter_count)));
}

statement_ptr statement::new_n_ptr(char const *query,
        size_t query_length, size_t parameter_count)
{
    return statement_ptr(statement::ptr(::cass_statement_new_n(
                    query, query_length, parameter_count)));
}

error statement::reset_parameters(size_t count)
{
    return error(::cass_statement_reset_parameters(backend(), count));
}

error statement::add_key_index(size_t index)
{
    return error(::cass_statement_add_key_index(backend(), index));
}

error statement::set_keyspace(char const *keyspace)
{
    return error(::cass_statement_set_keyspace(backend(), keyspace));
}

error statement::set_keyspace_n(char const *keyspace,
        size_t keyspace_length)
{
    return error(::cass_statement_set_keyspace_n(
                backend(), keyspace, keyspace_length));
}

error statement::set_consistency(cass::consistency consistency)
{
    return error(::cass_statement_set_consistency(backend(),
                (::CassConsistency)consistency));
}

error statement::set_serial_consistency(
        cass::consistency serial_consistency)
{
    return error(::cass_statement_set_serial_consistency(
                backend(), (::CassConsistency)serial_consistency));
}

error statement::set_paging_size(int page_size)
{
    return error(::cass_statement_set_paging_size(backend(), page_size));
}

error statement::set_paging_state_token(char const *paging_state,
        size_t paging_state_size)
{
    return error(::cass_statement_set_paging_state_token(
                backend(), paging_state, paging_state_size));
}

error statement::set_timestamp(int64_t timestamp)
{
    return error(::cass_statement_set_timestamp(backend(), timestamp));
}

error statement::set_request_timeout(uint64_t timeout_ms)
{
    return error(::cass_statement_set_request_timeout(backend(), timeout_ms));
}

error statement::bind(size_t index, std::nullptr_t)
{
    return error(::cass_statement_bind_null(backend(), index));
}

error statement::bind_by_name(char const *name, std::nullptr_t)
{
    return error(::cass_statement_bind_null_by_name(backend(), name));
}

error statement::bind_by_name_n(
        char const *name, size_t name_length, std::nullptr_t)
{
    return error(::cass_statement_bind_null_by_name_n(
                backend(), name, name_length));
}

error statement::bind(size_t index, int8_t value)
{
    return error(::cass_statement_bind_int8(backend(), index, value));
}

error statement::bind_by_name(char const *name, int8_t value)
{
    return error(::cass_statement_bind_int8_by_name(backend(), name, value));
}

error statement::bind_by_name_n(char const *name,
        size_t name_length, int8_t value)
{
    return error(::cass_statement_bind_int8_by_name_n(
                backend(), name, name_length, value));
}

error statement::bind(size_t index, int16_t value)
{
    return error(::cass_statement_bind_int16(backend(), index, value));
}

error statement::bind_by_name(char const *name, int16_t value)
{
    return error(::cass_statement_bind_int16_by_name(backend(), name, value));
}

error statement::bind_by_name_n(char const *name,
        size_t name_length, int16_t value)
{
    return error(::cass_statement_bind_int16_by_name_n(
                backend(), name, name_length, value));
}

error statement::bind(size_t index, int32_t value)
{
    return error(::cass_statement_bind_int32(backend(), index, value));
}

error statement::bind_by_name(char const *name, int32_t value)
{
    return error(::cass_statement_bind_int32_by_name(backend(), name, value));
}

error statement::bind_by_name_n(char const *name,
        size_t name_length, int32_t value)
{
    return error(::cass_statement_bind_int32_by_name_n(
                backend(), name, name_length, value));
}

error statement::bind(size_t index, uint32_t value)
{
    return error(::cass_statement_bind_uint32(backend(), index, value));
}

error statement::bind_by_name(char const *name, uint32_t value)
{
    return error(::cass_statement_bind_uint32_by_name(backend(), name, value));
}

error statement::bind_by_name_n(char const *name,
        size_t name_length, uint32_t value)
{
    return error(::cass_statement_bind_uint32_by_name_n(
                backend(), name, name_length, value));
}

error statement::bind(size_t index, int64_t value)
{
    return error(::cass_statement_bind_int64(backend(), index, value));
}

error statement::bind_by_name(char const *name, int64_t value)
{
    return error(::cass_statement_bind_int64_by_name(backend(), name, value));
}

error statement::bind_by_name_n(char const *name,
        size_t name_length, int64_t value)
{
    return error(::cass_statement_bind_int64_by_name_n(
                backend(), name, name_length, value));
}

error statement::bind(size_t index, float value)
{
    return error(::cass_statement_bind_float(backend(), index, value));
}

error statement::bind_by_name(char const *name, float value)
{
    return error(::cass_statement_bind_float_by_name(backend(), name, value));
}

error statement::bind_by_name_n(char const *name,
        size_t name_length, float value)
{
    return error(::cass_statement_bind_float_by_name_n(
                backend(), name, name_length, value));
}

error statement::bind(size_t index, double value)
{
    return error(::cass_statement_bind_double(backend(), index, value));
}

error statement::bind_by_name(char const *name, double value)
{
    return error(::cass_statement_bind_double_by_name(backend(), name, value));
}

error statement::bind_by_name_n(char const *name,
        size_t name_length, double value)
{
    return error(::cass_statement_bind_double_by_name_n(
                backend(), name, name_length, value));
}

error statement::bind(size_t index, bool value)
{
    return error(::cass_statement_bind_bool(
                backend(), index, value ? cass_true : cass_false));
}

error statement::bind_by_name(char const *name, bool value)
{
    return error(::cass_statement_bind_bool_by_name(backend(), name,
            value ? cass_true : cass_false));
}

error statement::bind_by_name_n(char const *name,
        size_t name_length, bool value)
{
    return error(::cass_statement_bind_bool_by_name_n(
                backend(), name, name_length, value ? cass_true : cass_false));
}

error statement::bind(size_t index, char const *value)
{
    return error(::cass_statement_bind_string(backend(), index, value));
}

error statement::bind(size_t index, std::experimental::string_view s)
{
    return error(::cass_statement_bind_string_n(
                backend(), index, s.data(), s.size()));
}

error statement::bind_by_name(char const *name, char const *value)
{
    return error(::cass_statement_bind_string_by_name(backend(), name, value));
}

error statement::bind_by_name_n(char const *name, size_t name_length,
        std::experimental::string_view value)
{
    return error(::cass_statement_bind_string_by_name_n(
                backend(), name, name_length, value.data(), value.size()));
}

error statement::bind(size_t index, bytes_view value)
{
    return error(::cass_statement_bind_bytes(
                backend(), index, value.data(), value.size()));
}

error statement::bind_by_name(char const *name, bytes_view value)
{
    return error(::cass_statement_bind_bytes_by_name(
                backend(), name, value.data(), value.size()));
}

error statement::bind_by_name_n(char const *name,
        size_t name_length, bytes_view value)
{
    return error(::cass_statement_bind_bytes_by_name_n(
                backend(), name, name_length, value.data(), value.size()));
}

error statement::bind_custom(size_t index, char const *class_name,
        byte_t const *value, size_t value_size)
{
    return error(::cass_statement_bind_custom(
                backend(), index, class_name, value, value_size));
}

error statement::bind(size_t index, custom c)
{
    return error(::cass_statement_bind_custom_n(backend(), index,
                c.class_name.data(), c.class_name.size(),
                c.value.data(), c.value.size()));
}

error statement::bind_custom_by_name(char const *name,
        char const *class_name, byte_t const *value, size_t value_size)
{
    return error(::cass_statement_bind_custom_by_name(
                backend(), name, class_name, value, value_size));
}

error statement::bind_by_name_n(char const *name, size_t name_length,
        custom c)
{
    return error(::cass_statement_bind_custom_by_name_n(
                backend(), name, name_length,
                c.class_name.data(), c.class_name.size(),
                c.value.data(), c.value.size()));
}

error statement::bind(size_t index, uuid const &value)
{
    return error(::cass_statement_bind_uuid(backend(), index,
            *value.backend()));
}

error statement::bind_by_name(char const *name, uuid const &value)
{
    return error(::cass_statement_bind_uuid_by_name(backend(), name,
                *value.backend()));
}

error statement::bind_by_name_n(char const *name, size_t name_length,
        uuid const &value)
{
    return error(::cass_statement_bind_uuid_by_name_n(
                backend(), name, name_length, *value.backend()));
}

error statement::bind(size_t index, inet const &value)
{
    return (error)::cass_statement_bind_inet(backend(), index,
                *value.backend());
}

error statement::bind_by_name(char const *name, inet const &value)
{
    return (error)::cass_statement_bind_inet_by_name(backend(), name,
                *value.backend());
}

error statement::bind_by_name_n(char const *name,
        size_t name_length, inet const &value)
{
    return (error)::cass_statement_bind_inet_by_name_n(
                backend(), name, name_length, *value.backend());
}

error statement::bind(size_t index, decimal d)
{
    return error(::cass_statement_bind_decimal(
                backend(), index, d.varint, d.varint_size, d.scale));
}

error statement::bind_by_name(char const *name, decimal d)
{
    return error(::cass_statement_bind_decimal_by_name(
                backend(), name, d.varint, d.varint_size, d.scale));
}

error statement::bind_by_name_n(char const *name, size_t name_length,
        decimal d)
{
    return error(::cass_statement_bind_decimal_by_name_n(
            backend(), name, name_length, d.varint, d.varint_size, d.scale));
}

error statement::set_paging_state(cass::result const *result)
{
    return (error)::cass_statement_set_paging_state(
            backend(), result->backend());
}

error statement::set_retry_policy(cass::retry_policy *retry_policy)
{
    return (error)::cass_statement_set_retry_policy(backend(), retry_policy->backend());
}

error statement::set_custom_payload(custom_payload const *payload)
{
    return (error)::cass_statement_set_custom_payload(
            backend(), (payload ? payload->backend() : nullptr));
}

error statement::bind(size_t index,
        cass::collection const *collection)
{
    return (error)::cass_statement_bind_collection(
            backend(), index, collection->backend());
}

error statement::bind_by_name(char const *name,
        cass::collection const *collection)
{
    return (error)::cass_statement_bind_collection_by_name(backend(), name,
            collection->backend());
}

error statement::bind_by_name_n(char const *name,
        size_t name_length, cass::collection const *collection)
{
    return (error)::cass_statement_bind_collection_by_name_n(
            backend(), name, name_length, collection->backend());
}

error statement::bind(size_t index, cass::tuple const *tuple)
{
    return (error)::cass_statement_bind_tuple(
            backend(), index, tuple->backend());
}

error statement::bind_by_name(char const *name, cass::tuple const *tuple)
{
    return (error)::cass_statement_bind_tuple_by_name(
            backend(), name, tuple->backend());
}

error statement::bind_by_name_n(char const *name, size_t name_length,
        cass::tuple const *tuple)
{
    return (error)::cass_statement_bind_tuple_by_name_n(
            backend(), name, name_length, tuple->backend());
}

error statement::bind(size_t index, cass::user_type const *user_type)
{
    return (error)::cass_statement_bind_user_type(
            backend(), index, user_type->backend());
}

error statement::bind_by_name(char const *name,
        cass::user_type const *user_type)
{
    return (error)::cass_statement_bind_user_type_by_name(backend(), name,
            user_type->backend());
}

error statement::bind_by_name_n(char const *name, size_t name_length,
        cass::user_type const *user_type)
{
    return (error)::cass_statement_bind_user_type_by_name_n(
            backend(), name, name_length, user_type->backend());
}

template class wrapper_ptr<statement>;

} // namespace cass

/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include "delete_defaults.hpp"
#include "forward.hpp"
#include "impexp.hpp"

typedef struct CassStatement_ CassStatement;

namespace cass {

class CASSA_IMPEXP statement : delete_defaults {
public:
    static statement * ptr(::CassStatement *p);

    ::CassStatement * backend();
    ::CassStatement const * backend() const;

    void free();

    static statement_ptr new_ptr(char const *query,
            size_t parameter_count);
    static statement_ptr new_n_ptr(char const *query,
            size_t query_length, size_t parameter_count);

    error reset_parameters(size_t count);

    error add_key_index(size_t index);

    error set_keyspace(char const *keyspace);
    error set_keyspace_n(char const *keyspace, size_t keyspace_length);

    error set_consistency(cass::consistency consistency);

    error set_serial_consistency(cass::consistency serial_consistency);

    error set_paging_size(int page_size);

    error set_paging_state(cass::result const *result);

    error set_paging_state_token(char const *paging_state,
            size_t paging_state_size);

    error set_timestamp(int64_t timestamp);

    error set_request_timeout(uint64_t timeout_ms);

    error set_retry_policy(cass::retry_policy *retry_policy);

    error set_custom_payload(custom_payload const *payload);

    error bind(size_t index, std::nullptr_t);
    error bind_by_name(char const *name, std::nullptr_t);
    error bind_by_name_n(char const *name, size_t name_length,
            std::nullptr_t);

    error bind(size_t index, int8_t value);
    error bind_by_name(char const *name, int8_t value);
    error bind_by_name_n(char const *name, size_t name_length,
            int8_t value);

    error bind(size_t index, int16_t value);
    error bind_by_name(char const *name, int16_t value);
    error bind_by_name_n(char const *name, size_t name_length,
            int16_t value);

    error bind(size_t index, int32_t value);
    error bind_by_name(char const *name, int32_t value);
    error bind_by_name_n(char const *name, size_t name_length,
            int32_t value);

    error bind(size_t index, uint32_t value);
    error bind_by_name(char const *name, uint32_t value);
    error bind_by_name_n(char const *name, size_t name_length,
            uint32_t value);

    error bind(size_t index, int64_t value);
    error bind_by_name(char const *name, int64_t value);
    error bind_by_name_n(char const *name, size_t name_length,
            int64_t value);

    error bind(size_t index, float value);
    error bind_by_name(char const *name, float value);
    error bind_by_name_n(char const *name, size_t name_length,
            float value);

    error bind(size_t index, double value);
    error bind_by_name(char const *name, double value);
    error bind_by_name_n(char const *name, size_t name_length,
            double value);

    error bind(size_t index, bool value);
    error bind_by_name(char const *name, bool value);
    error bind_by_name_n(char const *name, size_t name_length,
            bool value);

    error bind(size_t index, char const *value);
    error bind(size_t index, std::string_view s);
    error bind_by_name(char const *name, char const *value);
    error bind_by_name_n(char const *name, size_t name_length,
            std::string_view value);

    error bind(size_t index, bytes_view value);
    error bind_by_name(char const *name, bytes_view value);
    error bind_by_name_n(char const *name, size_t name_length,
            bytes_view value);

    error bind(size_t index, custom c);
    error bind_by_name_n(char const *name, size_t name_length, custom c);

    error bind(size_t index, uuid const &value);
    error bind_by_name(char const *name, uuid const &value);
    error bind_by_name_n(char const *name, size_t name_length,
            uuid const &value);

    error bind(size_t index, inet const &value);
    error bind_by_name(char const *name, inet const &value);
    error bind_by_name_n(char const *name, size_t name_length,
            inet const &value);

    error bind(size_t index, decimal d);
    error bind_by_name(char const *name, decimal d);
    error bind_by_name_n(char const *name, size_t name_length,
            decimal d);

    error bind(size_t index, cass::collection const *collection);
    error bind_by_name(char const *name,
            cass::collection const *collection);
    error bind_by_name_n(char const *name,
            size_t name_length, cass::collection const *collection);

    error bind(size_t index, cass::tuple const *tuple);
    error bind_by_name(char const *name, cass::tuple const *tuple);
    error bind_by_name_n(char const *name,
            size_t name_length, cass::tuple const *tuple);

    error bind(size_t index, cass::user_type const *user_type);
    error bind_by_name(char const *name,
            cass::user_type const *user_type);
    error bind_by_name_n(char const *name,
            size_t name_length, cass::user_type const *user_type);

    template<typename T>
    error bind_by_name(std::string_view name, T value)
    {
        return bind_by_name_n(name.data(), name.size(), value);
    }

    error bind_custom(size_t index, char const *class_name,
            std::byte const *value, size_t value_size);
    error bind_custom_by_name(char const *name, char const *class_name,
            std::byte const *value, size_t value_size);
};

} // namespace cass

/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cstddef>
#include <cstdint>
#include <experimental/string_view>

#include <cassandra.h>

#include <cass/wrapper_ptr.hpp>

namespace cass {

typedef ::cass_byte_t byte_t;
typedef std::experimental::basic_string_view<byte_t> bytes_view;

typedef ::cass_duration_t duration_t;

class inet;

class uuid;

class cluster;

class session;

class statement;
typedef wrapper_ptr<statement> statement_ptr;

class batch;

class future;

class prepared;
typedef wrapper_ptr<prepared const> prepared_const_ptr;

class result;
typedef wrapper_ptr<result const> result_const_ptr;

class error_result;
typedef wrapper_ptr<error_result const> error_result_const_ptr;

class iterator;

class row;

class value;

class data_type;
typedef wrapper_ptr<data_type> data_type_ptr;

class function_meta;

class aggregate_meta;

class collection;

class tuple;

class user_type;

class ssl;

typedef ::CassVersion version;

class schema_meta;
typedef wrapper_ptr<schema_meta const> schema_meta_const_ptr;

class keyspace_meta;

class table_meta;

class materialized_view_meta;

class column_meta;

class index_meta;

class uuid_gen;

class timestamp_gen;

class retry_policy;

class custom_payload;

typedef ::CassMetrics metrics;

typedef ::CassConsistency consistency;

typedef ::CassWriteType write_type;

typedef ::CassColumnType column_type;

typedef ::CassIndexType index_type;

typedef ::CassValueType value_type;

typedef ::CassClusteringOrder clustering_order;

typedef ::CassCollectionType colletion_type;

typedef ::CassBatchType batch_type;

typedef ::CassIteratorType iterator_type;

typedef ::CassLogLevel log_level;

typedef ::CassSslVerifyFlags ssl_verify_flags;

typedef ::CassErrorSource error_source;

enum error : int {
    OK                                     = ::CASS_OK,
    ERROR_LIB_BAD_PARAMS                   = ::CASS_ERROR_LIB_BAD_PARAMS,
    ERROR_LIB_NO_STREAMS                   = ::CASS_ERROR_LIB_NO_STREAMS,
    ERROR_LIB_UNABLE_TO_INIT               = ::CASS_ERROR_LIB_UNABLE_TO_INIT,
    ERROR_LIB_MESSAGE_ENCODE               = ::CASS_ERROR_LIB_MESSAGE_ENCODE,
    ERROR_LIB_HOST_RESOLUTION              = ::CASS_ERROR_LIB_HOST_RESOLUTION,
    ERROR_LIB_UNEXPECTED_RESPONSE          = ::CASS_ERROR_LIB_UNEXPECTED_RESPONSE,
    ERROR_LIB_REQUEST_QUEUE_FULL           = ::CASS_ERROR_LIB_REQUEST_QUEUE_FULL,
    ERROR_LIB_NO_AVAILABLE_IO_THREAD       = ::CASS_ERROR_LIB_NO_AVAILABLE_IO_THREAD,
    ERROR_LIB_WRITE_ERROR                  = ::CASS_ERROR_LIB_WRITE_ERROR,
    ERROR_LIB_NO_HOSTS_AVAILABLE           = ::CASS_ERROR_LIB_NO_HOSTS_AVAILABLE,
    ERROR_LIB_INDEX_OUT_OF_BOUNDS          = ::CASS_ERROR_LIB_INDEX_OUT_OF_BOUNDS,
    ERROR_LIB_INVALID_ITEM_COUNT           = ::CASS_ERROR_LIB_INVALID_ITEM_COUNT,
    ERROR_LIB_INVALID_VALUE_TYPE           = ::CASS_ERROR_LIB_INVALID_VALUE_TYPE,
    ERROR_LIB_REQUEST_TIMED_OUT            = ::CASS_ERROR_LIB_REQUEST_TIMED_OUT,
    ERROR_LIB_UNABLE_TO_SET_KEYSPACE       = ::CASS_ERROR_LIB_UNABLE_TO_SET_KEYSPACE,
    ERROR_LIB_CALLBACK_ALREADY_SET         = ::CASS_ERROR_LIB_CALLBACK_ALREADY_SET,
    ERROR_LIB_INVALID_STATEMENT_TYPE       = ::CASS_ERROR_LIB_INVALID_STATEMENT_TYPE,
    ERROR_LIB_NAME_DOES_NOT_EXIST          = ::CASS_ERROR_LIB_NAME_DOES_NOT_EXIST,
    ERROR_LIB_UNABLE_TO_DETERMINE_PROTOCOL = ::CASS_ERROR_LIB_UNABLE_TO_DETERMINE_PROTOCOL,
    ERROR_LIB_NULL_VALUE                   = ::CASS_ERROR_LIB_NULL_VALUE,
    ERROR_LIB_NOT_IMPLEMENTED              = ::CASS_ERROR_LIB_NOT_IMPLEMENTED,
    ERROR_LIB_UNABLE_TO_CONNECT            = ::CASS_ERROR_LIB_UNABLE_TO_CONNECT,
    ERROR_LIB_UNABLE_TO_CLOSE              = ::CASS_ERROR_LIB_UNABLE_TO_CLOSE,
    ERROR_LIB_NO_PAGING_STATE              = ::CASS_ERROR_LIB_NO_PAGING_STATE,
    ERROR_LIB_PARAMETER_UNSET              = ::CASS_ERROR_LIB_PARAMETER_UNSET,
    ERROR_LIB_INVALID_ERROR_RESULT_TYPE    = ::CASS_ERROR_LIB_INVALID_ERROR_RESULT_TYPE,
    ERROR_LIB_INVALID_FUTURE_TYPE          = ::CASS_ERROR_LIB_INVALID_FUTURE_TYPE,
    ERROR_LIB_INTERNAL_ERROR               = ::CASS_ERROR_LIB_INTERNAL_ERROR,
    ERROR_LIB_INVALID_CUSTOM_TYPE          = ::CASS_ERROR_LIB_INVALID_CUSTOM_TYPE,
    ERROR_LIB_INVALID_DATA                 = ::CASS_ERROR_LIB_INVALID_DATA,
    ERROR_LIB_NOT_ENOUGH_DATA              = ::CASS_ERROR_LIB_NOT_ENOUGH_DATA,
    ERROR_LIB_INVALID_STATE                = ::CASS_ERROR_LIB_INVALID_STATE,
    ERROR_LIB_NO_CUSTOM_PAYLOAD            = ::CASS_ERROR_LIB_NO_CUSTOM_PAYLOAD,
    ERROR_SERVER_SERVER_ERROR              = ::CASS_ERROR_SERVER_SERVER_ERROR,
    ERROR_SERVER_PROTOCOL_ERROR            = ::CASS_ERROR_SERVER_PROTOCOL_ERROR,
    ERROR_SERVER_BAD_CREDENTIALS           = ::CASS_ERROR_SERVER_BAD_CREDENTIALS,
    ERROR_SERVER_UNAVAILABLE               = ::CASS_ERROR_SERVER_UNAVAILABLE,
    ERROR_SERVER_OVERLOADED                = ::CASS_ERROR_SERVER_OVERLOADED,
    ERROR_SERVER_IS_BOOTSTRAPPING          = ::CASS_ERROR_SERVER_IS_BOOTSTRAPPING,
    ERROR_SERVER_TRUNCATE_ERROR            = ::CASS_ERROR_SERVER_TRUNCATE_ERROR,
    ERROR_SERVER_WRITE_TIMEOUT             = ::CASS_ERROR_SERVER_WRITE_TIMEOUT,
    ERROR_SERVER_READ_TIMEOUT              = ::CASS_ERROR_SERVER_READ_TIMEOUT,
    ERROR_SERVER_READ_FAILURE              = ::CASS_ERROR_SERVER_READ_FAILURE,
    ERROR_SERVER_FUNCTION_FAILURE          = ::CASS_ERROR_SERVER_FUNCTION_FAILURE,
    ERROR_SERVER_WRITE_FAILURE             = ::CASS_ERROR_SERVER_WRITE_FAILURE,
    ERROR_SERVER_SYNTAX_ERROR              = ::CASS_ERROR_SERVER_SYNTAX_ERROR,
    ERROR_SERVER_UNAUTHORIZED              = ::CASS_ERROR_SERVER_UNAUTHORIZED,
    ERROR_SERVER_INVALID_QUERY             = ::CASS_ERROR_SERVER_INVALID_QUERY,
    ERROR_SERVER_CONFIG_ERROR              = ::CASS_ERROR_SERVER_CONFIG_ERROR,
    ERROR_SERVER_ALREADY_EXISTS            = ::CASS_ERROR_SERVER_ALREADY_EXISTS,
    ERROR_SERVER_UNPREPARED                = ::CASS_ERROR_SERVER_UNPREPARED,
    ERROR_SSL_INVALID_CERT                 = ::CASS_ERROR_SSL_INVALID_CERT,
    ERROR_SSL_INVALID_PRIVATE_KEY          = ::CASS_ERROR_SSL_INVALID_PRIVATE_KEY,
    ERROR_SSL_NO_PEER_CERT                 = ::CASS_ERROR_SSL_NO_PEER_CERT,
    ERROR_SSL_INVALID_PEER_CERT            = ::CASS_ERROR_SSL_INVALID_PEER_CERT,
    ERROR_SSL_IDENTITY_MISMATCH            = ::CASS_ERROR_SSL_IDENTITY_MISMATCH,
    ERROR_SSL_PROTOCOL_ERROR               = ::CASS_ERROR_SSL_PROTOCOL_ERROR,
    ERROR_LAST_ENTRY                       = ::CASS_ERROR_LAST_ENTRY
};

typedef ::CassLogMessage log_message;

class authenticator;

typedef ::CassLogCallback log_callback;

struct custom {
    std::experimental::string_view class_name;
    bytes_view value;
    custom(std::experimental::string_view class_name, bytes_view value) :
            class_name(class_name), value(value) {}
};

struct decimal {
    byte_t const *varint;
    size_t varint_size;
    int32_t scale;
    decimal(byte_t const *varint, size_t varint_size, int32_t scale) :
        varint(varint), varint_size(varint_size), scale(scale) {}
};

} // namespace cass

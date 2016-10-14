/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cstddef>
#include <cstdint>

#include <cassandra.h>

#include <cass/wrapper_ptr.hpp>

namespace cass {

typedef ::cass_byte_t byte_t;

typedef ::cass_duration_t duration_t;

class inet;

class uuid;

class cluster;

class session;

class statement;
typedef wrapper_ptr<class statement> statement_ptr;

class batch;

class future;

class prepared;
typedef wrapper_const_ptr<class prepared const> prepared_const_ptr;

class result;
typedef wrapper_const_ptr<result const> result_const_ptr;

class error_result;
typedef wrapper_ptr<class error_result const> error_result_const_ptr;

class iterator;

class row;
typedef dummy_ptr<class row const> row_const_ptr;

class value;
typedef dummy_ptr<class value const> value_const_ptr;

class data_type;
typedef wrapper_ptr<data_type> data_type_ptr;
typedef wrapper_const_ptr<data_type const> data_type_const_ptr;

class function_meta;
typedef dummy_ptr<function_meta const> function_meta_const_ptr;

class aggregate_meta;
typedef dummy_ptr<class aggregate_meta const> aggregate_meta_const_ptr;

class collection;

class tuple;

class user_type;

class ssl;

typedef ::CassVersion version;

class schema_meta;
typedef wrapper_const_ptr<class schema_meta const> schema_meta_const_ptr;

class keyspace_meta;
typedef dummy_ptr<class keyspace_meta const> keyspace_meta_const_ptr;

class table_meta;
typedef dummy_ptr<class table_meta const> table_meta_const_ptr;

class materialized_view_meta;
typedef dummy_ptr<class materialized_view_meta const>
    materialized_view_meta_const_ptr;

class column_meta;
typedef dummy_ptr<class column_meta const> column_meta_const_ptr;

class index_meta;
typedef dummy_ptr<class index_meta const> index_meta_const_ptr;

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

#define CASS_ERROR_FOREACH(XX) \
    XX(OK)\
    XX(ERROR_LIB_BAD_PARAMS)\
    XX(ERROR_LIB_NO_STREAMS)\
    XX(ERROR_LIB_UNABLE_TO_INIT)\
    XX(ERROR_LIB_MESSAGE_ENCODE)\
    XX(ERROR_LIB_HOST_RESOLUTION)\
    XX(ERROR_LIB_UNEXPECTED_RESPONSE)\
    XX(ERROR_LIB_REQUEST_QUEUE_FULL)\
    XX(ERROR_LIB_NO_AVAILABLE_IO_THREAD)\
    XX(ERROR_LIB_WRITE_ERROR)\
    XX(ERROR_LIB_NO_HOSTS_AVAILABLE)\
    XX(ERROR_LIB_INDEX_OUT_OF_BOUNDS)\
    XX(ERROR_LIB_INVALID_ITEM_COUNT)\
    XX(ERROR_LIB_INVALID_VALUE_TYPE)\
    XX(ERROR_LIB_REQUEST_TIMED_OUT)\
    XX(ERROR_LIB_UNABLE_TO_SET_KEYSPACE)\
    XX(ERROR_LIB_CALLBACK_ALREADY_SET)\
    XX(ERROR_LIB_INVALID_STATEMENT_TYPE)\
    XX(ERROR_LIB_NAME_DOES_NOT_EXIST)\
    XX(ERROR_LIB_UNABLE_TO_DETERMINE_PROTOCOL)\
    XX(ERROR_LIB_NULL_VALUE)\
    XX(ERROR_LIB_NOT_IMPLEMENTED)\
    XX(ERROR_LIB_UNABLE_TO_CONNECT)\
    XX(ERROR_LIB_UNABLE_TO_CLOSE)\
    XX(ERROR_LIB_NO_PAGING_STATE)\
    XX(ERROR_LIB_PARAMETER_UNSET)\
    XX(ERROR_LIB_INVALID_ERROR_RESULT_TYPE)\
    XX(ERROR_LIB_INVALID_FUTURE_TYPE)\
    XX(ERROR_LIB_INTERNAL_ERROR)\
    XX(ERROR_LIB_INVALID_CUSTOM_TYPE)\
    XX(ERROR_LIB_INVALID_DATA)\
    XX(ERROR_LIB_NOT_ENOUGH_DATA)\
    XX(ERROR_LIB_INVALID_STATE)\
    XX(ERROR_LIB_NO_CUSTOM_PAYLOAD)\
    XX(ERROR_SERVER_SERVER_ERROR)\
    XX(ERROR_SERVER_PROTOCOL_ERROR)\
    XX(ERROR_SERVER_BAD_CREDENTIALS)\
    XX(ERROR_SERVER_UNAVAILABLE)\
    XX(ERROR_SERVER_OVERLOADED)\
    XX(ERROR_SERVER_IS_BOOTSTRAPPING)\
    XX(ERROR_SERVER_TRUNCATE_ERROR)\
    XX(ERROR_SERVER_WRITE_TIMEOUT)\
    XX(ERROR_SERVER_READ_TIMEOUT)\
    XX(ERROR_SERVER_READ_FAILURE)\
    XX(ERROR_SERVER_FUNCTION_FAILURE)\
    XX(ERROR_SERVER_WRITE_FAILURE)\
    XX(ERROR_SERVER_SYNTAX_ERROR)\
    XX(ERROR_SERVER_UNAUTHORIZED)\
    XX(ERROR_SERVER_INVALID_QUERY)\
    XX(ERROR_SERVER_CONFIG_ERROR)\
    XX(ERROR_SERVER_ALREADY_EXISTS)\
    XX(ERROR_SERVER_UNPREPARED)\
    XX(ERROR_SSL_INVALID_CERT)\
    XX(ERROR_SSL_INVALID_PRIVATE_KEY)\
    XX(ERROR_SSL_NO_PEER_CERT)\
    XX(ERROR_SSL_INVALID_PEER_CERT)\
    XX(ERROR_SSL_IDENTITY_MISMATCH)\
    XX(ERROR_SSL_PROTOCOL_ERROR)\
    XX(ERROR_LAST_ENTRY)\

enum error : int {
#define XX(name) name = ::CASS_##name,
    CASS_ERROR_FOREACH(XX)
#undef XX
};

typedef ::CassLogMessage log_message;

class authenticator;

typedef ::CassLogCallback log_callback;

} // namespace cass

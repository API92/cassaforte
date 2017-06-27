/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cstddef>
#include <cstdint>
#include <string_view>

#include "impexp.hpp"
#include "wrapper_ptr.hpp"

typedef struct CassVersion_ CassVersion;

typedef struct CassMetrics_ CassMetrics;

typedef struct CassLogMessage_ CassLogMessage;

typedef void (*CassLogCallback)(CassLogMessage const *message, void *data);

namespace cass {

typedef std::basic_string_view<std::byte> bytes_view;

typedef uint64_t duration_t;

typedef int64_t timestamp_t;

class inet;

class uuid;

class cluster;
typedef wrapper_ptr<cluster> cluster_ptr;
extern template class CASSA_IMPEXP wrapper_ptr<cluster>;

class session;
typedef wrapper_ptr<session> session_ptr;
extern template class CASSA_IMPEXP wrapper_ptr<session>;

class statement;
typedef wrapper_ptr<statement> statement_ptr;
extern template class CASSA_IMPEXP wrapper_ptr<statement>;

class batch;
typedef wrapper_ptr<batch> batch_ptr;
extern template class CASSA_IMPEXP wrapper_ptr<batch>;

class future;
typedef wrapper_ptr<future> future_ptr;
extern template class CASSA_IMPEXP wrapper_ptr<future>;

class prepared;
typedef wrapper_ptr<prepared const> prepared_const_ptr;
extern template class CASSA_IMPEXP wrapper_ptr<prepared const>;

class result;
typedef wrapper_ptr<result const> result_const_ptr;
extern template class CASSA_IMPEXP wrapper_ptr<result const>;

class error_result;
typedef wrapper_ptr<error_result const> error_result_const_ptr;
extern template class CASSA_IMPEXP wrapper_ptr<error_result const>;

class iterator;
typedef wrapper_ptr<iterator> iterator_ptr;
extern template class CASSA_IMPEXP wrapper_ptr<iterator>;

class row;

class value;

class data_type;
typedef wrapper_ptr<data_type> data_type_ptr;
extern template class CASSA_IMPEXP wrapper_ptr<data_type>;

class function_meta;

class aggregate_meta;

class collection;
typedef wrapper_ptr<collection> collection_ptr;
extern template class CASSA_IMPEXP wrapper_ptr<collection>;

class tuple;
typedef wrapper_ptr<tuple> tuple_ptr;
extern template class CASSA_IMPEXP wrapper_ptr<tuple>;

class user_type;
typedef wrapper_ptr<user_type> user_type_ptr;
extern template class CASSA_IMPEXP wrapper_ptr<user_type>;

class ssl;
typedef wrapper_ptr<ssl> ssl_ptr;
extern template class CASSA_IMPEXP wrapper_ptr<ssl>;

typedef ::CassVersion version;

class schema_meta;
typedef wrapper_ptr<schema_meta const> schema_meta_const_ptr;
extern template class CASSA_IMPEXP wrapper_ptr<schema_meta const>;

class keyspace_meta;

class table_meta;

class materialized_view_meta;

class column_meta;

class index_meta;

class uuid_gen;
typedef wrapper_ptr<uuid_gen> uuid_gen_ptr;
extern template class CASSA_IMPEXP wrapper_ptr<uuid_gen>;

class timestamp_gen;
typedef wrapper_ptr<timestamp_gen> timestamp_gen_ptr;
extern template class CASSA_IMPEXP wrapper_ptr<timestamp_gen>;

class retry_policy;
typedef wrapper_ptr<retry_policy> retry_policy_ptr;
extern template class CASSA_IMPEXP wrapper_ptr<retry_policy>;

class custom_payload;
typedef wrapper_ptr<custom_payload> custom_payload_ptr;
extern template class CASSA_IMPEXP wrapper_ptr<custom_payload>;

typedef ::CassMetrics metrics;

enum class consistency : int;

enum class write_type : int;

enum class column_type : int;

enum class index_type : int;

enum class value_type : int;

enum class clustering_order : int;

enum class collection_type : int;

enum class batch_type : int;

enum class iterator_type : int;

enum class log_level : int;

enum class ssl_verify_flags : int;

enum class error_source : int;

enum class error : int;

typedef ::CassLogMessage log_message;

class authenticator;

typedef ::CassLogCallback log_callback;

struct custom;

struct decimal;

} // namespace cass

/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cstddef>
#include <cstdint>

#include <cassandra.h>

namespace cass {

typedef ::CassInet inet;

typedef ::CassUuid uuid;

class cluster;

class session;

class statement;

class batch;

class future;

class prepared;

class result;

class error_result;

class iterator;

class row;

class value;

class data_type;

class function_meta;

class aggregate_meta;

class collection;

class tuple;

class user_type;

class ssl;

typedef ::CassVersion version;

class schema_meta;
class schema_meta_const_ptr;

class keyspace_meta;
class keyspace_meta_const_ptr;

class table_meta;
class table_meta_const_ptr;

class materialized_view_meta;
class materialized_view_meta_const_ptr;

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

typedef ::CassError error;

typedef ::CassLogMessage log_message;

class authenticator;

} // namespace cass

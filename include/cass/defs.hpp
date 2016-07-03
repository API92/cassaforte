/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cstddef>
#include <cstdint>

#include <cassandra.h>

#include <cass/wrapper_ptr.hpp>

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

typedef ::CassError error;

typedef ::CassLogMessage log_message;

class authenticator;

} // namespace cass
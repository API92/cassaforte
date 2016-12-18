/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

namespace cass {

enum class consistency : int {
    UNKNOWN      = 0xFFFF,
    ANY          = 0x0000,
    ONE          = 0x0001,
    TWO          = 0x0002,
    THREE        = 0x0003,
    QUORUM       = 0x0004,
    ALL          = 0x0005,
    LOCAL_QUORUM = 0x0006,
    EACH_QUORUM  = 0x0007,
    SERIAL       = 0x0008,
    LOCAL_SERIAL = 0x0009,
    LOCAL_ONE    = 0x000A
};

enum class write_type : int {
    UKNOWN,
    SIMPLE,
    BATCH,
    UNLOGGED_BATCH,
    COUNTER,
    BATCH_LOG,
    CAS,
};

enum class column_type : int {
    REGULAR,
    PARTITION_KEY,
    CLUSTERING_KEY,
    STATIC,
    COMPACT_VALUE,
};

enum class index_type : int {
    UNKNOWN,
    KEYS,
    CUSTOM,
    COMPOSITES,
};

enum class value_type : int {
    UNKNOWN    = 0xFFFF,
    CUSTOM     = 0x0000,
    ASCII      = 0x0001,
    BIGINT     = 0x0002,
    BLOB       = 0x0003,
    BOOLEAN    = 0x0004,
    COUNTER    = 0x0005,
    DECIMAL    = 0x0006,
    DOUBLE     = 0x0007,
    FLOAT      = 0x0008,
    INT        = 0x0009,
    TEXT       = 0x000A,
    TIMESTAMP  = 0x000B,
    UUID       = 0x000C,
    VARCHAR    = 0x000D,
    VARINT     = 0x000E,
    TIMEUUID   = 0x000F,
    INET       = 0x0010,
    DATE       = 0x0011,
    TIME       = 0x0012,
    SMALL_INT  = 0x0013,
    TINY_INT   = 0x0014,
    LIST       = 0x0020,
    MAP        = 0x0021,
    SET        = 0x0022,
    UDT        = 0x0030,
    TUPLE      = 0x0031,
    LAST_ENTRY
};

enum class clustering_order : int {
    NONE,
    ASC,
    DESC,
};

enum class collection_type : int {
    LIST = (int)value_type::LIST,
    MAP  = (int)value_type::MAP,
    SET  = (int)value_type::SET
};

enum class batch_type : int {
  LOGGED   = 0x00,
  UNLOGGED = 0x01,
  COUNTER  = 0x02
};

enum class iterator_type : int {
    RESULT,
    ROW,
    COLLECTION,
    MAP,
    TUPLE,
    USER_TYPE_FIELD,
    META_FIELD,
    KEYSPACE_META,
    TABLE_META,
    TYPE_META,
    FUNCTION_META,
    AGGREGATE_META,
    COLUMN_META,
    INDEX_META,
    MATERIALIZED_VIEW_META,
};

enum class log_level : int {
    DISABLED,
    CRITICAL,
    ERROR,
    WARN,
    INFO,
    DEBUG,
    TRACE,
    LAST_ENTRY,
};

enum class ssl_verify_flags : int {
    NONE              = 0x00,
    PEER_CERT         = 0x01,
    PEER_IDENTITY     = 0x02,
    PEER_IDENTITY_DNS = 0x04
};

enum class error_source : int {
    NONE,
    LIB,
    SERVER,
    SSL,
    COMPRESSION,
};

enum class error : int {
    OK                               = 0,
    LIB_BAD_PARAMS                   = ((int)error_source::LIB << 24) | 1,
    LIB_NO_STREAMS                   = ((int)error_source::LIB << 24) | 2,
    LIB_UNABLE_TO_INIT               = ((int)error_source::LIB << 24) | 3,
    LIB_MESSAGE_ENCODE               = ((int)error_source::LIB << 24) | 4,
    LIB_HOST_RESOLUTION              = ((int)error_source::LIB << 24) | 5,
    LIB_UNEXPECTED_RESPONSE          = ((int)error_source::LIB << 24) | 6,
    LIB_REQUEST_QUEUE_FULL           = ((int)error_source::LIB << 24) | 7,
    LIB_NO_AVAILABLE_IO_THREAD       = ((int)error_source::LIB << 24) | 8,
    LIB_WRITE_ERROR                  = ((int)error_source::LIB << 24) | 9,
    LIB_NO_HOSTS_AVAILABLE           = ((int)error_source::LIB << 24) | 10,
    LIB_INDEX_OUT_OF_BOUNDS          = ((int)error_source::LIB << 24) | 11,
    LIB_INVALID_ITEM_COUNT           = ((int)error_source::LIB << 24) | 12,
    LIB_INVALID_VALUE_TYPE           = ((int)error_source::LIB << 24) | 13,
    LIB_REQUEST_TIMED_OUT            = ((int)error_source::LIB << 24) | 14,
    LIB_UNABLE_TO_SET_KEYSPACE       = ((int)error_source::LIB << 24) | 15,
    LIB_CALLBACK_ALREADY_SET         = ((int)error_source::LIB << 24) | 16,
    LIB_INVALID_STATEMENT_TYPE       = ((int)error_source::LIB << 24) | 17,
    LIB_NAME_DOES_NOT_EXIST          = ((int)error_source::LIB << 24) | 18,
    LIB_UNABLE_TO_DETERMINE_PROTOCOL = ((int)error_source::LIB << 24) | 19,
    LIB_NULL_VALUE                   = ((int)error_source::LIB << 24) | 20,
    LIB_NOT_IMPLEMENTED              = ((int)error_source::LIB << 24) | 21,
    LIB_UNABLE_TO_CONNECT            = ((int)error_source::LIB << 24) | 22,
    LIB_UNABLE_TO_CLOSE              = ((int)error_source::LIB << 24) | 23,
    LIB_NO_PAGING_STATE              = ((int)error_source::LIB << 24) | 24,
    LIB_PARAMETER_UNSET              = ((int)error_source::LIB << 24) | 25,
    LIB_INVALID_ERROR_RESULT_TYPE    = ((int)error_source::LIB << 24) | 26,
    LIB_INVALID_FUTURE_TYPE          = ((int)error_source::LIB << 24) | 27,
    LIB_INTERNAL_ERROR               = ((int)error_source::LIB << 24) | 28,
    LIB_INVALID_CUSTOM_TYPE          = ((int)error_source::LIB << 24) | 29,
    LIB_INVALID_DATA                 = ((int)error_source::LIB << 24) | 30,
    LIB_NOT_ENOUGH_DATA              = ((int)error_source::LIB << 24) | 31,
    LIB_INVALID_STATE                = ((int)error_source::LIB << 24) | 32,
    LIB_NO_CUSTOM_PAYLOAD            = ((int)error_source::LIB << 24) | 33,
    SERVER_SERVER_ERROR              = ((int)error_source::SERVER << 24) | 0x0000,
    SERVER_PROTOCOL_ERROR            = ((int)error_source::SERVER << 24) | 0x000A,
    SERVER_BAD_CREDENTIALS           = ((int)error_source::SERVER << 24) | 0x0100,
    SERVER_UNAVAILABLE               = ((int)error_source::SERVER << 24) | 0x1000,
    SERVER_OVERLOADED                = ((int)error_source::SERVER << 24) | 0x1001,
    SERVER_IS_BOOTSTRAPPING          = ((int)error_source::SERVER << 24) | 0x1002,
    SERVER_TRUNCATE_ERROR            = ((int)error_source::SERVER << 24) | 0x1003,
    SERVER_WRITE_TIMEOUT             = ((int)error_source::SERVER << 24) | 0x1100,
    SERVER_READ_TIMEOUT              = ((int)error_source::SERVER << 24) | 0x1200,
    SERVER_READ_FAILURE              = ((int)error_source::SERVER << 24) | 0x1300,
    SERVER_FUNCTION_FAILURE          = ((int)error_source::SERVER << 24) | 0x1400,
    SERVER_WRITE_FAILURE             = ((int)error_source::SERVER << 24) | 0x1500,
    SERVER_SYNTAX_ERROR              = ((int)error_source::SERVER << 24) | 0x2000,
    SERVER_UNAUTHORIZED              = ((int)error_source::SERVER << 24) | 0x2100,
    SERVER_INVALID_QUERY             = ((int)error_source::SERVER << 24) | 0x2200,
    SERVER_CONFIG_ERROR              = ((int)error_source::SERVER << 24) | 0x2300,
    SERVER_ALREADY_EXISTS            = ((int)error_source::SERVER << 24) | 0x2400,
    SERVER_UNPREPARED                = ((int)error_source::SERVER << 24) | 0x2500,
    SSL_INVALID_CERT                 = ((int)error_source::SSL << 24) | 1,
    SSL_INVALID_PRIVATE_KEY          = ((int)error_source::SSL << 24) | 2,
    SSL_NO_PEER_CERT                 = ((int)error_source::SSL << 24) | 3,
    SSL_INVALID_PEER_CERT            = ((int)error_source::SSL << 24) | 4,
    SSL_IDENTITY_MISMATCH            = ((int)error_source::SSL << 24) | 5,
    SSL_PROTOCOL_ERROR               = ((int)error_source::SSL << 24) | 6,
    LAST_ENTRY
};

} // namespace cass

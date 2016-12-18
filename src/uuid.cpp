/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/uuid.hpp>

#include <cstring>

#include <cassandra.h>

namespace cass {

::CassUuid * uuid::backend()
{
    static_assert(sizeof(uuid) == sizeof(::CassUuid), "Bad size.");
    static_assert(alignof(uuid) == alignof(::CassUuid), "Bad alignment.");
    return reinterpret_cast<::CassUuid *>(this);
}

::CassUuid const * uuid::backend() const
{
    return reinterpret_cast<::CassUuid const *>(this);
}

void uuid::min_from_time(uint64_t time, uuid *output)
{
    ::cass_uuid_min_from_time(time, output->backend());
}

void uuid::max_from_time(uint64_t time, uuid *output)
{
    ::cass_uuid_max_from_time(time, output->backend());
}

uint64_t uuid::timestamp() const
{
    return ::cass_uuid_timestamp(*backend());
}

uint8_t uuid::version() const
{
    return ::cass_uuid_version(*backend());
}

void uuid::string(char *output) const
{
    ::cass_uuid_string(*backend(), output);
}

error uuid::from_string(char const *str)
{
    return error(::cass_uuid_from_string(str, backend()));
}

error uuid::from_string_n(char const *str, size_t str_length)
{
    return error(::cass_uuid_from_string_n(str, str_length, backend()));
}

bool operator < (uuid const &lhs, uuid const &rhs)
{
    char lhs_data[36], rhs_data[36];
    lhs.string(lhs_data);
    rhs.string(rhs_data);
    return memcmp(lhs_data, rhs_data, sizeof(lhs_data)) < 0;
}

bool uuid::operator == (uuid const &rhs) const
{
    return time_and_version == rhs.time_and_version &&
           clock_seq_and_node == rhs.clock_seq_and_node;
}


} // namespace cass

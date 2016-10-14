/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/defs.hpp>

namespace cass {

class uuid : public ::CassUuid {
public:
    inline static void min_from_time(uint64_t time, uuid *output);

    inline static void max_from_time(uint64_t time, uuid *output);

    inline uint64_t timestamp() const;

    inline uint8_t version() const;

    inline void string(char *output) const;

    inline error from_string(char const *str);
    inline error from_string_n(char const *str, size_t str_length);
};

inline void uuid::min_from_time(uint64_t time, uuid *output)
{
    ::cass_uuid_min_from_time(time, output);
}

inline void uuid::max_from_time(uint64_t time, uuid *output)
{
    ::cass_uuid_max_from_time(time, output);
}

inline uint64_t uuid::timestamp() const
{
    return ::cass_uuid_timestamp(*this);
}

inline uint8_t uuid::version() const
{
    return ::cass_uuid_version(*this);
}

inline void uuid::string(char *output) const
{
    ::cass_uuid_string(*this, output);
}

inline error uuid::from_string(char const *str)
{
    return error(::cass_uuid_from_string(str, this));
}

inline error uuid::from_string_n(char const *str, size_t str_length)
{
    return error(::cass_uuid_from_string_n(str, str_length, this));
}

} // namespace cass

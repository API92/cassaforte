/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/defs.hpp>

namespace cass {

class inet : public ::CassInet
{
public:
    inet() = default;

    explicit inet(::CassInet base) : ::CassInet(base) {}

    inline static inet init_v4(uint8_t const *address);

    inline static inet init_v6(uint8_t const *address);

    inline void string(char *output) const;

    inline error from_string(char const *str);
    inline error from_string_n(char const *str, size_t str_length);
};

inline inet inet::init_v4(uint8_t const *address)
{
    return inet(::cass_inet_init_v4(address));
}

inline inet inet::init_v6(uint8_t const *address)
{
    return inet(::cass_inet_init_v6(address));
}

inline void inet::string(char *output) const
{
    ::cass_inet_string(*this, output);
}

inline error inet::from_string(char const *str)
{
    return ::cass_inet_from_string(str, this);
}

inline error inet::from_string_n(char const *str, size_t str_length)
{
    return ::cass_inet_from_string_n(str, str_length, this);
}

} // namespace cass

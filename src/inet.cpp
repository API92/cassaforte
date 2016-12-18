/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/inet.hpp>

#include <cassert>

#include <cassandra.h>

namespace cass {

::CassInet * inet::backend()
{
    return reinterpret_cast<::CassInet *>(_impl);
}

::CassInet const * inet::backend() const
{
    return reinterpret_cast<::CassInet const *>(_impl);
}

inet::inet() : _impl(new ::CassInet)
{
}

inet::~inet()
{
    delete backend();
}

inet::inet(inet const &rhs) : _impl(new ::CassInet(*rhs.backend()))
{
}

inet & inet::operator = (inet const &rhs)
{
    if (this != &rhs) {
        delete backend();
        _impl = nullptr;
        _impl = new ::CassInet(*rhs.backend());
    }
    return *this;
}

inet::inet(inet &&rhs) : _impl(rhs._impl)
{
    rhs._impl = nullptr;
}

inet & inet::operator = (inet &&rhs)
{
    if (this != &rhs) {
        delete backend();
        _impl = rhs._impl;
        rhs._impl = nullptr;
    }
    return *this;
}

inet::inet(::CassInet const &base) : _impl(new ::CassInet(base))
{
}

inet inet::init_v4(uint8_t const *address)
{
    return inet(::cass_inet_init_v4(address));
}

inet inet::init_v6(uint8_t const *address)
{
    return inet(::cass_inet_init_v6(address));
}

void inet::string(char *output) const
{
    ::cass_inet_string(*backend(), output);
}

error inet::from_string(char const *str)
{
    return (error)::cass_inet_from_string(str, backend());
}

error inet::from_string_n(char const *str, size_t str_length)
{
    return (error)::cass_inet_from_string_n(str, str_length, backend());
}

} // namespace cass

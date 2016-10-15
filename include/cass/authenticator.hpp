/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/defs.hpp>
#include <cass/inet.hpp>

namespace cass {

class authenticator {
public:
    static authenticator * ptr(::CassAuthenticator *p)
    {
        return reinterpret_cast<authenticator *>(p);
    }

    ::CassAuthenticator * backend()
    {
        return reinterpret_cast<::CassAuthenticator *>(this);
    }

    ::CassAuthenticator const * backend() const
    {
        return reinterpret_cast<::CassAuthenticator const *>(this);
    }

    inline void address(inet *address) const;

    inline char const * hostname(size_t *length) const;

    inline char const * class_name(size_t *length) const;

    inline void * exchange_data();

    inline void set_exchange_data(void *exchange_data);

    inline char * response(size_t size);

    inline void set_response(char const *response, size_t response_size);

    inline void set_error(char const *message);
    inline void set_error_n(char const *message, size_t message_length);
};

inline void authenticator::address(inet *address) const
{
    ::cass_authenticator_address(backend(), address);
}

inline char const * authenticator::hostname(size_t *length) const
{
    return ::cass_authenticator_hostname(backend(), length);
}

inline char const * authenticator::class_name(size_t *length) const
{
    return ::cass_authenticator_class_name(backend(), length);
}

inline void * authenticator::exchange_data()
{
    return ::cass_authenticator_exchange_data(backend());
}

inline void authenticator::set_exchange_data(void *exchange_data)
{
    ::cass_authenticator_set_exchange_data(backend(), exchange_data);
}

inline char * authenticator::response(size_t size)
{
    return ::cass_authenticator_response(backend(), size);
}

inline void authenticator::set_response(char const *response,
        size_t response_size)
{
    ::cass_authenticator_set_response(backend(), response, response_size);
}

inline void authenticator::set_error(char const *message)
{
    ::cass_authenticator_set_error(backend(), message);
}

inline void authenticator::set_error_n(char const *message,
        size_t message_length)
{
    ::cass_authenticator_set_error_n(backend(), message, message_length);
}

} // namespace cass

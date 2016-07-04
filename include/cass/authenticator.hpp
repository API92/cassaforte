/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/defs.hpp>

namespace cass {

class authenticator {
public:
    explicit authenticator(::CassAuthenticator *p) : p(p) {}
    ::CassAuthenticator * backend() { return p; }
    ::CassAuthenticator const * backend() const { return p; }

    inline void address(inet *address) const;

    inline char const * hostname(size_t *length) const;

    inline char const * class_name(size_t *length) const;

    inline void * exchange_data();

    inline void set_exchange_data(void *exchange_data);

    inline char * response(size_t size);

    inline void set_response(char const *response, size_t response_size);

    inline void set_error(char const *message);
    inline void set_error_n(char const *message, size_t message_length);

private:
    ::CassAuthenticator *p;
};

inline void authenticator::address(inet *address) const
{
    ::cass_authenticator_address(p, address);
}

inline char const * authenticator::hostname(size_t *length) const
{
    return ::cass_authenticator_hostname(p, length);
}

inline char const * authenticator::class_name(size_t *length) const
{
    return ::cass_authenticator_class_name(p, length);
}

inline void * authenticator::exchange_data()
{
    return ::cass_authenticator_exchange_data(p);
}

inline void authenticator::set_exchange_data(void *exchange_data)
{
    ::cass_authenticator_set_exchange_data(p, exchange_data);
}

inline char * authenticator::response(size_t size)
{
    return ::cass_authenticator_response(p, size);
}

inline void authenticator::set_response(char const *response,
        size_t response_size)
{
    ::cass_authenticator_set_response(p, response, response_size);
}

inline void authenticator::set_error(char const *message)
{
    ::cass_authenticator_set_error(p, message);
}

inline void authenticator::set_error_n(char const *message,
        size_t message_length)
{
    ::cass_authenticator_set_error_n(p, message, message_length);
}

} // namespace cass

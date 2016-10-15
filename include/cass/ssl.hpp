/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/defs.hpp>
#include <cass/wrapper_ptr.hpp>

namespace cass {

typedef wrapper_ptr<class ssl> ssl_ptr;

class ssl {
public:
    static ssl * ptr(::CassSsl *p)
    {
        return reinterpret_cast<ssl *>(p);
    }

    ::CassSsl * backend()
    {
        return reinterpret_cast<::CassSsl *>(this);
    }
    ::CassSsl const * backend() const
    {
        return reinterpret_cast<::CassSsl const *>(this);
    }

    inline static ssl_ptr new_ptr();
    inline void free();

    inline error add_trusted_cert(char const *cert);
    inline error add_trusted_cert_n(char const *cert, size_t cert_length);

    inline void set_verify_flags(int flags);

    inline error set_cert(char const *cert);
    inline error set_cert_n(char const *cert, size_t cert_length);

    inline error set_private_key(char const *key, char const *password);
    inline error set_private_key_n(char const *key, size_t key_length,
            char const *password, size_t password_length);
};

inline ssl_ptr ssl::new_ptr()
{
    return ssl_ptr(ssl::ptr(::cass_ssl_new()), true);
}

inline void ssl::free()
{
    ::cass_ssl_free(backend());
}

inline error ssl::add_trusted_cert(char const *cert)
{
    return error(::cass_ssl_add_trusted_cert(backend(), cert));
}

inline error ssl::add_trusted_cert_n(char const *cert, size_t cert_length)
{
    return error(::cass_ssl_add_trusted_cert_n(backend(), cert, cert_length));
}

inline void ssl::set_verify_flags(int flags)
{
    ::cass_ssl_set_verify_flags(backend(), flags);
}

inline error ssl::set_cert(char const *cert)
{
    return error(::cass_ssl_set_cert(backend(), cert));
}

inline error ssl::set_cert_n(char const *cert, size_t cert_length)
{
    return error(::cass_ssl_set_cert_n(backend(), cert, cert_length));
}

inline error ssl::set_private_key(char const *key, char const *password)
{
    return error(::cass_ssl_set_private_key(backend(), key, password));
}

inline error ssl::set_private_key_n(char const *key, size_t key_length,
        char const *password, size_t password_length)
{
    return error(::cass_ssl_set_private_key_n(backend(), key, key_length,
            password, password_length));
}

} // namespace cass

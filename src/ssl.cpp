/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/ssl.hpp>

#include <cassandra.h>

#include <cass/wrapper_ptr_def.hpp>

namespace cass {

ssl * ssl::ptr(::CassSsl *p)
{
    return reinterpret_cast<ssl *>(p);
}

::CassSsl * ssl::backend()
{
    return reinterpret_cast<::CassSsl *>(this);
}

::CassSsl const * ssl::backend() const
{
    return reinterpret_cast<::CassSsl const *>(this);
}

ssl_ptr ssl::new_ptr()
{
    return ssl_ptr(ssl::ptr(::cass_ssl_new()));
}

void ssl::free()
{
    ::cass_ssl_free(backend());
}

error ssl::add_trusted_cert(char const *cert)
{
    return error(::cass_ssl_add_trusted_cert(backend(), cert));
}

error ssl::add_trusted_cert_n(char const *cert, size_t cert_length)
{
    return error(::cass_ssl_add_trusted_cert_n(backend(), cert, cert_length));
}

void ssl::set_verify_flags(int flags)
{
    ::cass_ssl_set_verify_flags(backend(), flags);
}

error ssl::set_cert(char const *cert)
{
    return error(::cass_ssl_set_cert(backend(), cert));
}

error ssl::set_cert_n(char const *cert, size_t cert_length)
{
    return error(::cass_ssl_set_cert_n(backend(), cert, cert_length));
}

error ssl::set_private_key(char const *key, char const *password)
{
    return error(::cass_ssl_set_private_key(backend(), key, password));
}

error ssl::set_private_key_n(char const *key, size_t key_length,
        char const *password, size_t password_length)
{
    return error(::cass_ssl_set_private_key_n(backend(), key, key_length,
            password, password_length));
}

template class wrapper_ptr<ssl>;

} // namespace cass

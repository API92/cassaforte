/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/defs.hpp>
#include <cass/wrapper_ptr.hpp>

namespace cass {

typedef wrapper_ptr<class ssl> ssl_ptr;
typedef wrapper_const_ptr<class ssl const> ssl_const_ptr;

class ssl {
public:
    explicit ssl(::CassSsl *p) : p(p) {}
    ::CassSsl * backend() { return p; }
    ::CassSsl const * backend() const { return p; }

    inline static ssl_ptr new_ptr();
    inline static void free(ssl const);

    inline error add_trusted_cert(char const *cert);
    inline error add_trusted_cert_n(char const *cert, size_t cert_length);

    inline void set_verify_flags(int flags);

    inline error set_cert(char const *cert);
    inline error set_cert_n(char const *cert, size_t cert_length);

    inline error set_private_key(char const *key, char const *password);
    inline error set_private_key_n(char const *key, size_t key_length,
            char const *password, size_t password_length);

private:
    ::CassSsl *p;
};

inline ssl_ptr ssl::new_ptr()
{
    return ssl_ptr(ssl(::cass_ssl_new()), true);
}

inline void ssl::free(ssl const s)
{
    ::cass_ssl_free(s.p);
}

inline error ssl::add_trusted_cert(char const *cert)
{
    return error(::cass_ssl_add_trusted_cert(p, cert));
}

inline error ssl::add_trusted_cert_n(char const *cert, size_t cert_length)
{
    return error(::cass_ssl_add_trusted_cert_n(p, cert, cert_length));
}

inline void ssl::set_verify_flags(int flags)
{
    ::cass_ssl_set_verify_flags(p, flags);
}

inline error ssl::set_cert(char const *cert)
{
    return error(::cass_ssl_set_cert(p, cert));
}

inline error ssl::set_cert_n(char const *cert, size_t cert_length)
{
    return error(::cass_ssl_set_cert_n(p, cert, cert_length));
}

inline error ssl::set_private_key(char const *key, char const *password)
{
    return error(::cass_ssl_set_private_key(p, key, password));
}

inline error ssl::set_private_key_n(char const *key, size_t key_length,
        char const *password, size_t password_length)
{
    return error(::cass_ssl_set_private_key_n(p, key, key_length,
            password, password_length));
}

} // namespace cass

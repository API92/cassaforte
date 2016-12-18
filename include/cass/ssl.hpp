/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include "delete_defaults.hpp"
#include "forward.hpp"
#include "impexp.hpp"

typedef struct CassSsl_ CassSsl;

namespace cass {

class CASSA_IMPEXP ssl : delete_defaults {
public:
    static ssl * ptr(::CassSsl *p);

    ::CassSsl * backend();
    ::CassSsl const * backend() const;

    static ssl_ptr new_ptr();
    void free();

    error add_trusted_cert(char const *cert);
    error add_trusted_cert_n(char const *cert, size_t cert_length);

    void set_verify_flags(int flags);

    error set_cert(char const *cert);
    error set_cert_n(char const *cert, size_t cert_length);

    error set_private_key(char const *key, char const *password);
    error set_private_key_n(char const *key, size_t key_length,
            char const *password, size_t password_length);
};

} // namespace cass

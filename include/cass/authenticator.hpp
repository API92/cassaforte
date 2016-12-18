/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include "delete_defaults.hpp"
#include "forward.hpp"
#include "impexp.hpp"

typedef struct CassAuthenticator_ CassAuthenticator;

namespace cass {

class CASSA_IMPEXP authenticator : delete_defaults {
public:
    static authenticator * ptr(::CassAuthenticator *p);

    ::CassAuthenticator * backend();
    ::CassAuthenticator const * backend() const;

    void address(inet *address) const;

    char const * hostname(size_t *length) const;

    char const * class_name(size_t *length) const;

    void * exchange_data();

    void set_exchange_data(void *exchange_data);

    char * response(size_t size);

    void set_response(char const *response, size_t response_size);

    void set_error(char const *message);
    void set_error_n(char const *message, size_t message_length);
};

} // namespace cass

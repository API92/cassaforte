/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include "delete_defaults.hpp"
#include "forward.hpp"
#include "impexp.hpp"


typedef struct CassFuture_ CassFuture;
typedef void (*CassFutureCallback)(CassFuture *future, void *data);

namespace cass {

class CASSA_IMPEXP future : delete_defaults {
public:
    typedef ::CassFutureCallback callback;

    static future * ptr(::CassFuture *p);

    ::CassFuture * backend();

    ::CassFuture const * backend() const;

    void free();

    error set_callback(future::callback callback, void *data);

    bool ready();

    void wait();

    bool wait_timed(duration_t timeout_us);

    result_const_ptr get_result();

    error_result_const_ptr get_error_result();

    prepared_const_ptr get_prepared();

    error error_code();

    void error_message(char const **message, size_t *message_length);

    size_t custom_payload_item_count();

    error custom_payload_item(size_t index, char const **name,
            size_t *name_length, byte_t const **value, size_t *value_size);
};

} // namespace cass

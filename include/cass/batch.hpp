/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include "delete_defaults.hpp"
#include "forward.hpp"
#include "impexp.hpp"

typedef struct CassBatch_ CassBatch;

namespace cass {

class CASSA_IMPEXP batch : delete_defaults {
public:
    static batch * ptr(::CassBatch *p);

    ::CassBatch * backend();
    ::CassBatch const * backend() const;

    void free();
    static batch_ptr new_ptr(batch_type type);

    error set_consistency(cass::consistency consistency);

    error set_serial_consistency(consistency serial_consistency);

    error set_timestamp(int64_t timestamp);

    error set_request_timeout(uint64_t timeout_ms);

    error set_retry_policy(cass::retry_policy *retry_policy);

    error set_custom_payload(custom_payload const *payload);

    error add_statement(cass::statement *statement);
};

} // namespace cass

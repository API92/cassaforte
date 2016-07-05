/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/defs.hpp>
#include <cass/impexp.hpp>
#include <cass/wrapper_ptr.hpp>

namespace cass {

typedef wrapper_ptr<class batch> batch_ptr;

class batch {
public:
    explicit batch(::CassBatch *p) : p(p) {}
    ::CassBatch * backend() { return p; }
    ::CassBatch const * backend() const { return p; }

    inline static void free(batch const b);
    inline static batch_ptr new_ptr(batch_type type);

    inline error set_consistency(cass::consistency consistency);

    inline error set_serial_consistency(consistency serial_consistency);

    inline error set_timestamp(int64_t timestamp);

    inline error set_request_timeout(uint64_t timeout_ms);

    CASSA_IMPEXP error set_retry_policy(cass::retry_policy *retry_policy);

    CASSA_IMPEXP error set_custom_payload(custom_payload const *payload);

    CASSA_IMPEXP error add_statement(cass::statement *statement);

private:
    ::CassBatch *p;
};

inline void batch::free(batch const b)
{
    ::cass_batch_free(b.p);
}

inline batch_ptr batch::new_ptr(batch_type type)
{
    return batch_ptr(batch(::cass_batch_new(type)), true);
}

inline error batch::set_consistency(cass::consistency consistency)
{
    return ::cass_batch_set_consistency(p, consistency);
}

inline error batch::set_serial_consistency(consistency serial_consistency)
{
    return ::cass_batch_set_serial_consistency(p, serial_consistency);
}

inline error batch::set_timestamp(int64_t timestamp)
{
    return ::cass_batch_set_timestamp(p, timestamp);
}

inline error batch::set_request_timeout(uint64_t timeout_ms)
{
    return ::cass_batch_set_request_timeout(p, timeout_ms);
}

} // namespace cass

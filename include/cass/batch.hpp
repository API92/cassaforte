/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/defs.hpp>
#include <cass/impexp.hpp>
#include <cass/wrapper_ptr.hpp>

namespace cass {

typedef wrapper_ptr<batch> batch_ptr;

class batch : wrapper {
public:
    static batch * ptr(::CassBatch *p)
    {
        return reinterpret_cast<batch *>(p);
    }

    ::CassBatch * backend()
    {
        return reinterpret_cast<::CassBatch *>(this);
    }

    ::CassBatch const * backend() const
    {
        return reinterpret_cast<::CassBatch const *>(this);
    }

    inline void free();
    inline static batch_ptr new_ptr(batch_type type);

    inline error set_consistency(cass::consistency consistency);

    inline error set_serial_consistency(consistency serial_consistency);

    inline error set_timestamp(int64_t timestamp);

    inline error set_request_timeout(uint64_t timeout_ms);

    CASSA_IMPEXP error set_retry_policy(cass::retry_policy *retry_policy);

    CASSA_IMPEXP error set_custom_payload(custom_payload const *payload);

    CASSA_IMPEXP error add_statement(cass::statement *statement);
};

inline void batch::free()
{
    ::cass_batch_free(backend());
}

inline batch_ptr batch::new_ptr(batch_type type)
{
    return batch_ptr(batch::ptr(::cass_batch_new((::CassBatchType)type)), true);
}

inline error batch::set_consistency(cass::consistency consistency)
{
    return error(::cass_batch_set_consistency(backend(), consistency));
}

inline error batch::set_serial_consistency(consistency serial_consistency)
{
    return error(::cass_batch_set_serial_consistency(
                backend(), serial_consistency));
}

inline error batch::set_timestamp(int64_t timestamp)
{
    return error(::cass_batch_set_timestamp(backend(), timestamp));
}

inline error batch::set_request_timeout(uint64_t timeout_ms)
{
    return error(::cass_batch_set_request_timeout(backend(), timeout_ms));
}

} // namespace cass

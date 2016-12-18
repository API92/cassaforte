/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/batch.hpp>

#include <cassandra.h>

#include <cass/custom_payload.hpp>
#include <cass/retry_policy.hpp>
#include <cass/statement.hpp>
#include <cass/wrapper_ptr_def.hpp>

namespace cass {

void batch::free()
{
    ::cass_batch_free(backend());
}

batch_ptr batch::new_ptr(batch_type type)
{
    return batch_ptr(batch::ptr(::cass_batch_new((::CassBatchType)type)), true);
}

batch * batch::ptr(::CassBatch *p)
{
    return reinterpret_cast<batch *>(p);
}

::CassBatch * batch::backend()
{
    return reinterpret_cast<::CassBatch *>(this);
}

::CassBatch const * batch::backend() const
{
    return reinterpret_cast<::CassBatch const *>(this);
}

error batch::set_consistency(cass::consistency consistency)
{
    return error(::cass_batch_set_consistency(backend(),
                (::CassConsistency)consistency));
}

error batch::set_serial_consistency(consistency serial_consistency)
{
    return error(::cass_batch_set_serial_consistency(
                backend(), (::CassConsistency)serial_consistency));
}

error batch::set_timestamp(int64_t timestamp)
{
    return error(::cass_batch_set_timestamp(backend(), timestamp));
}

error batch::set_request_timeout(uint64_t timeout_ms)
{
    return error(::cass_batch_set_request_timeout(backend(), timeout_ms));
}

error batch::set_retry_policy(cass::retry_policy *retry_policy)
{
    return error(::cass_batch_set_retry_policy(backend(),
            retry_policy ? retry_policy->backend() : nullptr));
}

error batch::set_custom_payload(custom_payload const *payload)
{
    return error(::cass_batch_set_custom_payload(backend(),
            payload ? payload->backend() : nullptr));
}

error batch::add_statement(cass::statement *statement)
{
    return error(::cass_batch_add_statement(backend(), statement->backend()));
}

template class wrapper_ptr<batch>;

} // namespace cass

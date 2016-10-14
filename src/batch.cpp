/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/batch.hpp>

#include <cass/custom_payload.hpp>
#include <cass/retry_policy.hpp>
#include <cass/statement.hpp>

namespace cass {

error batch::set_retry_policy(cass::retry_policy *retry_policy)
{
    return error(::cass_batch_set_retry_policy(p,
            retry_policy ? retry_policy->backend() : nullptr));
}

error batch::set_custom_payload(custom_payload const *payload)
{
    return error(::cass_batch_set_custom_payload(p,
            payload ? payload->backend() : nullptr));
}

error batch::add_statement(cass::statement *statement)
{
    return error(::cass_batch_add_statement(p, statement->backend()));
}

} // namespace cass

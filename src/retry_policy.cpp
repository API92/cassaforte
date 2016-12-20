/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/retry_policy.hpp>

#include <cassandra.h>

#include <cass/wrapper_ptr_def.hpp>

namespace cass {

retry_policy * retry_policy::ptr(::CassRetryPolicy *p)
{
    return reinterpret_cast<retry_policy *>(p);
}

::CassRetryPolicy * retry_policy::backend()
{
    return reinterpret_cast<::CassRetryPolicy *>(this);
}

void retry_policy::free()
{
    ::cass_retry_policy_free(backend());
}

retry_policy_ptr retry_policy::default_new()
{
    return retry_policy_ptr(retry_policy::ptr(
                ::cass_retry_policy_default_new()));
}

retry_policy_ptr retry_policy::downgrading_consistency_new()
{
    return retry_policy_ptr(retry_policy::ptr(
                ::cass_retry_policy_downgrading_consistency_new()));
}

retry_policy_ptr retry_policy::fallthrough_new()
{
    return retry_policy_ptr(retry_policy::ptr(
                ::cass_retry_policy_fallthrough_new()));
}

retry_policy_ptr retry_policy::logging_new(
        retry_policy *child_retry_policy)
{
    ::CassRetryPolicy *p = ::cass_retry_policy_logging_new(
            child_retry_policy->backend());
    return retry_policy_ptr(retry_policy::ptr(p));
}

template class wrapper_ptr<retry_policy>;

} // namespace cass

/*
 * Copyright (C) Andrey Pikas
 */

#include <cassandra.h>

#include <cass/wrapper_ptr.hpp>

namespace cass {

typedef wrapper_ptr<class retry_policy> retry_policy_ptr;

class retry_policy {
public:
    static retry_policy * ptr(::CassRetryPolicy *p)
    {
        return reinterpret_cast<retry_policy *>(p);
    }

    ::CassRetryPolicy * backend()
    {
        return reinterpret_cast<::CassRetryPolicy *>(this);
    }

    inline void free();

    inline static retry_policy_ptr default_new();

    inline static retry_policy_ptr downgrading_consistency_new();

    inline static retry_policy_ptr fallthrough_new();

    inline static retry_policy_ptr logging_new(
            retry_policy *child_retry_policy);
};

inline void retry_policy::free()
{
    ::cass_retry_policy_free(backend());
}

inline retry_policy_ptr retry_policy::default_new()
{
    return retry_policy_ptr(retry_policy::ptr(
                ::cass_retry_policy_default_new()), true);
}

inline retry_policy_ptr retry_policy::downgrading_consistency_new()
{
    return retry_policy_ptr(retry_policy::ptr(
                ::cass_retry_policy_downgrading_consistency_new()), true);
}

inline retry_policy_ptr retry_policy::fallthrough_new()
{
    return retry_policy_ptr(retry_policy::ptr(
                ::cass_retry_policy_fallthrough_new()), true);
}

inline retry_policy_ptr retry_policy::logging_new(
        retry_policy *child_retry_policy)
{
    ::CassRetryPolicy *p = ::cass_retry_policy_logging_new(
            child_retry_policy->backend());
    return retry_policy_ptr(retry_policy::ptr(p), p != nullptr);
}

} // namespace cass

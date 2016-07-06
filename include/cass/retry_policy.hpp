/*
 * Copyright (C) Andrey Pikas
 */

#include <cassandra.h>

#include <cass/wrapper_ptr.hpp>

namespace cass {

typedef wrapper_ptr<class retry_policy> retry_policy_ptr;

class retry_policy {
public:
    explicit retry_policy(::CassRetryPolicy *p) : p(p) {}
    ::CassRetryPolicy * backend() { return p; }
    ::CassRetryPolicy const * backend() const { return p; }

    inline static void free(retry_policy const p);

    inline static retry_policy_ptr default_new();

    inline static retry_policy_ptr downgrading_consistency_new();

    inline static retry_policy_ptr fallthrough_new();

    inline static retry_policy_ptr logging_new(
            retry_policy *child_retry_policy);

private:
    ::CassRetryPolicy *p;
};

inline void retry_policy::free(retry_policy const p)
{
    ::cass_retry_policy_free(p.p);
}

inline retry_policy_ptr retry_policy::default_new()
{
    return retry_policy_ptr(retry_policy(::cass_retry_policy_default_new()),
            true);
}

inline retry_policy_ptr retry_policy::downgrading_consistency_new()
{
    return retry_policy_ptr(retry_policy(
                ::cass_retry_policy_downgrading_consistency_new()), true);
}

inline retry_policy_ptr retry_policy::fallthrough_new()
{
    return retry_policy_ptr(retry_policy(::cass_retry_policy_fallthrough_new()),
            true);
}

inline retry_policy_ptr retry_policy::logging_new(
        retry_policy *child_retry_policy)
{
    retry_policy p(::cass_retry_policy_logging_new(child_retry_policy->p));
    return retry_policy_ptr(p, p.p != nullptr);
}

} // namespace cass

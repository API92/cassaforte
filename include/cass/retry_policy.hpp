/*
 * Copyright (C) Andrey Pikas
 */

#include "delete_defaults.hpp"
#include "forward.hpp"
#include "impexp.hpp"

typedef struct CassRetryPolicy_ CassRetryPolicy;

namespace cass {

class retry_policy : delete_defaults {
public:
    static retry_policy * ptr(::CassRetryPolicy *p);

    ::CassRetryPolicy * backend();

    void free();

    static retry_policy_ptr default_new();

    static retry_policy_ptr downgrading_consistency_new();

    static retry_policy_ptr fallthrough_new();

    static retry_policy_ptr logging_new(
            retry_policy *child_retry_policy);
};

} // namespace cass

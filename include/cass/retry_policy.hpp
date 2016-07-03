/*
 * Copyright (C) Andrey Pikas
 */

#include <cassandra.h>

namespace cass {

class retry_policy {
public:
    explicit retry_policy(::CassRetryPolicy *p) : p(p) {}
    ::CassRetryPolicy * backend() { return p; }
    ::CassRetryPolicy const * backend() const { return p; }

private:
    ::CassRetryPolicy *p;
};

} // namespace cass

/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

namespace cass {

class batch {
public:
    explicit batch(::CassBatch *p) : p(p) {}
    ::CassBatch * backend() { return p; }
    ::CassBatch const * backend() const { return p; }

private:
    ::CassBatch *p;
};

} // namespace cass

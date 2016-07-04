/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

namespace cass {

class collection {
public:
    explicit collection(::CassCollection *p) : p(p) {}
    ::CassCollection * backend() { return p; }
    ::CassCollection const * backend() const { return p; }

private:
    ::CassCollection *p;
};

} // namespace cass

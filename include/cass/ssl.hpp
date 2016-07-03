/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/defs.hpp>

namespace cass {

class ssl {
public:
    ::CassSsl * backend() { return p; }
    ::CassSsl const * backend() const { return p; }

private:
    ::CassSsl *p;
};

} // namespace cass

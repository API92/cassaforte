/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

namespace cass {

class tuple {
public:
    explicit tuple(::CassTuple *p) : p(p) {}
    ::CassTuple * backend() { return p; }
    ::CassTuple const * backend() const { return p; }

private:
    ::CassTuple *p;
};

} // namespace cass

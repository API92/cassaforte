/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/wrapper_ptr.hpp>

namespace cass {

typedef dummy_ptr<class row const> row_const_ptr;

class row {
public:
    explicit row(::CassRow const *p) : p(p) {}
    ::CassRow const * backend() const { return p; }

private:
    ::CassRow const *p;
};

} // namespace cass

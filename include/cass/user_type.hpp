/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

namespace cass {

class user_type {
public:
    explicit user_type(::CassUserType *p) : p(p) {}
    ::CassUserType * backend() { return p; }
    ::CassUserType const * backend() const { return p; }

private:
    ::CassUserType *p;
};

} // namespace cass

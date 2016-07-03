/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/wrapper_ptr.hpp>

namespace cass {

typedef dummy_ptr<class value const> value_const_ptr;

class value {
public:
    explicit value(::CassValue const *p) : p(p) {}
    ::CassValue const * backend() const { return p; }

private:
    ::CassValue const *p;
};

} // namespace cass

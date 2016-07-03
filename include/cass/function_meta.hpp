/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/wrapper_ptr.hpp>

namespace cass {

class function_meta {
public:
    explicit function_meta(::CassFunctionMeta const *p) : p(p) {}
    ::CassFunctionMeta const * backend() const { return p; }

private:
    ::CassFunctionMeta const *p;
};

typedef dummy_ptr<function_meta const> function_meta_const_ptr;

} // namespace cass

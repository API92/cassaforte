/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/wrapper_ptr.hpp>

namespace cass {

typedef wrapper_const_ptr<class result const> result_const_ptr;

class result {
public:
    explicit result(::CassResult const *p) : p(p) {}
    ::CassResult const * backend() const { return p; }

    inline static void free(result const r);

private:
    ::CassResult const *p;
};

inline void result::free(result const r)
{
    ::cass_result_free(r.p);
}

} // namespace cass

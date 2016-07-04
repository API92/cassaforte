/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/wrapper_ptr.hpp>

namespace cass {

typedef wrapper_ptr<class error_result const> error_result_const_ptr;

class error_result {
public:
    explicit error_result(::CassErrorResult const *p) : p(p) {}
    ::CassErrorResult const * backend() const { return p; }

    inline static void free(error_result const e);

private:
    ::CassErrorResult const *p;
};

inline void error_result::free(error_result const e)
{
    ::cass_error_result_free(e.p);
}

} // namespace cass

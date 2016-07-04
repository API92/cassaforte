/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/wrapper_ptr.hpp>

namespace cass {

typedef wrapper_const_ptr<class prepared const> prepared_const_ptr;

class prepared {
public:
    explicit prepared(::CassPrepared const *p) : p(p) {}
    ::CassPrepared const * backend() const { return p; }

    inline static void free(prepared const p);

private:
    ::CassPrepared const *p;
};

inline void prepared::free(prepared const p)
{
    ::cass_prepared_free(p.p);
}

} // namespace cass

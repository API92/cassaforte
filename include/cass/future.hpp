/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/wrapper_ptr.hpp>

namespace cass {

typedef wrapper_ptr<class future> future_ptr;

class future {
public:
    explicit future(::CassFuture *p) : p(p) {}
    ::CassFuture * backend() { return p; }
    ::CassFuture const * backend() const { return p; }

    inline static void free(const future);

private:
    ::CassFuture *p;
};

inline void future::free(const future f)
{
    ::cass_future_free(f.p);
}

} // namespace cass

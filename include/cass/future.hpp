/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/shared_res.hpp>

namespace cass {

class future {
public:
    explicit future(::CassFuture *p) : p(p) {}
    ::CassFuture * backend() { return p; }
    ::CassFuture const * backend() const { return p; }

    inline static void free(const future);

private:
    ::CassFuture *p;
};

class future_ptr : shared_res<future, future::free> {
public:
    using shared_res::shared_res;
    future * get() { return &shared_res::get(); }
    future * operator -> () { return &shared_res::get(); }
    future & operator * () { return shared_res::get(); }
};


///
/// future
///

inline void future::free(const future f)
{
    ::cass_future_free(f.p);
}

} // namespace cass

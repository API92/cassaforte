/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/wrapper_ptr.hpp>

namespace cass {

typedef dummy_ptr<class aggregate_meta const> aggregate_meta_const_ptr;

class aggregate_meta {
public:
    explicit aggregate_meta(::CassAggregateMeta const *p) : p(p) {}
    ::CassAggregateMeta const * backend() const { return p; }

private:
    ::CassAggregateMeta const *p;
};

} // namespace cass

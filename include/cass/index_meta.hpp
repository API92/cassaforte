/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/wrapper_ptr.hpp>

namespace cass {

typedef dummy_ptr<class index_meta const> index_meta_const_ptr;

class index_meta {
public:
    explicit index_meta(::CassIndexMeta const *p) : p(p) {}
    ::CassIndexMeta const * backend() const { return p; }

private:
    ::CassIndexMeta const *p;
};

} // namespace cass

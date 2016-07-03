/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/wrapper_ptr.hpp>

namespace cass {

typedef dummy_ptr<class column_meta const> column_meta_const_ptr;

class column_meta {
public:
    explicit column_meta(::CassColumnMeta const *p) : p(p) {}
    ::CassColumnMeta const * backend() const { return p; }

private:
    ::CassColumnMeta const *p;
};

} // namespace cass

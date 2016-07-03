/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

namespace cass {

class timestamp_gen {
public:
    explicit timestamp_gen(::CassTimestampGen *p) : p(p) {}
    ::CassTimestampGen * backend() { return p; }
    ::CassTimestampGen const * backend() const { return p; }

private:
    ::CassTimestampGen *p;
};

} // namespace cass

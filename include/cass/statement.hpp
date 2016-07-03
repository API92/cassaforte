/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

namespace cass {

class statement {
public:
    explicit statement(::CassStatement *p) : p(p) {}
    ::CassStatement * backend() { return p; }
    ::CassStatement const * backend() const { return p; }

private:
    ::CassStatement *p;
};

} // namespace cass

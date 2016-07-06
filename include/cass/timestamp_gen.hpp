/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/wrapper_ptr.hpp>

namespace cass {

typedef wrapper_ptr<class timestamp_gen> timestamp_gen_ptr;

class timestamp_gen {
public:
    explicit timestamp_gen(::CassTimestampGen *p) : p(p) {}
    ::CassTimestampGen * backend() { return p; }
    ::CassTimestampGen const * backend() const { return p; }

    inline static void free(timestamp_gen const g);

    inline static timestamp_gen_ptr server_side_new();

    inline static timestamp_gen_ptr monotonic_new();

private:
    ::CassTimestampGen *p;
};

inline void timestamp_gen::free(timestamp_gen const g)
{
    ::cass_timestamp_gen_free(g.p);
}

inline timestamp_gen_ptr timestamp_gen::server_side_new()
{
    return timestamp_gen_ptr(timestamp_gen(
                ::cass_timestamp_gen_server_side_new()), true);
}

inline timestamp_gen_ptr timestamp_gen::monotonic_new()
{
    return timestamp_gen_ptr(timestamp_gen(
                ::cass_timestamp_gen_monotonic_new()), true);
}

} // namespace cass

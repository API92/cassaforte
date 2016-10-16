/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/defs.hpp>
#include <cass/wrapper_ptr.hpp>

namespace cass {

typedef wrapper_ptr<timestamp_gen> timestamp_gen_ptr;

class timestamp_gen : wrapper {
public:
    static timestamp_gen * ptr(::CassTimestampGen *p)
    {
        return reinterpret_cast<timestamp_gen *>(p);
    }

    ::CassTimestampGen * backend()
    {
        return reinterpret_cast<::CassTimestampGen *>(this);
    }

    ::CassTimestampGen const * backend() const
    {
        return reinterpret_cast<::CassTimestampGen const *>(this);
    }

    inline void free();

    inline static timestamp_gen_ptr server_side_new();

    inline static timestamp_gen_ptr monotonic_new();
};

inline void timestamp_gen::free()
{
    ::cass_timestamp_gen_free(backend());
}

inline timestamp_gen_ptr timestamp_gen::server_side_new()
{
    return timestamp_gen_ptr(timestamp_gen::ptr(
                ::cass_timestamp_gen_server_side_new()), true);
}

inline timestamp_gen_ptr timestamp_gen::monotonic_new()
{
    return timestamp_gen_ptr(timestamp_gen::ptr(
                ::cass_timestamp_gen_monotonic_new()), true);
}

} // namespace cass

/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/timestamp_gen.hpp>

#include <cassandra.h>

#include <cass/wrapper_ptr_def.hpp>

namespace cass {

timestamp_gen * timestamp_gen::ptr(::CassTimestampGen *p)
{
    return reinterpret_cast<timestamp_gen *>(p);
}

::CassTimestampGen * timestamp_gen::backend()
{
    return reinterpret_cast<::CassTimestampGen *>(this);
}

::CassTimestampGen const * timestamp_gen::backend() const
{
    return reinterpret_cast<::CassTimestampGen const *>(this);
}

inline void timestamp_gen::free()
{
    ::cass_timestamp_gen_free(backend());
}

inline timestamp_gen_ptr timestamp_gen::server_side_new()
{
    return timestamp_gen_ptr(timestamp_gen::ptr(
                ::cass_timestamp_gen_server_side_new()));
}

inline timestamp_gen_ptr timestamp_gen::monotonic_new()
{
    return timestamp_gen_ptr(timestamp_gen::ptr(
                ::cass_timestamp_gen_monotonic_new()));
}

template class wrapper_ptr<timestamp_gen>;

} // namespace cass

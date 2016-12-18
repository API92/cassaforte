/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include "delete_defaults.hpp"
#include "forward.hpp"
#include "impexp.hpp"

typedef struct CassTimestampGen_ CassTimestampGen;

namespace cass {

class timestamp_gen : delete_defaults {
public:
    static timestamp_gen * ptr(::CassTimestampGen *p);

    ::CassTimestampGen * backend();
    ::CassTimestampGen const * backend() const;

    inline void free();

    inline static timestamp_gen_ptr server_side_new();

    inline static timestamp_gen_ptr monotonic_new();
};

} // namespace cass

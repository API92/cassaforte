/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include "delete_defaults.hpp"
#include "forward.hpp"
#include "impexp.hpp"

typedef struct CassUuidGen_ CassUuidGen;

namespace cass {

class CASSA_IMPEXP uuid_gen : delete_defaults {
public:
    static uuid_gen * ptr(::CassUuidGen *p);

    ::CassUuidGen * backend();

    ::CassUuidGen const * backend() const;

    void free();

    static uuid_gen_ptr new_ptr();

    static uuid_gen_ptr new_with_node(uint64_t node);

    void time(uuid *output);

    void random(uuid *output);

    void from_time(uint64_t timestamp, uuid *output);
};

} // namespace cass

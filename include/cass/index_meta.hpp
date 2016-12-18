/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include "delete_defaults.hpp"
#include "forward.hpp"
#include "impexp.hpp"

typedef struct CassIndexMeta_ CassIndexMeta;

namespace cass {

class index_meta : delete_defaults {
public:
    static index_meta const * ptr(::CassIndexMeta const *p);

    ::CassIndexMeta const * backend() const;

    void name(char const **name, size_t *name_length) const;

    index_type type() const;

    void target(char const **target, size_t *target_length) const;

    value const * options() const;

    value const * field_by_name(char const *name) const;
    value const * field_by_name_n(
            char const *name, size_t name_length) const;
};

} // namespace cass

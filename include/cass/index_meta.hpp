/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/defs.hpp>
#include <cass/impexp.hpp>
#include <cass/wrapper_ptr.hpp>

namespace cass {

typedef dummy_ptr<class index_meta const> index_meta_const_ptr;

class index_meta {
public:
    explicit index_meta(::CassIndexMeta const *p) : p(p) {}
    ::CassIndexMeta const * backend() const { return p; }

    inline void name(char const **name, size_t *name_length) const;

    inline index_type type() const;

    inline void target(char const **target, size_t *target_length) const;

    CASSA_IMPEXP value_const_ptr options() const;

    CASSA_IMPEXP value_const_ptr field_by_name(char const *name) const;
    CASSA_IMPEXP value_const_ptr field_by_name_n(
            char const *name, size_t name_length) const;

private:
    ::CassIndexMeta const *p;
};

inline void index_meta::name(char const **name, size_t *name_length) const
{
    ::cass_index_meta_name(p, name, name_length);
}

inline index_type index_meta::type() const
{
    return ::cass_index_meta_type(p);
}

inline void index_meta::target(char const **target, size_t *target_length) const
{
    ::cass_index_meta_target(p, target, target_length);
}

} // namespace cass

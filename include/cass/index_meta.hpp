/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/defs.hpp>
#include <cass/impexp.hpp>
#include <cass/wrapper_ptr.hpp>

namespace cass {

class index_meta : wrapper {
public:
    static index_meta const * ptr(::CassIndexMeta const *p)
    {
        return reinterpret_cast<index_meta const *>(p);
    }

    ::CassIndexMeta const * backend() const
    {
        return reinterpret_cast<::CassIndexMeta const *>(this);
    }

    inline void name(char const **name, size_t *name_length) const;

    inline index_type type() const;

    inline void target(char const **target, size_t *target_length) const;

    CASSA_IMPEXP value const * options() const;

    CASSA_IMPEXP value const * field_by_name(char const *name) const;
    CASSA_IMPEXP value const * field_by_name_n(
            char const *name, size_t name_length) const;
};

inline void index_meta::name(char const **name, size_t *name_length) const
{
    ::cass_index_meta_name(backend(), name, name_length);
}

inline index_type index_meta::type() const
{
    return ::cass_index_meta_type(backend());
}

inline void index_meta::target(char const **target, size_t *target_length) const
{
    ::cass_index_meta_target(backend(), target, target_length);
}

} // namespace cass

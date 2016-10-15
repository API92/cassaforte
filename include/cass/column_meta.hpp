/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/defs.hpp>
#include <cass/impexp.hpp>
#include <cass/wrapper_ptr.hpp>

namespace cass {

class column_meta {
public:
    static column_meta const * ptr(::CassColumnMeta const *p)
    {
        return reinterpret_cast<column_meta const *>(p);
    }

    ::CassColumnMeta const * backend() const
    {
        return reinterpret_cast<::CassColumnMeta const *>(this);
    }

    inline void name(char const **name, size_t *name_length) const;

    inline column_type type() const;

    CASSA_IMPEXP data_type_const_ptr data_type() const;

    CASSA_IMPEXP value const * field_by_name(char const *name) const;
    CASSA_IMPEXP value const * field_by_name_n(char const *name,
            size_t name_length) const;
};

inline void column_meta::name(char const **name, size_t *name_length) const
{
    ::cass_column_meta_name(backend(), name, name_length);
}

inline column_type column_meta::type() const
{
    return ::cass_column_meta_type(backend());
}

} // namespace cass

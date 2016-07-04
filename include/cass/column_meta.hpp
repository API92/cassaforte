/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/defs.hpp>
#include <cass/impexp.hpp>
#include <cass/wrapper_ptr.hpp>

namespace cass {

typedef dummy_ptr<class column_meta const> column_meta_const_ptr;

class column_meta {
public:
    explicit column_meta(::CassColumnMeta const *p) : p(p) {}
    ::CassColumnMeta const * backend() const { return p; }

    inline void name(char const **name, size_t *name_length) const;

    inline column_type type() const;

    CASSA_IMPEXP data_type_const_ptr data_type() const;

    CASSA_IMPEXP value_const_ptr field_by_name(char const *name) const;
    CASSA_IMPEXP value_const_ptr field_by_name_n(char const *name,
            size_t name_length) const;

private:
    ::CassColumnMeta const *p;
};

inline void column_meta::name(char const **name, size_t *name_length) const
{
    ::cass_column_meta_name(p, name, name_length);
}

inline column_type column_meta::type() const
{
    return ::cass_column_meta_type(p);
}

} // namespace cass

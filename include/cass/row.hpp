/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/defs.hpp>
#include <cass/wrapper_ptr.hpp>

namespace cass {

class row {
public:
    static row const * ptr(::CassRow const *p)
    {
        return reinterpret_cast<row const *>(p);
    }

    ::CassRow const * backend() const
    {
        return reinterpret_cast<::CassRow const *>(this);
    }

    CASSA_IMPEXP value const * get_column(size_t index) const;
    CASSA_IMPEXP value const * get_column_by_name(char const *name) const;
    CASSA_IMPEXP value const * get_column_by_name_n(char const *name,
            size_t name_length) const;
};

} // namespace cass

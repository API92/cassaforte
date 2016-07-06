/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/defs.hpp>
#include <cass/wrapper_ptr.hpp>

namespace cass {

typedef dummy_ptr<class row const> row_const_ptr;

class row {
public:
    explicit row(::CassRow const *p) : p(p) {}
    ::CassRow const * backend() const { return p; }

    CASSA_IMPEXP value_const_ptr get_column(size_t index) const;
    CASSA_IMPEXP value_const_ptr get_column_by_name(char const *name) const;
    CASSA_IMPEXP value_const_ptr get_column_by_name_n(char const *name,
            size_t name_length) const;

private:
    ::CassRow const *p;
};

} // namespace cass

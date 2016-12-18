/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include "delete_defaults.hpp"
#include "forward.hpp"
#include "impexp.hpp"

typedef struct CassRow_ CassRow;

namespace cass {

class CASSA_IMPEXP row : delete_defaults {
public:
    static row const * ptr(::CassRow const *p);

    ::CassRow const * backend() const;

    value const * get_column(size_t index) const;
    value const * get_column_by_name(char const *name) const;
    value const * get_column_by_name_n(char const *name,
            size_t name_length) const;
};

} // namespace cass

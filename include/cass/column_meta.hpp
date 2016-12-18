/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include "delete_defaults.hpp"
#include "forward.hpp"
#include "impexp.hpp"

typedef struct CassColumnMeta_ CassColumnMeta;

namespace cass {

class CASSA_IMPEXP column_meta : delete_defaults {
public:
    static column_meta const * ptr(::CassColumnMeta const *p);

    ::CassColumnMeta const * backend() const;

    void name(char const **name, size_t *name_length) const;

    column_type type() const;

    cass::data_type const * data_type() const;

    value const * field_by_name(char const *name) const;
    value const * field_by_name_n(char const *name, size_t name_length) const;
};

} // namespace cass

/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include "delete_defaults.hpp"
#include "forward.hpp"
#include "impexp.hpp"

typedef struct CassResult_ CassResult;

namespace cass {

class CASSA_IMPEXP result : delete_defaults {
public:
    static result const * ptr(::CassResult const *p);

    ::CassResult const * backend() const;

    void free() const;

    size_t row_count() const;

    size_t column_count() const;

    error column_name(size_t index, char const **name,
            size_t *name_length) const;

    value_type column_type(size_t index) const;

    data_type const * column_data_type(size_t index) const;

    row const * first_row() const;

    bool has_more_pages() const;

    error paging_state_token(char const **paging_state,
            size_t *paging_state_size) const;
};

} // namespace cass

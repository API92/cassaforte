/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include "delete_defaults.hpp"
#include "forward.hpp"
#include "impexp.hpp"

typedef struct CassPrepared_ CassPrepared;

namespace cass {

class CASSA_IMPEXP prepared : delete_defaults {
public:
    static prepared const * ptr(::CassPrepared const *p);

    ::CassPrepared const * backend() const;

    void free() const;

    statement_ptr bind() const;

    error parameter_name(size_t index, char const **name,
            size_t *name_length);

    data_type const * parameter_data_type(size_t index) const;
    data_type const * parameter_data_type_by_name(
            char const *name) const;
    data_type const * parameter_data_type_by_name_n(
            char const *name, size_t name_length) const;
};

} // namespace cass

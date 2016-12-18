/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include "delete_defaults.hpp"
#include "forward.hpp"
#include "impexp.hpp"

typedef struct CassAggregateMeta_ CassAggregateMeta;

namespace cass {

class CASSA_IMPEXP aggregate_meta : delete_defaults {
public:
    static aggregate_meta const * ptr(::CassAggregateMeta const *p);

    ::CassAggregateMeta const * backend() const;

    void name(char const **name, size_t *name_length) const;

    void full_name(char const **full_name, size_t *full_name_length) const;

    size_t argument_count() const;

    data_type const * argument_type(size_t index) const;

    data_type const * return_type() const;

    data_type const * state_type() const;

    function_meta const * state_func() const;

    function_meta const * final_func() const;

    value const * init_cond() const;

    value const * field_by_name(char const *name) const;
    value const * field_by_name_n(char const *name, size_t name_length) const;
};

} // namespace cass

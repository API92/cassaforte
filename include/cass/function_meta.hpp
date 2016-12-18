/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include "delete_defaults.hpp"
#include "forward.hpp"
#include "impexp.hpp"

typedef struct CassFunctionMeta_ CassFunctionMeta;

namespace cass {

class CASSA_IMPEXP function_meta : delete_defaults {
public:
    static function_meta const * ptr(::CassFunctionMeta const *p);

    ::CassFunctionMeta const * backend() const;

    void name(char const **name, size_t *name_length) const;

    void full_name(char const **full_name,
            size_t *full_name_length) const;

    void body(char const **body, size_t *body_length) const;

    void language(char const **language, size_t *language_length) const;

    bool called_on_null_input() const;

    size_t argument_count() const;

    error argument(size_t index, char const **name,
            size_t *name_length, data_type const **type) const;

    data_type const * argument_type_by_name(char const *name) const;
    data_type const * argument_type_by_name_n(
            char const *name, size_t name_length) const;

    data_type const * return_type() const;

    value const * field_by_name(char const *name) const;
    value const * field_by_name_n(char const *name, size_t name_length) const;
};

} // namespace cass

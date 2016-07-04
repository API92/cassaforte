/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/defs.hpp>
#include <cass/impexp.hpp>
#include <cass/wrapper_ptr.hpp>

namespace cass {

typedef dummy_ptr<class function_meta const> function_meta_const_ptr;

class function_meta {
public:
    explicit function_meta(::CassFunctionMeta const *p) : p(p) {}
    ::CassFunctionMeta const * backend() const { return p; }

    inline void name(char const **name, size_t *name_length) const;

    inline void full_name(char const **full_name,
            size_t *full_name_length) const;

    inline void body(char const **body, size_t *body_length) const;

    inline void language(char const **language, size_t *language_length) const;

    inline bool called_on_null_input() const;

    inline size_t argument_count() const;

    CASSA_IMPEXP error argument(size_t index, char const **name,
            size_t *name_length, data_type_const_ptr *type) const;

    CASSA_IMPEXP data_type_const_ptr argument_type_by_name(
            char const *name) const;
    CASSA_IMPEXP data_type_const_ptr argument_type_by_name_n(
            char const *name, size_t name_length) const;

    CASSA_IMPEXP data_type_const_ptr return_type() const;

    CASSA_IMPEXP value_const_ptr field_by_name(char const *name) const;
    CASSA_IMPEXP value_const_ptr field_by_name_n(char const *name,
            size_t name_length) const;

private:
    ::CassFunctionMeta const *p;
};

inline void function_meta::name(char const **name, size_t *name_length) const
{
    ::cass_function_meta_name(p, name, name_length);
}

inline void function_meta::full_name(char const **full_name,
        size_t *full_name_length) const
{
    ::cass_function_meta_full_name(p, full_name, full_name_length);
}

inline void function_meta::body(char const **body, size_t *body_length) const
{
    ::cass_function_meta_body(p, body, body_length);
}

inline void function_meta::language(char const **language,
        size_t *language_length) const
{
    ::cass_function_meta_language(p, language, language_length);
}

inline bool function_meta::called_on_null_input() const
{
    return ::cass_function_meta_called_on_null_input(p) == cass_true;
}

inline size_t function_meta::argument_count() const
{
    return ::cass_function_meta_argument_count(p);
}

} // namespace cass

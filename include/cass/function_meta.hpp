/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/defs.hpp>
#include <cass/impexp.hpp>
#include <cass/wrapper_ptr.hpp>

namespace cass {

class function_meta : wrapper {
public:
    static function_meta const * ptr(::CassFunctionMeta const *p)
    {
        return reinterpret_cast<function_meta const *>(p);
    }

    ::CassFunctionMeta const * backend() const
    {
        return reinterpret_cast<::CassFunctionMeta const *>(this);
    }

    inline void name(char const **name, size_t *name_length) const;

    inline void full_name(char const **full_name,
            size_t *full_name_length) const;

    inline void body(char const **body, size_t *body_length) const;

    inline void language(char const **language, size_t *language_length) const;

    inline bool called_on_null_input() const;

    inline size_t argument_count() const;

    inline error argument(size_t index, char const **name,
            size_t *name_length, data_type const **type) const;

    CASSA_IMPEXP data_type const * argument_type_by_name(
            char const *name) const;
    CASSA_IMPEXP data_type const * argument_type_by_name_n(
            char const *name, size_t name_length) const;

    CASSA_IMPEXP data_type const * return_type() const;

    CASSA_IMPEXP value const * field_by_name(char const *name) const;
    CASSA_IMPEXP value const * field_by_name_n(char const *name,
            size_t name_length) const;
};

inline void function_meta::name(char const **name, size_t *name_length) const
{
    ::cass_function_meta_name(backend(), name, name_length);
}

inline void function_meta::full_name(char const **full_name,
        size_t *full_name_length) const
{
    ::cass_function_meta_full_name(backend(), full_name, full_name_length);
}

inline void function_meta::body(char const **body, size_t *body_length) const
{
    ::cass_function_meta_body(backend(), body, body_length);
}

inline void function_meta::language(char const **language,
        size_t *language_length) const
{
    ::cass_function_meta_language(backend(), language, language_length);
}

inline bool function_meta::called_on_null_input() const
{
    return ::cass_function_meta_called_on_null_input(backend()) == cass_true;
}

inline size_t function_meta::argument_count() const
{
    return ::cass_function_meta_argument_count(backend());
}

error function_meta::argument(size_t index, char const **name,
        size_t *name_length, data_type const **type) const
{
    return error(::cass_function_meta_argument(
            backend(), index, name, name_length,
            reinterpret_cast<::CassDataType const **>(type)));
}

} // namespace cass

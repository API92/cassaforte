/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/defs.hpp>
#include <cass/impexp.hpp>
#include <cass/wrapper_ptr.hpp>

namespace cass {

typedef wrapper_ptr<prepared const> prepared_const_ptr;

class prepared : wrapper {
public:
    static prepared const * ptr(::CassPrepared const *p)
    {
        return reinterpret_cast<prepared const *>(p);
    }

    ::CassPrepared const * backend() const
    {
        return reinterpret_cast<::CassPrepared const *>(this);
    }

    inline void free() const;

    CASSA_IMPEXP statement_ptr bind() const;

    inline error parameter_name(size_t index, char const **name,
            size_t *name_length);

    CASSA_IMPEXP data_type const * parameter_data_type(size_t index) const;
    CASSA_IMPEXP data_type const * parameter_data_type_by_name(
            char const *name) const;
    CASSA_IMPEXP data_type const * parameter_data_type_by_name_n(
            char const *name, size_t name_length) const;
};

inline void prepared::free() const
{
    ::cass_prepared_free(backend());
}

inline error prepared::parameter_name(size_t index, char const **name,
        size_t *name_length)
{
    return (error)::cass_prepared_parameter_name(
            backend(), index, name, name_length);
}

} // namespace cass

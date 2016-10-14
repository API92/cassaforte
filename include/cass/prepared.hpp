/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/defs.hpp>
#include <cass/impexp.hpp>
#include <cass/wrapper_ptr.hpp>

namespace cass {

typedef wrapper_const_ptr<class prepared const> prepared_const_ptr;

class prepared {
public:
    explicit prepared(::CassPrepared const *p) : p(p) {}
    ::CassPrepared const * backend() const { return p; }

    inline static void free(prepared const p);

    CASSA_IMPEXP statement_ptr bind() const;

    inline error parameter_name(size_t index, char const **name,
            size_t *name_length);

    CASSA_IMPEXP data_type_const_ptr parameter_data_type(size_t index) const;
    CASSA_IMPEXP data_type_const_ptr parameter_data_type_by_name(
            char const *name);
    CASSA_IMPEXP data_type_const_ptr parameter_data_type_by_name_n(
            char const *name, size_t name_length);

private:
    ::CassPrepared const *p;
};

inline void prepared::free(prepared const p)
{
    ::cass_prepared_free(p.p);
}

inline error prepared::parameter_name(size_t index, char const **name,
        size_t *name_length)
{
    return (error)::cass_prepared_parameter_name(p, index, name, name_length);
}

} // namespace cass

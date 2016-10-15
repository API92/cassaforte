/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/defs.hpp>
#include <cass/wrapper_ptr.hpp>

namespace cass {

class aggregate_meta {
public:
    static aggregate_meta const * ptr(::CassAggregateMeta const *p)
    {
        return reinterpret_cast<aggregate_meta const *>(p);
    }

    ::CassAggregateMeta const * backend() const
    {
        return reinterpret_cast<::CassAggregateMeta const *>(this);
    }

    inline void name(char const **name, size_t *name_length) const;

    inline void full_name(char const **full_name,
            size_t *full_name_length) const;

    inline size_t argument_count() const;

    CASSA_IMPEXP data_type_const_ptr argument_type(size_t index) const;

    CASSA_IMPEXP data_type_const_ptr return_type() const;

    CASSA_IMPEXP data_type_const_ptr state_type() const;

    CASSA_IMPEXP function_meta const * state_func() const;

    CASSA_IMPEXP function_meta const * final_func() const;

    CASSA_IMPEXP value const * init_cond() const;

    CASSA_IMPEXP value const * field_by_name(char const *name) const;
    CASSA_IMPEXP value const * field_by_name_n(char const *name,
            size_t name_length) const;
};

inline void aggregate_meta::name(char const **name, size_t *name_length) const
{
    ::cass_aggregate_meta_name(backend(), name, name_length);
}

inline void aggregate_meta::full_name(char const **full_name,
        size_t *full_name_length) const
{
    ::cass_aggregate_meta_full_name(backend(), full_name, full_name_length);
}

inline size_t aggregate_meta::argument_count() const
{
    return ::cass_aggregate_meta_argument_count(backend());
}

} // namespace cass

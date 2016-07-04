/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/defs.hpp>
#include <cass/wrapper_ptr.hpp>

namespace cass {

typedef dummy_ptr<class aggregate_meta const> aggregate_meta_const_ptr;

class aggregate_meta {
public:
    explicit aggregate_meta(::CassAggregateMeta const *p) : p(p) {}
    ::CassAggregateMeta const * backend() const { return p; }

    inline void name(char const **name, size_t *name_length) const;

    inline void full_name(char const **full_name,
            size_t *full_name_length) const;

    inline size_t argument_count() const;

    CASSA_IMPEXP data_type_const_ptr argument_type(size_t index) const;

    CASSA_IMPEXP data_type_const_ptr return_type() const;

    CASSA_IMPEXP data_type_const_ptr state_type() const;

    CASSA_IMPEXP function_meta_const_ptr state_func() const;

    CASSA_IMPEXP function_meta_const_ptr final_func() const;

    CASSA_IMPEXP value_const_ptr init_cond() const;

    CASSA_IMPEXP value_const_ptr field_by_name(char const *name) const;
    CASSA_IMPEXP value_const_ptr field_by_name_n(char const *name,
            size_t name_length) const;

private:
    ::CassAggregateMeta const *p;
};

inline void aggregate_meta::name(char const **name, size_t *name_length) const
{
    ::cass_aggregate_meta_name(p, name, name_length);
}

inline void aggregate_meta::full_name(char const **full_name,
        size_t *full_name_length) const
{
    ::cass_aggregate_meta_full_name(p, full_name, full_name_length);
}

inline size_t aggregate_meta::argument_count() const
{
    return ::cass_aggregate_meta_argument_count(p);
}

} // namespace cass

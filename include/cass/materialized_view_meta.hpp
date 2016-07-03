/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/defs.hpp>
#include <cass/impexp.hpp>
#include <cass/wrapper_ptr.hpp>

namespace cass {

typedef dummy_ptr<class materialized_view_meta const>
    materialized_view_meta_const_ptr;

class materialized_view_meta {
public:
    explicit materialized_view_meta(::CassMaterializedViewMeta const *p) :
        p(p) {}
    ::CassMaterializedViewMeta const * backend() const { return p; }

    CASSA_IMPEXP column_meta_const_ptr column_by_name(char const *column) const;
    CASSA_IMPEXP column_meta_const_ptr column_by_name_n(
            char const *column, size_t column_length) const;

    inline void name(char const **name, size_t *name_length) const;

    CASSA_IMPEXP table_meta_const_ptr base_table() const;

    inline size_t column_count() const;

    CASSA_IMPEXP column_meta_const_ptr column(size_t index) const;

    inline size_t partition_key_count() const;

    CASSA_IMPEXP column_meta_const_ptr partition_key(size_t index) const;

    inline size_t clustering_key_count() const;

    CASSA_IMPEXP column_meta_const_ptr clustering_key(size_t index) const;

    inline clustering_order clustering_key_order(size_t index) const;

    CASSA_IMPEXP value_const_ptr field_by_name(char const *name) const;
    CASSA_IMPEXP value_const_ptr field_by_name_n(
            char const *name, size_t name_length) const;

private:
    ::CassMaterializedViewMeta const *p;
};

inline void materialized_view_meta::name(
        char const **name, size_t *name_length) const
{
    ::cass_materialized_view_meta_name(p, name, name_length);
}

inline size_t materialized_view_meta::column_count() const
{
    return ::cass_materialized_view_meta_column_count(p);
}

inline size_t materialized_view_meta::partition_key_count() const
{
    return ::cass_materialized_view_meta_partition_key_count(p);
}

inline size_t materialized_view_meta::clustering_key_count() const
{
    return ::cass_materialized_view_meta_clustering_key_count(p);
}

inline clustering_order materialized_view_meta::clustering_key_order(
        size_t index) const
{
    return ::cass_materialized_view_meta_clustering_key_order(p, index);
}

} // namespace cass

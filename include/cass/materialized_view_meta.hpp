/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/defs.hpp>
#include <cass/impexp.hpp>
#include <cass/wrapper_ptr.hpp>

namespace cass {

class materialized_view_meta : wrapper {
public:
    static materialized_view_meta const * ptr(
            ::CassMaterializedViewMeta const *p)
    {
        return reinterpret_cast<materialized_view_meta const *>(p);
    }

    ::CassMaterializedViewMeta const * backend() const
    {
        return reinterpret_cast<::CassMaterializedViewMeta const *>(this);
    }

    CASSA_IMPEXP column_meta const * column_by_name(char const *column) const;
    CASSA_IMPEXP column_meta const * column_by_name_n(
            char const *column, size_t column_length) const;

    inline void name(char const **name, size_t *name_length) const;

    CASSA_IMPEXP table_meta const * base_table() const;

    inline size_t column_count() const;

    CASSA_IMPEXP column_meta const * column(size_t index) const;

    inline size_t partition_key_count() const;

    CASSA_IMPEXP column_meta const * partition_key(size_t index) const;

    inline size_t clustering_key_count() const;

    CASSA_IMPEXP column_meta const * clustering_key(size_t index) const;

    inline clustering_order clustering_key_order(size_t index) const;

    CASSA_IMPEXP value const * field_by_name(char const *name) const;
    CASSA_IMPEXP value const * field_by_name_n(
            char const *name, size_t name_length) const;
};

inline void materialized_view_meta::name(
        char const **name, size_t *name_length) const
{
    ::cass_materialized_view_meta_name(backend(), name, name_length);
}

inline size_t materialized_view_meta::column_count() const
{
    return ::cass_materialized_view_meta_column_count(backend());
}

inline size_t materialized_view_meta::partition_key_count() const
{
    return ::cass_materialized_view_meta_partition_key_count(backend());
}

inline size_t materialized_view_meta::clustering_key_count() const
{
    return ::cass_materialized_view_meta_clustering_key_count(backend());
}

inline clustering_order materialized_view_meta::clustering_key_order(
        size_t index) const
{
    return ::cass_materialized_view_meta_clustering_key_order(backend(), index);
}

} // namespace cass

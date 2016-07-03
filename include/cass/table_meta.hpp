/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/defs.hpp>
#include <cass/impexp.hpp>
#include <cass/wrapper_ptr.hpp>

namespace cass {

typedef dummy_ptr<class table_meta const> table_meta_const_ptr;

class table_meta {
public:
    explicit table_meta(::CassTableMeta const *p) : p(p) {}
    ::CassTableMeta const * backend() const { return p; }

    inline void name(char const **name, size_t *name_length) const;

    CASSA_IMPEXP column_meta_const_ptr column_by_name(char const *column) const;
    CASSA_IMPEXP column_meta_const_ptr column_by_name_n(
            char const *column, size_t column_length) const;

    inline size_t column_count() const;

    CASSA_IMPEXP column_meta_const_ptr column(size_t index) const;

    CASSA_IMPEXP index_meta_const_ptr index_by_name(char const *index) const;
    CASSA_IMPEXP index_meta_const_ptr index_by_name_n(char const *index,
            size_t index_length) const;

    inline size_t index_count() const;

    CASSA_IMPEXP index_meta_const_ptr index(size_t index) const;

    CASSA_IMPEXP materialized_view_meta_const_ptr materialized_view_by_name(
            char const *view) const;
    CASSA_IMPEXP materialized_view_meta_const_ptr materialized_view_by_name_n(
            char const *view, size_t view_length) const;

    inline size_t materialized_view_count() const;

    CASSA_IMPEXP materialized_view_meta_const_ptr materialized_view(
            size_t index) const;

    inline size_t partition_key_count() const;

    CASSA_IMPEXP column_meta_const_ptr partition_key(size_t index) const;

    inline size_t clustering_key_count() const;

    CASSA_IMPEXP column_meta_const_ptr clustering_key(size_t index) const;

    inline clustering_order clustering_key_order(size_t index) const;

    CASSA_IMPEXP value_const_ptr field_by_name(char const *name);
    CASSA_IMPEXP value_const_ptr field_by_name_n(char const *name,
            size_t name_length);

private:
    ::CassTableMeta const *p;
};

inline void table_meta::name(char const **name, size_t *name_length) const
{
    ::cass_table_meta_name(p, name, name_length);
}

inline size_t table_meta::column_count() const
{
    return ::cass_table_meta_column_count(p);
}

inline size_t table_meta::index_count() const
{
    return ::cass_table_meta_index_count(p);
}

inline size_t table_meta::materialized_view_count() const
{
    return ::cass_table_meta_materialized_view_count(p);
}

inline size_t table_meta::partition_key_count() const
{
    return ::cass_table_meta_partition_key_count(p);
}

inline size_t table_meta::clustering_key_count() const
{
    return ::cass_table_meta_clustering_key_count(p);
}

inline clustering_order table_meta::clustering_key_order(size_t index) const
{
    return ::cass_table_meta_clustering_key_order(p, index);
}

} // namespace cass

/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include "delete_defaults.hpp"
#include "forward.hpp"
#include "impexp.hpp"

typedef struct CassTableMeta_ CassTableMeta;

namespace cass {

class CASSA_IMPEXP table_meta : delete_defaults {
public:
    static table_meta const * ptr(::CassTableMeta const *p);

    ::CassTableMeta const * backend() const;

    void name(char const **name, size_t *name_length) const;

    column_meta const * column_by_name(char const *column) const;
    column_meta const * column_by_name_n(
            char const *column, size_t column_length) const;

    size_t column_count() const;

    column_meta const * column(size_t index) const;

    index_meta const * index_by_name(char const *index) const;
    index_meta const * index_by_name_n(char const *index,
            size_t index_length) const;

    size_t index_count() const;

    index_meta const * index(size_t index) const;

    materialized_view_meta const * materialized_view_by_name(
            char const *view) const;
    materialized_view_meta const * materialized_view_by_name_n(
            char const *view, size_t view_length) const;

    size_t materialized_view_count() const;

    materialized_view_meta const * materialized_view(
            size_t index) const;

    size_t partition_key_count() const;

    column_meta const * partition_key(size_t index) const;

    size_t clustering_key_count() const;

    column_meta const * clustering_key(size_t index) const;

    clustering_order clustering_key_order(size_t index) const;

    value const * field_by_name(char const *name);
    value const * field_by_name_n(char const *name,
            size_t name_length);
};

} // namespace cass

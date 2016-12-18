/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include "delete_defaults.hpp"
#include "forward.hpp"
#include "impexp.hpp"

typedef struct CassMaterializedViewMeta_ CassMaterializedViewMeta;

namespace cass {

class CASSA_IMPEXP materialized_view_meta : delete_defaults {
public:
    static materialized_view_meta const * ptr(
            ::CassMaterializedViewMeta const *p);

    ::CassMaterializedViewMeta const * backend() const;

    column_meta const * column_by_name(char const *column) const;
    column_meta const * column_by_name_n(
            char const *column, size_t column_length) const;

    void name(char const **name, size_t *name_length) const;

    table_meta const * base_table() const;

    size_t column_count() const;

    column_meta const * column(size_t index) const;

    size_t partition_key_count() const;

    column_meta const * partition_key(size_t index) const;

    size_t clustering_key_count() const;

    column_meta const * clustering_key(size_t index) const;

    clustering_order clustering_key_order(size_t index) const;

    value const * field_by_name(char const *name) const;
    value const * field_by_name_n(
            char const *name, size_t name_length) const;
};

} // namespace cass

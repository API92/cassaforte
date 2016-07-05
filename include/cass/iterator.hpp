/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/column_meta.hpp>
#include <cass/defs.hpp>
#include <cass/impexp.hpp>
#include <cass/wrapper_ptr.hpp>

namespace cass {

typedef wrapper_ptr<class iterator> iterator_ptr;

class iterator {
public:
    explicit iterator(::CassIterator *p) : p(p) {}
    ::CassIterator * backend() { return p; }

    inline static void free(iterator const i);

    CASSA_IMPEXP static iterator_ptr from_result(cass::result const *result);

    CASSA_IMPEXP static iterator_ptr from_row(cass::row const *row);

    CASSA_IMPEXP static iterator_ptr from_collection(cass::value const *value);

    CASSA_IMPEXP static iterator_ptr from_map(cass::value const *value);

    CASSA_IMPEXP static iterator_ptr from_tuple(cass::value const *value);

    CASSA_IMPEXP static iterator_ptr fields_from_user_type(
            cass::value const *value);

    CASSA_IMPEXP static iterator_ptr keyspaces_from_schema_meta(
            cass::schema_meta const *schema_meta);

    CASSA_IMPEXP static iterator_ptr tables_from_keyspace_meta(
            cass::keyspace_meta const *keyspace_meta);

    CASSA_IMPEXP static iterator_ptr materialized_views_from_keyspace_meta(
            cass::keyspace_meta const *keyspace_meta);

    CASSA_IMPEXP static iterator_ptr user_types_from_keyspace_meta(
            cass::keyspace_meta const *keyspace_meta);

    CASSA_IMPEXP static iterator_ptr functions_from_keyspace_meta(
            cass::keyspace_meta const *keyspace_meta);

    CASSA_IMPEXP static iterator_ptr aggregates_from_keyspace_meta(
            cass::keyspace_meta const *keyspace_meta);

    CASSA_IMPEXP static iterator_ptr fields_from_keyspace_meta(
            cass::keyspace_meta const *keyspace_meta);

    CASSA_IMPEXP static iterator_ptr columns_from_table_meta(
            cass::table_meta const *table_meta);

    CASSA_IMPEXP static iterator_ptr indexes_from_table_meta(
            cass::table_meta const *table_meta);

    CASSA_IMPEXP static iterator_ptr materialized_views_from_table_meta(
            cass::table_meta const *table_meta);

    CASSA_IMPEXP static iterator_ptr fields_from_table_meta(
            cass::table_meta const *table_meta);

    CASSA_IMPEXP static iterator_ptr columns_from_materialized_view_meta(
            materialized_view_meta const *view_meta);

    CASSA_IMPEXP static iterator_ptr fields_from_materialized_view_meta(
            materialized_view_meta const *view_meta);

    CASSA_IMPEXP static iterator_ptr cass_iterator_fields_from_column_meta(
            cass::column_meta const *column_meta);

    inline iterator_type type();

private:
    ::CassIterator *p;
};

inline void iterator::free(iterator const i)
{
    ::cass_iterator_free(i.p);
}

inline iterator_type iterator::type()
{
    return ::cass_iterator_type(p);
}

} // namespace cass

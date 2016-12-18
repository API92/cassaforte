/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/schema_meta.hpp>

#include <cassandra.h>

#include <cass/keyspace_meta.hpp>
#include <cass/wrapper_ptr_def.hpp>

namespace cass {

schema_meta const * schema_meta::ptr(::CassSchemaMeta const *p)
{
    return reinterpret_cast<schema_meta const *>(p);
}

::CassSchemaMeta const * schema_meta::backend() const
{
    return reinterpret_cast<::CassSchemaMeta const *>(this);
}

void schema_meta::free() const
{
    ::cass_schema_meta_free(backend());
}

uint32_t schema_meta::snapshot_version() const
{
    return ::cass_schema_meta_snapshot_version(backend());
}

version schema_meta::version() const
{
    return ::cass_schema_meta_version(backend());
}

keyspace_meta const * const schema_meta::keyspace_by_name(
        char const *keyspace) const
{
    return keyspace_meta::ptr(::cass_schema_meta_keyspace_by_name(
                backend(), keyspace));
}

keyspace_meta const * const schema_meta::keyspace_by_name_n(
        char const *keyspace, size_t keyspace_length) const
{
    return keyspace_meta::ptr(::cass_schema_meta_keyspace_by_name_n(
                backend(), keyspace, keyspace_length));
}

template class wrapper_ptr<schema_meta const>;

} // namespace cass

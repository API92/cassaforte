/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cstdint>

#include <cassandra.h>

#include <cass/defs.hpp>
#include <cass/impexp.hpp>
#include <cass/wrapper_ptr.hpp>

namespace cass {

typedef wrapper_ptr<schema_meta const> schema_meta_const_ptr;

class schema_meta : wrapper {
public:
    static schema_meta const * ptr(::CassSchemaMeta const *p)
    {
        return reinterpret_cast<schema_meta const *>(p);
    }

    ::CassSchemaMeta const * backend() const
    {
        return reinterpret_cast<::CassSchemaMeta const *>(this);
    }

    inline void free() const;

    inline uint32_t snapshot_version() const;

    inline cass::version version() const;

    CASSA_IMPEXP keyspace_meta const * const keyspace_by_name(
            char const *keyspace) const;
    CASSA_IMPEXP keyspace_meta const * const keyspace_by_name_n(
            char const *keyspace, size_t keyspace_length) const;
};


inline void schema_meta::free() const
{
    ::cass_schema_meta_free(backend());
}

inline uint32_t schema_meta::snapshot_version() const
{
    return ::cass_schema_meta_snapshot_version(backend());
}

inline version schema_meta::version() const
{
    return ::cass_schema_meta_version(backend());
}

} // namespace cass

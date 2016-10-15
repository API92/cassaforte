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

typedef wrapper_const_ptr<class schema_meta const> schema_meta_const_ptr;

class schema_meta {
public:
    explicit schema_meta(::CassSchemaMeta const *p) : p(p) {}
    ::CassSchemaMeta const * backend() const { return p; }

    inline static void free(const schema_meta);

    inline uint32_t snapshot_version() const;

    inline cass::version version() const;

    CASSA_IMPEXP keyspace_meta const * const keyspace_by_name(
            char const *keyspace);
    CASSA_IMPEXP keyspace_meta const * const keyspace_by_name_n(
            char const *keyspace, size_t keyspace_length);

private:
    ::CassSchemaMeta const *p;
};


inline void schema_meta::free(const schema_meta s)
{
    ::cass_schema_meta_free(s.p);
}

inline uint32_t schema_meta::snapshot_version() const
{
    return ::cass_schema_meta_snapshot_version(p);
}

inline version schema_meta::version() const
{
    return ::cass_schema_meta_version(p);
}

} // namespace cass

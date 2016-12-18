/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include "delete_defaults.hpp"
#include "forward.hpp"
#include "impexp.hpp"

typedef struct CassSchemaMeta_ CassSchemaMeta;

namespace cass {

class CASSA_IMPEXP schema_meta : delete_defaults {
public:
    static schema_meta const * ptr(::CassSchemaMeta const *p);

    ::CassSchemaMeta const * backend() const;

    void free() const;

    uint32_t snapshot_version() const;

    cass::version version() const;

    keyspace_meta const * const keyspace_by_name(
            char const *keyspace) const;
    keyspace_meta const * const keyspace_by_name_n(
            char const *keyspace, size_t keyspace_length) const;
};

} // namespace cass

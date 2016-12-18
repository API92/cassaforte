/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include "delete_defaults.hpp"
#include "forward.hpp"
#include "impexp.hpp"

typedef struct CassSession_ CassSession;

namespace cass {

class CASSA_IMPEXP session : delete_defaults {
public:
    static session * ptr(::CassSession *p);

    ::CassSession * backend();
    ::CassSession const * backend() const;

    static session_ptr new_ptr();
    void free();

    future_ptr connect(cluster const *c);

    future_ptr connect_keyspace(cluster const *c, char const *keyspace);
    future_ptr connect_keyspace_n(cluster const *c, char const *keyspace,
            size_t keyspace_length);

    future_ptr close();

    future_ptr prepare(char const *query);

    future_ptr prepare_n(char const *query, size_t query_length);

    future_ptr execute(statement const *s);

    future_ptr execute_batch(batch const *b);

    schema_meta_const_ptr get_schema_meta() const;

    void get_metrics(metrics *output) const;
};

} // namespace cass

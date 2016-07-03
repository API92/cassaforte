/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/batch.hpp>
#include <cass/cluster.hpp>
#include <cass/defs.hpp>
#include <cass/future.hpp>
#include <cass/statement.hpp>
#include <cass/wrapper_ptr.hpp>

namespace cass {

typedef wrapper_const_ptr<class session const> session_const_ptr;
typedef wrapper_ptr<class session> session_ptr;

class session {
public:
    explicit session(::CassSession *p) : p(p) {}
    ::CassSession * backend() { return p; }
    ::CassSession const * backend() const { return p; }

    inline static session_ptr new_ptr();
    inline static void free(session const);

    inline future_ptr connect(cluster const *c);

    inline future_ptr connect_keyspace(cluster const *c, char const *keyspace);
    inline future_ptr connect_keyspace_n(cluster const *c, char const *keyspace,
            size_t keyspace_length);

    inline future_ptr close();

    inline future_ptr prepare(char const *query);

    inline future_ptr prepare_n(char const *query, size_t query_length);

    inline future_ptr execute(statement const *s);

    inline future_ptr execute_batch(batch const *b);

    CASSA_IMPEXP schema_meta_const_ptr get_schema_meta() const;

    inline void get_metrics(metrics *output) const;

private:
    ::CassSession *p;
};


inline session_ptr session::new_ptr()
{
    return session_ptr(session(::cass_session_new()), true);
}

inline void session::free(const session s)
{
    ::cass_session_free(s.p);
}

inline future_ptr session::connect(cluster const *c)
{
    return future_ptr(future(::cass_session_connect(p, c->backend())), true);
}

inline future_ptr session::connect_keyspace(cluster const *c,
        char const *keyspace)
{
    return future_ptr(future(::cass_session_connect_keyspace(p, c->backend(),
                    keyspace)), true);
}

inline future_ptr session::connect_keyspace_n(cluster const *c,
        char const *keyspace, size_t keyspace_length)
{
    return future_ptr(future(::cass_session_connect_keyspace_n(p, c->backend(),
                    keyspace, keyspace_length)), true);
}

inline future_ptr session::close()
{
    return future_ptr(future(::cass_session_close(p)), true);
}

inline future_ptr session::prepare(char const *query)
{
    return future_ptr(future(::cass_session_prepare(p, query)), true);
}

inline future_ptr session::prepare_n(char const *query, size_t query_length)
{
    return future_ptr(future(::cass_session_prepare_n(p, query, query_length)),
            true);
}

inline future_ptr session::execute(statement const *s)
{
    return future_ptr(future(::cass_session_execute(p, s->backend())), true);
}

inline future_ptr session::execute_batch(batch const *b)
{
    return future_ptr(future(::cass_session_execute_batch(p, b->backend())),
            true);
}

inline void session::get_metrics(metrics *output) const
{
    ::cass_session_get_metrics(p, output);
}

} // namespace cass

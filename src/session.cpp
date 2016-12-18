/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/session.hpp>

#include <cassandra.h>

#include <cass/batch.hpp>
#include <cass/cluster.hpp>
#include <cass/future.hpp>
#include <cass/schema_meta.hpp>
#include <cass/statement.hpp>
#include <cass/wrapper_ptr_def.hpp>

namespace cass {

session * session::ptr(::CassSession *p)
{
    return reinterpret_cast<session *>(p);
}

::CassSession * session::backend()
{
    return reinterpret_cast<::CassSession *>(this);
}

::CassSession const * session::backend() const
{
    return reinterpret_cast<::CassSession const *>(this);
}

schema_meta_const_ptr session::get_schema_meta() const
{
    return schema_meta_const_ptr(schema_meta::ptr(
                ::cass_session_get_schema_meta(backend())), true);
}

session_ptr session::new_ptr()
{
    return session_ptr(ptr(::cass_session_new()), true);
}

void session::free()
{
    ::cass_session_free(backend());
}

future_ptr session::connect(cluster const *c)
{
    return future_ptr(future::ptr(::cass_session_connect(
                    backend(), c->backend())), true);
}

future_ptr session::connect_keyspace(cluster const *c,
        char const *keyspace)
{
    return future_ptr(future::ptr(::cass_session_connect_keyspace(
                    backend(), c->backend(), keyspace)), true);
}

future_ptr session::connect_keyspace_n(cluster const *c,
        char const *keyspace, size_t keyspace_length)
{
    return future_ptr(future::ptr(::cass_session_connect_keyspace_n(
                    backend(), c->backend(), keyspace, keyspace_length)), true);
}

future_ptr session::close()
{
    return future_ptr(future::ptr(::cass_session_close(backend())), true);
}

future_ptr session::prepare(char const *query)
{
    return future_ptr(future::ptr(::cass_session_prepare(
                    backend(), query)), true);
}

future_ptr session::prepare_n(char const *query, size_t query_length)
{
    return future_ptr(future::ptr(::cass_session_prepare_n(
                    backend(), query, query_length)), true);
}

future_ptr session::execute(statement const *s)
{
    return future_ptr(future::ptr(::cass_session_execute(
                    backend(), s->backend())), true);
}

future_ptr session::execute_batch(batch const *b)
{
    return future_ptr(future::ptr(::cass_session_execute_batch(
                    backend(), b->backend())), true);
}

void session::get_metrics(metrics *output) const
{
    ::cass_session_get_metrics(backend(), output);
}

template class wrapper_ptr<session>;

} // namespace cass

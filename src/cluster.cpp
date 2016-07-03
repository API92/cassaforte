/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/authenticator.hpp>
#include <cass/cluster.hpp>
#include <cass/retry_policy.hpp>
#include <cass/ssl.hpp>
#include <cass/timestamp_gen.hpp>

#include <cassert>

namespace cass {

void cluster::set_ssl(ssl *ssl_context)
{
    assert(ssl_context);
    ::cass_cluster_set_ssl(p, ssl_context->backend());
}

error cluster::set_authenticator_callbacks(
        std::unique_ptr<authenticator_callbacks> exchange_cbs)
{
    assert(exchange_cbs);

    struct cb {
        static void init(::CassAuthenticator *auth, void *data) {
            authenticator w(auth);
            reinterpret_cast<authenticator_callbacks *>(data)->init(&w);
        }

        static void challenge(::CassAuthenticator *auth, void *data,
                char const *token, size_t token_size) {
            authenticator w(auth);
            reinterpret_cast<authenticator_callbacks *>(data)->challenge(
                    &w, token, token_size);
        }

        static void success(::CassAuthenticator *auth, void *data,
                char const *token, size_t token_size) {
            authenticator w(auth);
            reinterpret_cast<authenticator_callbacks *>(data)->success(
                    &w, token, token_size);
        }

        static void cleanup(::CassAuthenticator *auth, void *data) {
            authenticator w(auth);
            reinterpret_cast<authenticator_callbacks *>(data)->cleanup(&w);
        }

        static void data_cleanup(void *data) {
            delete reinterpret_cast<authenticator_callbacks *>(data);
        }
    };

    CassAuthenticatorCallbacks cbs = {};
    cbs.initial_callback = cb::init;
    cbs.challenge_callback = cb::challenge;
    cbs.success_callback = cb::success;
    cbs.cleanup_callback = cb::cleanup;

    // Exception can occur only in operator new().
    // So in case of exception pointer to exchange_cbs not saved and may be
    // deleted.
    // If no exception, then pointer to exchange_cbs saved and cb::data_cleanup
    // will be called. Therefore exchange_cbs.release() needed.
    error er = ::cass_cluster_set_authenticator_callbacks(p, &cbs,
            cb::data_cleanup, exchange_cbs.get());
    exchange_cbs.release();
    return er;
}

void cluster::set_timestamp_gen(timestamp_gen *gen)
{
    assert(gen);
    ::cass_cluster_set_timestamp_gen(p, gen->backend());
}

void cluster::set_retry_policy(retry_policy *policy)
{
    assert(policy);
    ::cass_cluster_set_retry_policy(p, policy->backend());
}

} // namespace cass

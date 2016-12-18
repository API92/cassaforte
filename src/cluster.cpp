/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/cluster.hpp>

#include <cassert>

#include <cassandra.h>

#include <cass/authenticator.hpp>
#include <cass/retry_policy.hpp>
#include <cass/ssl.hpp>
#include <cass/timestamp_gen.hpp>
#include <cass/wrapper_ptr_def.hpp>

namespace cass {

authenticator_callbacks::~authenticator_callbacks() {}
void authenticator_callbacks::init(authenticator *) {}
void authenticator_callbacks::challenge(authenticator *, char const *, size_t)
{
}

void authenticator_callbacks::success(authenticator *, char const *, size_t) {}
void authenticator_callbacks::cleanup(authenticator *) {}


void cluster::set_ssl(ssl *ssl_context)
{
    assert(ssl_context);
    ::cass_cluster_set_ssl(backend(), ssl_context->backend());
}

error cluster::set_authenticator_callbacks(
        std::unique_ptr<authenticator_callbacks> exchange_cbs)
{
    assert(exchange_cbs);

    struct cb {
        static void init(::CassAuthenticator *auth, void *data) {
            reinterpret_cast<authenticator_callbacks *>(data)->init(
                    authenticator::ptr(auth));
        }

        static void challenge(::CassAuthenticator *auth, void *data,
                char const *token, size_t token_size) {
            reinterpret_cast<authenticator_callbacks *>(data)->challenge(
                    authenticator::ptr(auth), token, token_size);
        }

        static void success(::CassAuthenticator *auth, void *data,
                char const *token, size_t token_size) {
            reinterpret_cast<authenticator_callbacks *>(data)->success(
                    authenticator::ptr(auth), token, token_size);
        }

        static void cleanup(::CassAuthenticator *auth, void *data) {
            reinterpret_cast<authenticator_callbacks *>(data)->cleanup(
                    authenticator::ptr(auth));
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
    error er = error(::cass_cluster_set_authenticator_callbacks(backend(), &cbs,
            cb::data_cleanup, exchange_cbs.get()));
    exchange_cbs.release();
    return er;
}

cluster * cluster::ptr(::CassCluster *p)
{
    return reinterpret_cast<cluster *>(p);
}

::CassCluster * cluster::backend()
{
    return reinterpret_cast<::CassCluster *>(this);
}

::CassCluster const * cluster::backend() const
{
    return reinterpret_cast<::CassCluster const *>(this);
}

void cluster::set_timestamp_gen(timestamp_gen *gen)
{
    assert(gen);
    ::cass_cluster_set_timestamp_gen(backend(), gen->backend());
}

void cluster::set_retry_policy(retry_policy *policy)
{
    assert(policy);
    ::cass_cluster_set_retry_policy(backend(), policy->backend());
}

cluster_ptr cluster::new_ptr()
{
    return cluster_ptr(cluster::ptr(cass_cluster_new()), true);
}

void cluster::free()
{
    ::cass_cluster_free(backend());
}

error cluster::set_contact_points(char const *cp)
{
    return error(::cass_cluster_set_contact_points(backend(), cp));
}

error cluster::set_contact_points_n(char const *cp, size_t len)
{
    return error(::cass_cluster_set_contact_points_n(backend(), cp, len));
}

error cluster::set_port(int port)
{
    return error(::cass_cluster_set_port(backend(), port));
}

error cluster::set_num_threads_io(unsigned num_threads)
{
    return error(::cass_cluster_set_num_threads_io(backend(), num_threads));
}

error cluster::set_queue_size_io(unsigned queue_size)
{
    return error(::cass_cluster_set_queue_size_io(backend(), queue_size));
}

error cluster::set_queue_size_event(unsigned queue_size)
{
    return error(::cass_cluster_set_queue_size_event(backend(), queue_size));
}

error cluster::set_core_connections_per_host(unsigned num_connections)
{
    return error(::cass_cluster_set_core_connections_per_host(
                backend(), num_connections));
}

error cluster::set_max_connections_per_host(unsigned num_connections)
{
    return error(::cass_cluster_set_max_connections_per_host(
                backend(), num_connections));
}

void cluster::set_reconnect_wait_time(unsigned wait_time)
{
    ::cass_cluster_set_reconnect_wait_time(backend(), wait_time);
}

error cluster::set_max_concurrent_creation(unsigned num_connections)
{
    return error(::cass_cluster_set_max_concurrent_creation(
                backend(), num_connections));
}

error cluster::set_max_concurrent_requests_threshold(unsigned num_req)
{
    return error(::cass_cluster_set_max_concurrent_requests_threshold(
                backend(), num_req));
}

error cluster::set_max_requests_per_flush(unsigned num_requests)
{
    return error(::cass_cluster_set_max_requests_per_flush(
                backend(), num_requests));
}

error cluster::set_write_bytes_high_water_mark(unsigned num_bytes)
{
    return error(::cass_cluster_set_write_bytes_high_water_mark(
                backend(), num_bytes));
}

error cluster::set_write_bytes_low_water_mark(unsigned num_bytes)
{
    return error(::cass_cluster_set_write_bytes_low_water_mark(
                backend(), num_bytes));
}

error cluster::set_pending_requests_high_water_mark(unsigned num_req)
{
    return error(::cass_cluster_set_pending_requests_high_water_mark(
                backend(), num_req));
}

error cluster::set_pending_requests_low_water_mark(unsigned num_requests)
{
    return error(::cass_cluster_set_pending_requests_low_water_mark(
                backend(), num_requests));
}

void cluster::set_connect_timeout(unsigned timeout_ms)
{
    return ::cass_cluster_set_connect_timeout(backend(), timeout_ms);
}

void cluster::set_request_timeout(unsigned timeout_ms)
{
    return ::cass_cluster_set_request_timeout(backend(), timeout_ms);
}

void cluster::set_resolve_timeout(unsigned timeout_ms)
{
    ::cass_cluster_set_resolve_timeout(backend(), timeout_ms);
}

void cluster::set_credentials(char const *username, char const *password)
{
    ::cass_cluster_set_credentials(backend(), username, password);
}

void cluster::set_credentials_n(
    char const *username, size_t username_length,
    char const *password, size_t password_length)
{
    ::cass_cluster_set_credentials_n(backend(), username, username_length,
            password, password_length);
}

void cluster::set_load_balance_round_robin()
{
    ::cass_cluster_set_load_balance_round_robin(backend());
}

error cluster::set_load_balance_dc_aware(char const *local_dc,
        unsigned used_hosts_per_remote_dc,
        bool allow_remote_dcs_for_local_cl)
{
    return error(::cass_cluster_set_load_balance_dc_aware(backend(), local_dc,
            used_hosts_per_remote_dc,
            (allow_remote_dcs_for_local_cl ? cass_true : cass_false)));
}

error cluster::set_load_balance_dc_aware_n(char const *local_dc,
        size_t local_dc_length, unsigned used_hosts_per_remote_dc,
        bool allow_remote_dcs_for_local_cl)
{
    return error(::cass_cluster_set_load_balance_dc_aware_n(backend(), local_dc,
            local_dc_length, used_hosts_per_remote_dc,
            (allow_remote_dcs_for_local_cl ? cass_true : cass_false)));
}

void cluster::set_token_aware_routing(bool enabled)
{
    ::cass_cluster_set_token_aware_routing(backend(),
            (enabled ? cass_true : cass_false));
}

void cluster::set_latency_aware_routing(bool enabled)
{
    ::cass_cluster_set_latency_aware_routing(backend(),
            (enabled ? cass_true : cass_false));
}

void cluster::set_latency_aware_routing_settings(
        double exclusion_threshold,
        uint64_t scale_ms, uint64_t retry_period_ms,
        uint64_t update_rate_ms, uint64_t min_measured)
{
    ::cass_cluster_set_latency_aware_routing_settings(backend(),
            exclusion_threshold, scale_ms, retry_period_ms, update_rate_ms,
            min_measured);
}

void cluster::set_whitelist_filtering(char const *hosts)
{
    ::cass_cluster_set_whitelist_filtering(backend(), hosts);
}

void cluster::set_whitelist_filtering_n(char const *hosts,
        size_t hosts_length)
{
    ::cass_cluster_set_whitelist_filtering_n(backend(), hosts, hosts_length);
}

void cluster::set_blacklist_filtering(char const *hosts)
{
    ::cass_cluster_set_blacklist_filtering(backend(), hosts);
}

void cluster::set_blacklist_filtering_n(char const *hosts,
        size_t hosts_length)
{
    ::cass_cluster_set_blacklist_filtering_n(backend(), hosts, hosts_length);
}

void cluster::set_whitelist_dc_filtering(char const *dcs)
{
    ::cass_cluster_set_whitelist_dc_filtering(backend(), dcs);
}

void cluster::set_whitelist_dc_filtering_n(char const *dcs,
        size_t dcs_length)
{
    ::cass_cluster_set_whitelist_dc_filtering_n(backend(), dcs, dcs_length);
}

void cluster::set_blacklist_dc_filtering(char const *dcs)
{
    ::cass_cluster_set_blacklist_dc_filtering(backend(), dcs);
}

void cluster::set_blacklist_dc_filtering_n(char const *dcs,
        size_t dcs_length)
{
    ::cass_cluster_set_blacklist_dc_filtering_n(backend(), dcs, dcs_length);
}

void cluster::set_tcp_keepalive(bool enabled, unsigned delay_secs)
{
    ::cass_cluster_set_tcp_keepalive(backend(),
            (enabled ? cass_true : cass_false), delay_secs);
}

void cluster::set_connection_heartbeat_interval(unsigned interval_secs)
{
    ::cass_cluster_set_connection_heartbeat_interval(backend(), interval_secs);
}

void cluster::set_connection_idle_timeout(unsigned timeout_secs)
{
    ::cass_cluster_set_connection_idle_timeout(backend(), timeout_secs);
}

void cluster::set_use_schema(bool enabled)
{
    ::cass_cluster_set_use_schema(
            backend(), (enabled ? cass_true : cass_false));
}

error cluster::set_use_hostname_resolution(bool enabled)
{
    return error(::cass_cluster_set_use_hostname_resolution(backend(),
            (enabled ? cass_true : cass_false)));
}

template class wrapper_ptr<cluster>;

} // namespace cass

/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <memory>

#include <cassandra.h>

#include <cass/defs.hpp>
#include <cass/impexp.hpp>
#include <cass/wrapper_ptr.hpp>

namespace cass {

struct authenticator_callbacks {
    virtual ~authenticator_callbacks() {}
    virtual void init(authenticator *) {}
    virtual void challenge(authenticator *, char const * /*token*/,
            size_t /*token_size*/) {}
    virtual void success(authenticator *, char const * /*token*/,
            size_t /* token_size */) {}
    virtual void cleanup(authenticator *) {}
};

typedef wrapper_ptr<cluster> cluster_ptr;

class cluster : wrapper {
public:
    static cluster * ptr(::CassCluster *p)
    {
        return reinterpret_cast<cluster *>(p);
    }

    ::CassCluster * backend()
    {
        return reinterpret_cast<::CassCluster *>(this);
    }

    ::CassCluster const * backend() const
    {
        return reinterpret_cast<::CassCluster const *>(this);
    }

    inline static cluster_ptr new_ptr();

    inline void free();

    inline error set_contact_points(char const *contact_points);
    inline error set_contact_points_n(char const *contact_points, size_t len);

    inline error set_port(int port);

    CASSA_IMPEXP void set_ssl(ssl *ssl_context);

    CASSA_IMPEXP error set_authenticator_callbacks(
            std::unique_ptr<authenticator_callbacks> exchange_cbs);

    inline error set_num_threads_io(unsigned num_threads);

    inline error set_queue_size_io(unsigned queue_size);

    inline error set_queue_size_event(unsigned queue_size);

    inline error set_queue_size_log(unsigned queue_size);

    inline error set_core_connections_per_host(unsigned num_connections);

    inline error set_max_connections_per_host(unsigned num_connections);

    inline void set_reconnect_wait_time(unsigned wait_time);

    inline error set_max_concurrent_creation(unsigned num_connections);

    inline error set_max_concurrent_requests_threshold(unsigned num_requests);

    inline error set_max_requests_per_flush(unsigned num_requests);

    inline error set_write_bytes_high_water_mark(unsigned num_bytes);

    inline error set_write_bytes_low_water_mark(unsigned num_bytes);

    inline error set_pending_requests_high_water_mark(unsigned num_requests);

    inline error set_pending_requests_low_water_mark(unsigned num_requests);

    inline void set_connect_timeout(unsigned timeout_ms);

    inline void set_request_timeout(unsigned timeout_ms);

    inline void set_resolve_timeout(unsigned timeout_ms);

    inline void set_credentials(char const *username, char const *password);
    inline void set_credentials_n(char const *username, size_t username_length,
            char const *password, size_t password_length);

    inline void set_load_balance_round_robin();

    inline error set_load_balance_dc_aware(char const *local_dc,
            unsigned used_hosts_per_remote_dc,
            bool allow_remote_dcs_for_local_cl);
    inline error set_load_balance_dc_aware_n(char const *local_dc,
            size_t local_dc_length, unsigned used_hosts_per_remote_dc,
            bool allow_remote_dcs_for_local_cl);

    inline void set_token_aware_routing(bool enabled);

    inline void set_latency_aware_routing(bool enabled);

    inline void set_latency_aware_routing_settings(double exclusion_threshold,
            uint64_t scale_ms, uint64_t retry_period_ms,
            uint64_t update_rate_ms, uint64_t min_measured);

    inline void set_whitelist_filtering(char const *hosts);
    inline void set_whitelist_filtering_n(char const *hosts,
            size_t hosts_length);

    inline void set_blacklist_filtering(char const *hosts);
    inline void set_blacklist_filtering_n(char const *hosts,
            size_t hosts_length);

    inline void set_whitelist_dc_filtering(char const *dcs);
    inline void set_whitelist_dc_filtering_n(char const *dcs,
            size_t dcs_length);

    inline void set_blacklist_dc_filtering(char const *dcs);
    inline void set_blacklist_dc_filtering_n(char const *dcs,
            size_t dcs_length);

    inline void set_tcp_keepalive(bool enabled, unsigned delay_secs);

    CASSA_IMPEXP void set_timestamp_gen(timestamp_gen *gen);

    inline void set_connection_heartbeat_interval(unsigned interval_secs);

    inline void set_connection_idle_timeout(unsigned timeout_secs);

    CASSA_IMPEXP void set_retry_policy(retry_policy *policy);

    inline void set_use_schema(bool enabled);

    inline error set_use_hostname_resolution(bool enabled);
};


inline cluster_ptr cluster::new_ptr()
{
    return cluster_ptr(cluster::ptr(cass_cluster_new()), true);
}

inline void cluster::free()
{
    ::cass_cluster_free(backend());
}

inline error cluster::set_contact_points(char const *cp)
{
    return error(::cass_cluster_set_contact_points(backend(), cp));
}

inline error cluster::set_contact_points_n(char const *cp, size_t len)
{
    return error(::cass_cluster_set_contact_points_n(backend(), cp, len));
}

inline error cluster::set_port(int port)
{
    return error(::cass_cluster_set_port(backend(), port));
}

inline error cluster::set_num_threads_io(unsigned num_threads)
{
    return error(::cass_cluster_set_num_threads_io(backend(), num_threads));
}

inline error cluster::set_queue_size_io(unsigned queue_size)
{
    return error(::cass_cluster_set_queue_size_io(backend(), queue_size));
}

inline error cluster::set_queue_size_event(unsigned queue_size)
{
    return error(::cass_cluster_set_queue_size_event(backend(), queue_size));
}

inline error cluster::set_queue_size_log(unsigned queue_size)
{
    return error(::cass_cluster_set_queue_size_log(backend(), queue_size));
}

inline error cluster::set_core_connections_per_host(unsigned num_connections)
{
    return error(::cass_cluster_set_core_connections_per_host(
                backend(), num_connections));
}

inline error cluster::set_max_connections_per_host(unsigned num_connections)
{
    return error(::cass_cluster_set_max_connections_per_host(
                backend(), num_connections));
}

inline void cluster::set_reconnect_wait_time(unsigned wait_time)
{
    ::cass_cluster_set_reconnect_wait_time(backend(), wait_time);
}

inline error cluster::set_max_concurrent_creation(unsigned num_connections)
{
    return error(::cass_cluster_set_max_concurrent_creation(
                backend(), num_connections));
}

inline error cluster::set_max_concurrent_requests_threshold(unsigned num_req)
{
    return error(::cass_cluster_set_max_concurrent_requests_threshold(
                backend(), num_req));
}

inline error cluster::set_max_requests_per_flush(unsigned num_requests)
{
    return error(::cass_cluster_set_max_requests_per_flush(
                backend(), num_requests));
}

inline error cluster::set_write_bytes_high_water_mark(unsigned num_bytes)
{
    return error(::cass_cluster_set_write_bytes_high_water_mark(
                backend(), num_bytes));
}

inline error cluster::set_write_bytes_low_water_mark(unsigned num_bytes)
{
    return error(::cass_cluster_set_write_bytes_low_water_mark(
                backend(), num_bytes));
}

inline error cluster::set_pending_requests_high_water_mark(unsigned num_req)
{
    return error(::cass_cluster_set_pending_requests_high_water_mark(
                backend(), num_req));
}

inline error cluster::set_pending_requests_low_water_mark(unsigned num_requests)
{
    return error(::cass_cluster_set_pending_requests_low_water_mark(
                backend(), num_requests));
}

inline void cluster::set_connect_timeout(unsigned timeout_ms)
{
    return ::cass_cluster_set_connect_timeout(backend(), timeout_ms);
}

inline void cluster::set_request_timeout(unsigned timeout_ms)
{
    return ::cass_cluster_set_request_timeout(backend(), timeout_ms);
}

inline void cluster::set_resolve_timeout(unsigned timeout_ms)
{
    ::cass_cluster_set_resolve_timeout(backend(), timeout_ms);
}

inline void cluster::set_credentials(char const *username, char const *password)
{
    ::cass_cluster_set_credentials(backend(), username, password);
}

inline void cluster::set_credentials_n(
    char const *username, size_t username_length,
    char const *password, size_t password_length)
{
    ::cass_cluster_set_credentials_n(backend(), username, username_length,
            password, password_length);
}

inline void cluster::set_load_balance_round_robin()
{
    ::cass_cluster_set_load_balance_round_robin(backend());
}

inline error cluster::set_load_balance_dc_aware(char const *local_dc,
        unsigned used_hosts_per_remote_dc,
        bool allow_remote_dcs_for_local_cl)
{
    return error(::cass_cluster_set_load_balance_dc_aware(backend(), local_dc,
            used_hosts_per_remote_dc,
            (allow_remote_dcs_for_local_cl ? cass_true : cass_false)));
}

inline error cluster::set_load_balance_dc_aware_n(char const *local_dc,
        size_t local_dc_length, unsigned used_hosts_per_remote_dc,
        bool allow_remote_dcs_for_local_cl)
{
    return error(::cass_cluster_set_load_balance_dc_aware_n(backend(), local_dc,
            local_dc_length, used_hosts_per_remote_dc,
            (allow_remote_dcs_for_local_cl ? cass_true : cass_false)));
}

inline void cluster::set_token_aware_routing(bool enabled)
{
    ::cass_cluster_set_token_aware_routing(backend(),
            (enabled ? cass_true : cass_false));
}

inline void cluster::set_latency_aware_routing(bool enabled)
{
    ::cass_cluster_set_latency_aware_routing(backend(),
            (enabled ? cass_true : cass_false));
}

inline void cluster::set_latency_aware_routing_settings(
        double exclusion_threshold,
        uint64_t scale_ms, uint64_t retry_period_ms,
        uint64_t update_rate_ms, uint64_t min_measured)
{
    ::cass_cluster_set_latency_aware_routing_settings(backend(),
            exclusion_threshold, scale_ms, retry_period_ms, update_rate_ms,
            min_measured);
}

inline void cluster::set_whitelist_filtering(char const *hosts)
{
    ::cass_cluster_set_whitelist_filtering(backend(), hosts);
}

inline void cluster::set_whitelist_filtering_n(char const *hosts,
        size_t hosts_length)
{
    ::cass_cluster_set_whitelist_filtering_n(backend(), hosts, hosts_length);
}

inline void cluster::set_blacklist_filtering(char const *hosts)
{
    ::cass_cluster_set_blacklist_filtering(backend(), hosts);
}

inline void cluster::set_blacklist_filtering_n(char const *hosts,
        size_t hosts_length)
{
    ::cass_cluster_set_blacklist_filtering_n(backend(), hosts, hosts_length);
}

inline void cluster::set_whitelist_dc_filtering(char const *dcs)
{
    ::cass_cluster_set_whitelist_dc_filtering(backend(), dcs);
}

inline void cluster::set_whitelist_dc_filtering_n(char const *dcs,
        size_t dcs_length)
{
    ::cass_cluster_set_whitelist_dc_filtering_n(backend(), dcs, dcs_length);
}

inline void cluster::set_blacklist_dc_filtering(char const *dcs)
{
    ::cass_cluster_set_blacklist_dc_filtering(backend(), dcs);
}

inline void cluster::set_blacklist_dc_filtering_n(char const *dcs,
        size_t dcs_length)
{
    ::cass_cluster_set_blacklist_dc_filtering_n(backend(), dcs, dcs_length);
}

inline void cluster::set_tcp_keepalive(bool enabled, unsigned delay_secs)
{
    ::cass_cluster_set_tcp_keepalive(backend(),
            (enabled ? cass_true : cass_false), delay_secs);
}

inline void cluster::set_connection_heartbeat_interval(unsigned interval_secs)
{
    ::cass_cluster_set_connection_heartbeat_interval(backend(), interval_secs);
}

inline void cluster::set_connection_idle_timeout(unsigned timeout_secs)
{
    ::cass_cluster_set_connection_idle_timeout(backend(), timeout_secs);
}

inline void cluster::set_use_schema(bool enabled)
{
    ::cass_cluster_set_use_schema(
            backend(), (enabled ? cass_true : cass_false));
}

inline error cluster::set_use_hostname_resolution(bool enabled)
{
    return error(::cass_cluster_set_use_hostname_resolution(backend(),
            (enabled ? cass_true : cass_false)));
}

} // namespace cass

/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <memory>

#include "delete_defaults.hpp"
#include "forward.hpp"
#include "impexp.hpp"

typedef struct CassCluster_ CassCluster;

namespace cass {

struct CASSA_IMPEXP authenticator_callbacks {
    virtual ~authenticator_callbacks();
    virtual void init(authenticator *);
    virtual void challenge(authenticator *, char const * token,
            size_t token_size);
    virtual void success(authenticator *, char const *token, size_t token_size);
    virtual void cleanup(authenticator *);
};

class CASSA_IMPEXP cluster : delete_defaults {
public:
    static cluster * ptr(::CassCluster *p);

    ::CassCluster * backend();
    ::CassCluster const * backend() const;

    static cluster_ptr new_ptr();

    void free();

    error set_contact_points(char const *contact_points);
    error set_contact_points_n(char const *contact_points, size_t len);

    error set_port(int port);

    void set_ssl(ssl *ssl_context);

    error set_authenticator_callbacks(
            std::unique_ptr<authenticator_callbacks> exchange_cbs);

    error set_num_threads_io(unsigned num_threads);

    error set_queue_size_io(unsigned queue_size);

    error set_queue_size_event(unsigned queue_size);

    error set_core_connections_per_host(unsigned num_connections);

    error set_max_connections_per_host(unsigned num_connections);

    void set_reconnect_wait_time(unsigned wait_time);

    error set_max_concurrent_creation(unsigned num_connections);

    error set_max_concurrent_requests_threshold(unsigned num_requests);

    error set_max_requests_per_flush(unsigned num_requests);

    error set_write_bytes_high_water_mark(unsigned num_bytes);

    error set_write_bytes_low_water_mark(unsigned num_bytes);

    error set_pending_requests_high_water_mark(unsigned num_requests);

    error set_pending_requests_low_water_mark(unsigned num_requests);

    void set_connect_timeout(unsigned timeout_ms);

    void set_request_timeout(unsigned timeout_ms);

    void set_resolve_timeout(unsigned timeout_ms);

    void set_credentials(char const *username, char const *password);
    void set_credentials_n(char const *username, size_t username_length,
            char const *password, size_t password_length);

    void set_load_balance_round_robin();

    error set_load_balance_dc_aware(char const *local_dc,
            unsigned used_hosts_per_remote_dc,
            bool allow_remote_dcs_for_local_cl);
    error set_load_balance_dc_aware_n(char const *local_dc,
            size_t local_dc_length, unsigned used_hosts_per_remote_dc,
            bool allow_remote_dcs_for_local_cl);

    void set_token_aware_routing(bool enabled);

    void set_latency_aware_routing(bool enabled);

    void set_latency_aware_routing_settings(double exclusion_threshold,
            uint64_t scale_ms, uint64_t retry_period_ms,
            uint64_t update_rate_ms, uint64_t min_measured);

    void set_whitelist_filtering(char const *hosts);
    void set_whitelist_filtering_n(char const *hosts,
            size_t hosts_length);

    void set_blacklist_filtering(char const *hosts);
    void set_blacklist_filtering_n(char const *hosts,
            size_t hosts_length);

    void set_whitelist_dc_filtering(char const *dcs);
    void set_whitelist_dc_filtering_n(char const *dcs,
            size_t dcs_length);

    void set_blacklist_dc_filtering(char const *dcs);
    void set_blacklist_dc_filtering_n(char const *dcs,
            size_t dcs_length);

    void set_tcp_keepalive(bool enabled, unsigned delay_secs);

    void set_timestamp_gen(timestamp_gen *gen);

    void set_connection_heartbeat_interval(unsigned interval_secs);

    void set_connection_idle_timeout(unsigned timeout_secs);

    void set_retry_policy(retry_policy *policy);

    void set_use_schema(bool enabled);

    error set_use_hostname_resolution(bool enabled);
};

} // namespace cass

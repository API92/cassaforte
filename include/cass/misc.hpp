/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/defs.hpp>

namespace cass {

inline char const * consistency_string(cass::consistency consistency)
{
    return ::cass_consistency_string(consistency);
}

inline char const * write_type_string(write_type type)
{
    return ::cass_write_type_string(type);
}

inline char const * error_desc(cass::error error)
{
    return ::cass_error_desc(static_cast<::CassError>(error));
}

inline void log_set_level(cass::log_level log_level)
{
    ::cass_log_set_level(log_level);
}

inline void log_set_callback(log_callback callback, void *data)
{
    ::cass_log_set_callback(callback, data);
}

inline char const * log_level_string(cass::log_level log_level)
{
    return ::cass_log_level_string(log_level);
}

inline uint32_t date_from_epoch(int64_t epoch_secs)
{
    return ::cass_date_from_epoch(epoch_secs);
}

inline int64_t time_from_epoch(int64_t epoch_secs)
{
    return ::cass_time_from_epoch(epoch_secs);
}

inline int64_t date_time_to_epoch(uint32_t date, int64_t time)
{
    return ::cass_date_time_to_epoch(date, time);
}

} // namespace cass

/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/misc.hpp>

#include <cassandra.h>

namespace cass {

char const * consistency_string(cass::consistency consistency)
{
    return ::cass_consistency_string((::CassConsistency)consistency);
}

char const * write_type_string(write_type type)
{
    return ::cass_write_type_string((::CassWriteType)type);
}

char const * error_desc(cass::error error)
{
    return ::cass_error_desc(static_cast<::CassError>(error));
}

void log_set_level(cass::log_level log_level)
{
    ::cass_log_set_level((::CassLogLevel)log_level);
}

void log_set_callback(log_callback callback, void *data)
{
    ::cass_log_set_callback(callback, data);
}

char const * log_level_string(cass::log_level log_level)
{
    return ::cass_log_level_string((::CassLogLevel)log_level);
}

uint32_t date_from_epoch(int64_t epoch_secs)
{
    return ::cass_date_from_epoch(epoch_secs);
}

int64_t time_from_epoch(int64_t epoch_secs)
{
    return ::cass_time_from_epoch(epoch_secs);
}

int64_t date_time_to_epoch(uint32_t date, int64_t time)
{
    return ::cass_date_time_to_epoch(date, time);
}

} // namespace cass

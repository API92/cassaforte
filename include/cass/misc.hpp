/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include "forward.hpp"
#include "impexp.hpp"

namespace cass {

CASSA_IMPEXP char const * consistency_string(cass::consistency consistency);

CASSA_IMPEXP char const * write_type_string(write_type type);

CASSA_IMPEXP char const * error_desc(cass::error error);

CASSA_IMPEXP void log_set_level(cass::log_level log_level);

CASSA_IMPEXP void log_set_callback(log_callback callback, void *data);

CASSA_IMPEXP char const * log_level_string(cass::log_level log_level);

CASSA_IMPEXP uint32_t date_from_epoch(int64_t epoch_secs);

CASSA_IMPEXP int64_t time_from_epoch(int64_t epoch_secs);

CASSA_IMPEXP int64_t date_time_to_epoch(uint32_t date, int64_t time);

} // namespace cass

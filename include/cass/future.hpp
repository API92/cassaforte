/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/defs.hpp>
#include <cass/impexp.hpp>
#include <cass/wrapper_ptr.hpp>

namespace cass {

typedef wrapper_ptr<future> future_ptr;

class future : wrapper {
public:
    typedef ::CassFutureCallback callback;

    static future * ptr(::CassFuture *p)
    {
        return reinterpret_cast<future *>(p);
    }

    ::CassFuture * backend()
    {
        return reinterpret_cast<::CassFuture *>(this);
    }

    ::CassFuture const * backend() const
    {
        return reinterpret_cast<::CassFuture const *>(this);
    }

    inline void free();

    inline error set_callback(future::callback callback, void *data);

    inline bool ready();

    inline void wait();

    inline bool wait_timed(duration_t timeout_us);

    CASSA_IMPEXP result_const_ptr get_result();

    CASSA_IMPEXP error_result_const_ptr get_error_result();

    CASSA_IMPEXP prepared_const_ptr get_prepared();

    inline error error_code();

    inline void error_message(char const **message, size_t *message_length);

    inline size_t custom_payload_item_count();

    inline error custom_payload_item(size_t index, char const **name,
            size_t *name_length, byte_t const **value, size_t *value_size);
};

inline void future::free()
{
    ::cass_future_free(backend());
}

inline error future::set_callback(future::callback callback, void *data)
{
    return (error)::cass_future_set_callback(backend(), callback, data);
}

inline bool future::ready()
{
    return ::cass_future_ready(backend()) == cass_true;
}

inline void future::wait()
{
    ::cass_future_wait(backend());
}

inline bool future::wait_timed(duration_t timeout_us)
{
    return ::cass_future_wait_timed(backend(), timeout_us) == cass_true;
}

inline error future::error_code()
{
    return (error)::cass_future_error_code(backend());
}

inline void future::error_message(char const **message, size_t *message_length)
{
    return ::cass_future_error_message(backend(), message, message_length);
}

inline size_t future::custom_payload_item_count()
{
    return ::cass_future_custom_payload_item_count(backend());
}

inline error future::custom_payload_item(size_t index, char const **name,
        size_t *name_length, byte_t const **value, size_t *value_size)
{
    return (error)::cass_future_custom_payload_item(
            backend(), index, name, name_length, value, value_size);
}

} // namespace cass

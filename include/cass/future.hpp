/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/defs.hpp>
#include <cass/impexp.hpp>
#include <cass/wrapper_ptr.hpp>

namespace cass {

typedef wrapper_ptr<class future> future_ptr;

class future {
public:
    typedef ::CassFutureCallback callback;

    explicit future(::CassFuture *p) : p(p) {}
    ::CassFuture * backend() { return p; }
    ::CassFuture const * backend() const { return p; }

    inline static void free(const future);

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

private:
    ::CassFuture *p;
};

inline void future::free(const future f)
{
    ::cass_future_free(f.p);
}

inline error future::set_callback(future::callback callback, void *data)
{
    return ::cass_future_set_callback(p, callback, data);
}

inline bool future::ready()
{
    return ::cass_future_ready(p) == cass_true;
}

inline void future::wait()
{
    ::cass_future_wait(p);
}

inline bool future::wait_timed(duration_t timeout_us)
{
    return ::cass_future_wait_timed(p, timeout_us) == cass_true;
}

inline error future::error_code()
{
    return ::cass_future_error_code(p);
}

inline void future::error_message(char const **message, size_t *message_length)
{
    return ::cass_future_error_message(p, message, message_length);
}

inline size_t future::custom_payload_item_count()
{
    return ::cass_future_custom_payload_item_count(p);
}

inline error future::custom_payload_item(size_t index, char const **name,
        size_t *name_length, byte_t const **value, size_t *value_size)
{
    return ::cass_future_custom_payload_item(p, index, name, name_length,
            value, value_size);
}

} // namespace cass

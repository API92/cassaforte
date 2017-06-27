/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/future.hpp>

#include <cassandra.h>

#include <cass/error_result.hpp>
#include <cass/prepared.hpp>
#include <cass/result.hpp>
#include <cass/wrapper_ptr_def.hpp>

namespace cass {

future * future::ptr(::CassFuture *p)
{
    return reinterpret_cast<future *>(p);
}

::CassFuture * future::backend()
{
    return reinterpret_cast<::CassFuture *>(this);
}

::CassFuture const * future::backend() const
{
    return reinterpret_cast<::CassFuture const *>(this);
}

result_const_ptr future::get_result()
{
    ::CassResult const * res = ::cass_future_get_result(backend());
    return result_const_ptr(result::ptr(res));
}

error_result_const_ptr future::get_error_result()
{
    ::CassErrorResult const * res = ::cass_future_get_error_result(backend());
    return error_result_const_ptr(error_result::ptr(res));
}

prepared_const_ptr future::get_prepared()
{
    ::CassPrepared const * pr = ::cass_future_get_prepared(backend());
    return prepared_const_ptr(prepared::ptr(pr));
}

void future::free()
{
    ::cass_future_free(backend());
}

error future::set_callback(future::callback callback, void *data)
{
    return (error)::cass_future_set_callback(backend(), callback, data);
}

bool future::ready()
{
    return ::cass_future_ready(backend()) == cass_true;
}

void future::wait()
{
    ::cass_future_wait(backend());
}

bool future::wait_timed(duration_t timeout_us)
{
    return ::cass_future_wait_timed(backend(), timeout_us) == cass_true;
}

error future::error_code()
{
    return (error)::cass_future_error_code(backend());
}

void future::error_message(char const **message, size_t *message_length)
{
    return ::cass_future_error_message(backend(), message, message_length);
}

size_t future::custom_payload_item_count()
{
    return ::cass_future_custom_payload_item_count(backend());
}

error future::custom_payload_item(size_t index, char const **name,
        size_t *name_length, std::byte const **value, size_t *value_size)
{
    return (error)::cass_future_custom_payload_item(
            backend(), index, name, name_length,
            (cass_byte_t const **)value, value_size);
}

template class wrapper_ptr<future>;

} // namespace cass

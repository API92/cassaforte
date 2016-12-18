/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/custom_payload.hpp>

#include <cassandra.h>

#include <cass/wrapper_ptr_def.hpp>

namespace cass {

custom_payload * custom_payload::ptr(::CassCustomPayload *p)
{
    return reinterpret_cast<custom_payload *>(p);
}

::CassCustomPayload * custom_payload::backend()
{
    return reinterpret_cast<::CassCustomPayload *>(this);
}

::CassCustomPayload const * custom_payload::backend() const
{
    return reinterpret_cast<::CassCustomPayload const *>(this);
}

void custom_payload::free()
{
    ::cass_custom_payload_free(backend());
}

custom_payload_ptr custom_payload::new_ptr()
{
    return custom_payload_ptr(custom_payload::ptr(::cass_custom_payload_new()),
            true);
}

void custom_payload::set(char const *name, byte_t const *value,
        size_t value_size)
{
    ::cass_custom_payload_set(backend(), name, value, value_size);
}

void custom_payload::set_n(char const *name, size_t name_length,
        byte_t const *value, size_t value_size)
{
    ::cass_custom_payload_set_n(backend(), name, name_length, value, value_size);
}

void custom_payload::remove(char const *name)
{
    ::cass_custom_payload_remove(backend(), name);
}

void custom_payload::remove_n(char const *name, size_t name_length)
{
    ::cass_custom_payload_remove_n(backend(), name, name_length);
}

template class wrapper_ptr<custom_payload>;

} // namespace cass

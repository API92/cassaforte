/*
 * Copyright (C) Andrey Pikas
 */

#include <cassandra.h>

#include <cass/defs.hpp>
#include <cass/wrapper_ptr.hpp>

namespace cass {

typedef wrapper_ptr<custom_payload> custom_payload_ptr;

class custom_payload : wrapper {
public:
    static custom_payload * ptr(::CassCustomPayload *p)
    {
        return reinterpret_cast<custom_payload *>(p);
    }

    ::CassCustomPayload * backend()
    {
        return reinterpret_cast<::CassCustomPayload *>(this);
    }

    ::CassCustomPayload const * backend() const
    {
        return reinterpret_cast<::CassCustomPayload const *>(this);
    }

    inline void free();

    inline static custom_payload_ptr new_ptr();

    inline void set(char const *name, byte_t const *value, size_t value_size);
    inline void set_n(char const *name, size_t name_length, byte_t const *value,
            size_t value_size);

    inline void remove(char const *name);
    inline void remove_n(char const *name, size_t name_length);
};

inline void custom_payload::free()
{
    ::cass_custom_payload_free(backend());
}

inline custom_payload_ptr custom_payload::new_ptr()
{
    return custom_payload_ptr(custom_payload::ptr(::cass_custom_payload_new()),
            true);
}

inline void custom_payload::set(char const *name, byte_t const *value,
        size_t value_size)
{
    ::cass_custom_payload_set(backend(), name, value, value_size);
}

inline void custom_payload::set_n(char const *name, size_t name_length,
        byte_t const *value, size_t value_size)
{
    ::cass_custom_payload_set_n(backend(), name, name_length, value, value_size);
}

inline void custom_payload::remove(char const *name)
{
    ::cass_custom_payload_remove(backend(), name);
}

inline void custom_payload::remove_n(char const *name, size_t name_length)
{
    ::cass_custom_payload_remove_n(backend(), name, name_length);
}

} // namespace cass

/*
 * Copyright (C) Andrey Pikas
 */

#include <cassandra.h>

#include <cass/defs.hpp>
#include <cass/wrapper_ptr.hpp>

namespace cass {

typedef wrapper_ptr<class custom_payload> custom_payload_ptr;

class custom_payload {
public:
    explicit custom_payload(::CassCustomPayload *p) : p(p) {}
    ::CassCustomPayload * backend() { return p; }
    ::CassCustomPayload const * backend() const { return p; }

    inline static void free(custom_payload const p);

    inline static custom_payload_ptr new_ptr();

    inline void set(char const *name, byte_t const *value, size_t value_size);
    inline void set_n(char const *name, size_t name_length, byte_t const *value,
            size_t value_size);

    inline void remove(char const *name);
    inline void remove_n(char const *name, size_t name_length);

private:
    ::CassCustomPayload *p;
};

inline void custom_payload::free(custom_payload const p)
{
    ::cass_custom_payload_free(p.p);
}

inline custom_payload_ptr custom_payload::new_ptr()
{
    return custom_payload_ptr(custom_payload(::cass_custom_payload_new()),
            true);
}

inline void custom_payload::set(char const *name, byte_t const *value,
        size_t value_size)
{
    ::cass_custom_payload_set(p, name, value, value_size);
}

inline void custom_payload::set_n(char const *name, size_t name_length,
        byte_t const *value, size_t value_size)
{
    ::cass_custom_payload_set_n(p, name, name_length, value, value_size);
}

inline void custom_payload::remove(char const *name)
{
    ::cass_custom_payload_remove(p, name);
}

inline void custom_payload::remove_n(char const *name, size_t name_length)
{
    ::cass_custom_payload_remove_n(p, name, name_length);
}

} // namespace cass

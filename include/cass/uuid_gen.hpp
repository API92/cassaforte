/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/defs.hpp>
#include <cass/impexp.hpp>
#include <cass/uuid.hpp>
#include <cass/wrapper_ptr.hpp>

namespace cass {

typedef wrapper_ptr<uuid_gen> uuid_gen_ptr;

class uuid_gen : wrapper {
public:
    static uuid_gen * ptr(::CassUuidGen *p)
    {
        return reinterpret_cast<uuid_gen * >(p);
    }

    ::CassUuidGen * backend()
    {
        return reinterpret_cast<::CassUuidGen *>(this);
    }

    ::CassUuidGen const * backend() const
    {
        return reinterpret_cast<::CassUuidGen const *>(this);
    }

    inline void free();

    inline static uuid_gen_ptr new_ptr();

    inline static uuid_gen_ptr new_with_node(uint64_t node);

    inline void time(uuid *output);

    inline void random(uuid *output);

    inline void from_time(uint64_t timestamp, uuid *output);
};

inline void uuid_gen::free()
{
    ::cass_uuid_gen_free(backend());
}

inline uuid_gen_ptr uuid_gen::new_ptr()
{
    return uuid_gen_ptr(ptr(::cass_uuid_gen_new()), true);
}

inline uuid_gen_ptr uuid_gen::new_with_node(uint64_t node)
{
    return uuid_gen_ptr(ptr(::cass_uuid_gen_new_with_node(node)), true);
}

inline void uuid_gen::time(uuid *output)
{
    ::cass_uuid_gen_time(backend(), output);
}

inline void uuid_gen::random(uuid *output)
{
    ::cass_uuid_gen_random(backend(), output);
}

inline void uuid_gen::from_time(uint64_t timestamp, uuid *output)
{
    ::cass_uuid_gen_from_time(backend(), timestamp, output);
}

} // namespace cass

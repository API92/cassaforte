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

typedef wrapper_ptr<class uuid_gen> uuid_gen_ptr;

class uuid_gen {
public:
    explicit uuid_gen(::CassUuidGen *p) : p(p) {}

    inline static void free(uuid_gen const g);

    inline static uuid_gen_ptr new_ptr();

    inline static uuid_gen_ptr new_with_node(uint64_t node);

    inline void time(uuid *output);

    inline void random(uuid *output);

    inline void from_time(uint64_t timestamp, uuid *output);

private:
    ::CassUuidGen *p;
};

inline void uuid_gen::free(uuid_gen const g)
{
    ::cass_uuid_gen_free(g.p);
}

inline uuid_gen_ptr uuid_gen::new_ptr()
{
    return uuid_gen_ptr(uuid_gen(::cass_uuid_gen_new()), true);
}

inline uuid_gen_ptr uuid_gen::new_with_node(uint64_t node)
{
    return uuid_gen_ptr(uuid_gen(::cass_uuid_gen_new_with_node(node)),
            true);
}

inline void uuid_gen::time(uuid *output)
{
    ::cass_uuid_gen_time(p, output);
}

inline void uuid_gen::random(uuid *output)
{
    ::cass_uuid_gen_random(p, output);
}

inline void uuid_gen::from_time(uint64_t timestamp, uuid *output)
{
    ::cass_uuid_gen_from_time(p, timestamp, output);
}

} // namespace cass

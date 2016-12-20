/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/uuid_gen.hpp>

#include <cassandra.h>

#include <cass/uuid.hpp>
#include <cass/wrapper_ptr_def.hpp>

namespace cass {

uuid_gen * uuid_gen::ptr(::CassUuidGen *p)
{
    return reinterpret_cast<uuid_gen * >(p);
}

::CassUuidGen * uuid_gen::backend()
{
    return reinterpret_cast<::CassUuidGen *>(this);
}

::CassUuidGen const * uuid_gen::backend() const
{
    return reinterpret_cast<::CassUuidGen const *>(this);
}

void uuid_gen::free()
{
    ::cass_uuid_gen_free(backend());
}

uuid_gen_ptr uuid_gen::new_ptr()
{
    return uuid_gen_ptr(ptr(::cass_uuid_gen_new()));
}

uuid_gen_ptr uuid_gen::new_with_node(uint64_t node)
{
    return uuid_gen_ptr(ptr(::cass_uuid_gen_new_with_node(node)));
}

void uuid_gen::time(uuid *output)
{
    ::cass_uuid_gen_time(backend(), output->backend());
}

void uuid_gen::random(uuid *output)
{
    ::cass_uuid_gen_random(backend(), output->backend());
}

void uuid_gen::from_time(uint64_t timestamp, uuid *output)
{
    ::cass_uuid_gen_from_time(backend(), timestamp, output->backend());
}


template class wrapper_ptr<uuid_gen>;

} // namespace cass

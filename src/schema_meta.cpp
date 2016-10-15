/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/keyspace_meta.hpp>
#include <cass/schema_meta.hpp>

namespace cass {

keyspace_meta const * const schema_meta::keyspace_by_name(
        char const *keyspace)
{
    return keyspace_meta::ptr(::cass_schema_meta_keyspace_by_name(
                p, keyspace));
}

keyspace_meta const * const schema_meta::keyspace_by_name_n(
        char const *keyspace, size_t keyspace_length)
{
    return keyspace_meta::ptr(::cass_schema_meta_keyspace_by_name_n(
                p, keyspace, keyspace_length));
}

} // namespace cass

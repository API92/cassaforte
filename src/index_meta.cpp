/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/index_meta.hpp>

#include <cassandra.h>

#include <cass/value.hpp>

namespace cass {

index_meta const * index_meta::ptr(::CassIndexMeta const *p)
{
    return reinterpret_cast<index_meta const *>(p);
}

::CassIndexMeta const * index_meta::backend() const
{
    return reinterpret_cast<::CassIndexMeta const *>(this);
}

value const * index_meta::options() const
{
    return value::ptr(::cass_index_meta_options(backend()));
}

value const * index_meta::field_by_name(char const *name) const
{
    return value::ptr(::cass_index_meta_field_by_name(backend(), name));
}

value const * index_meta::field_by_name_n(
        char const *name, size_t name_length) const
{
    return value::ptr(::cass_index_meta_field_by_name_n(
                backend(), name, name_length));
}

void index_meta::name(char const **name, size_t *name_length) const
{
    ::cass_index_meta_name(backend(), name, name_length);
}

index_type index_meta::type() const
{
    return (index_type)::cass_index_meta_type(backend());
}

void index_meta::target(char const **target, size_t *target_length) const
{
    ::cass_index_meta_target(backend(), target, target_length);
}

} // namespace cass

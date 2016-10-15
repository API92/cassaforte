/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/index_meta.hpp>

#include <cass/value.hpp>

namespace cass {

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

} // namespace cass

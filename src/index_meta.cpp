/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/index_meta.hpp>

#include <cass/value.hpp>

namespace cass {

value_const_ptr index_meta::options() const
{
    return value_const_ptr(::cass_index_meta_options(p));
}

value_const_ptr index_meta::field_by_name(char const *name) const
{
    return value_const_ptr(::cass_index_meta_field_by_name(p, name));
}

value_const_ptr index_meta::field_by_name_n(
        char const *name, size_t name_length) const
{
    return value_const_ptr(::cass_index_meta_field_by_name_n(
                p, name, name_length));
}

} // namespace cass

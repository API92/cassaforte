/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/column_meta.hpp>

#include <cass/data_type.hpp>
#include <cass/value.hpp>

namespace cass {

data_type_const_ptr column_meta::data_type() const
{
    return data_type_const_ptr(cass::data_type(::cass_column_meta_data_type(
                    backend())), false);
}

value const * column_meta::field_by_name(char const *name) const
{
    return value::ptr(::cass_column_meta_field_by_name(backend(), name));
}

value const * column_meta::field_by_name_n(char const *name,
        size_t name_length) const
{
    return value::ptr(::cass_column_meta_field_by_name_n(
                backend(), name, name_length));
}

} // namespace cass

/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/row.hpp>

#include <cass/value.hpp>

namespace cass {

value_const_ptr row::get_column(size_t index) const
{
    return value_const_ptr(::cass_row_get_column(p, index));
}

value_const_ptr row::get_column_by_name(char const *name) const
{
    return value_const_ptr(::cass_row_get_column_by_name(p, name));
}

value_const_ptr row::get_column_by_name_n(char const *name,
        size_t name_length) const
{
    return value_const_ptr(::cass_row_get_column_by_name_n(p, name,
                name_length));
}

} // namespace cass

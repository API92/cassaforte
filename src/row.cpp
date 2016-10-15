/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/row.hpp>

#include <cass/value.hpp>

namespace cass {

value const * row::get_column(size_t index) const
{
    return value::ptr(::cass_row_get_column(backend(), index));
}

value const * row::get_column_by_name(char const *name) const
{
    return value::ptr(::cass_row_get_column_by_name(backend(), name));
}

value const * row::get_column_by_name_n(char const *name,
        size_t name_length) const
{
    return value::ptr(::cass_row_get_column_by_name_n(
                backend(), name, name_length));
}

} // namespace cass

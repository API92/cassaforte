/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/result.hpp>

#include <cass/data_type.hpp>
#include <cass/row.hpp>

namespace cass {

data_type const * result::column_data_type(size_t index) const
{
    return data_type::ptr(::cass_result_column_data_type(
                    backend(), index));
}

row const * result::first_row() const
{
    return row::ptr(::cass_result_first_row(backend()));
}

} // namespace cass

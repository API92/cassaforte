/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/result.hpp>

#include <cass/data_type.hpp>
#include <cass/row.hpp>

namespace cass {

data_type_const_ptr result::column_data_type(size_t index)
{
    return data_type_const_ptr(data_type(::cass_result_column_data_type(
                    p, index)), false);
}

row_const_ptr result::first_row() const
{
    return row_const_ptr(::cass_result_first_row(p));
}

} // namespace cass

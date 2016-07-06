/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/value.hpp>

#include <cass/data_type.hpp>

namespace cass {

data_type_const_ptr value::data_type() const
{
    return data_type_const_ptr(cass::data_type(::cass_value_data_type(p)),
            false);
}

} // namespace cass

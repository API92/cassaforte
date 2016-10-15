/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/value.hpp>

#include <cass/data_type.hpp>

namespace cass {

data_type const * value::data_type() const
{
    return cass::data_type::ptr(::cass_value_data_type(backend()));
}

} // namespace cass

/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/prepared.hpp>

#include <cass/data_type.hpp>
#include <cass/statement.hpp>

namespace cass {

statement_ptr prepared::bind() const
{
    return statement_ptr(statement(::cass_prepared_bind(p)), true);
}

data_type_const_ptr prepared::parameter_data_type(size_t index) const
{
    return data_type_const_ptr(data_type(::cass_prepared_parameter_data_type(
                    p, index)), false);
}

data_type_const_ptr prepared::parameter_data_type_by_name(
        char const *name)
{
    return data_type_const_ptr(data_type(
                ::cass_prepared_parameter_data_type_by_name(p, name)), false);
}

data_type_const_ptr prepared::parameter_data_type_by_name_n(
        char const *name, size_t name_length)
{
    return data_type_const_ptr(data_type(
                ::cass_prepared_parameter_data_type_by_name_n(
                    p, name, name_length)), false);
}

} // namespace cass

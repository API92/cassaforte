/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/prepared.hpp>

#include <cass/data_type.hpp>
#include <cass/statement.hpp>

namespace cass {

statement_ptr prepared::bind() const
{
    return statement_ptr(statement::ptr(::cass_prepared_bind(backend())), true);
}

data_type const * prepared::parameter_data_type(size_t index) const
{
    return data_type::ptr(::cass_prepared_parameter_data_type(
                    backend(), index));
}

data_type const * prepared::parameter_data_type_by_name(
        char const *name) const
{
    return data_type::ptr(
                ::cass_prepared_parameter_data_type_by_name(backend(), name));
}

data_type const * prepared::parameter_data_type_by_name_n(
        char const *name, size_t name_length) const
{
    return data_type::ptr(::cass_prepared_parameter_data_type_by_name_n(
                backend(), name, name_length));
}

} // namespace cass

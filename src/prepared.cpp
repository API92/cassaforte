/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/prepared.hpp>

#include <cassandra.h>

#include <cass/data_type.hpp>
#include <cass/statement.hpp>
#include <cass/wrapper_ptr_def.hpp>

namespace cass {

prepared const * prepared::ptr(::CassPrepared const *p)
{
    return reinterpret_cast<prepared const *>(p);
}

::CassPrepared const * prepared::backend() const
{
    return reinterpret_cast<::CassPrepared const *>(this);
}

void prepared::free() const
{
    ::cass_prepared_free(backend());
}

error prepared::parameter_name(size_t index, char const **name,
        size_t *name_length)
{
    return (error)::cass_prepared_parameter_name(
            backend(), index, name, name_length);
}


statement_ptr prepared::bind() const
{
    return statement_ptr(statement::ptr(::cass_prepared_bind(backend())));
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

template class wrapper_ptr<prepared const>;

} // namespace cass

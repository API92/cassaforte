/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/column_meta.hpp>

#include <cassandra.h>

#include <cass/data_type.hpp>
#include <cass/value.hpp>

namespace cass {

column_meta const * column_meta::ptr(::CassColumnMeta const *p)
{
    return reinterpret_cast<column_meta const *>(p);
}

::CassColumnMeta const * column_meta::backend() const
{
    return reinterpret_cast<::CassColumnMeta const *>(this);
}

data_type const * column_meta::data_type() const
{
    return cass::data_type::ptr(::cass_column_meta_data_type(
                    backend()));
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

void column_meta::name(char const **name, size_t *name_length) const
{
    ::cass_column_meta_name(backend(), name, name_length);
}

column_type column_meta::type() const
{
    return (column_type)::cass_column_meta_type(backend());
}

} // namespace cass

/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/result.hpp>

#include <cassandra.h>

#include <cass/data_type.hpp>
#include <cass/row.hpp>
#include <cass/wrapper_ptr_def.hpp>

namespace cass {

result const * result::ptr(::CassResult const *p)
{
    return reinterpret_cast<result const *>(p);
}

::CassResult const * result::backend() const
{
    return reinterpret_cast<::CassResult const *>(this);
}

void result::free() const
{
    ::cass_result_free(backend());
}

size_t result::row_count() const
{
    return ::cass_result_row_count(backend());
}

size_t result::column_count() const
{
    return ::cass_result_column_count(backend());
}

error result::column_name(size_t index, char const **name,
        size_t *name_length) const
{
    return (error)::cass_result_column_name(
            backend(), index, name, name_length);
}

value_type result::column_type(size_t index) const
{
    return (value_type)::cass_result_column_type(backend(), index);
}

bool result::has_more_pages() const
{
    return ::cass_result_has_more_pages(backend()) == cass_true;
}

error result::paging_state_token(char const **paging_state,
        size_t *paging_state_size) const
{
    return (error)::cass_result_paging_state_token(
            backend(), paging_state, paging_state_size);
}

data_type const * result::column_data_type(size_t index) const
{
    return data_type::ptr(::cass_result_column_data_type(
                    backend(), index));
}

row const * result::first_row() const
{
    return row::ptr(::cass_result_first_row(backend()));
}

template class wrapper_ptr<result const>;

} // namespace cass

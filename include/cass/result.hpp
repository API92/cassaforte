/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/defs.hpp>
#include <cass/wrapper_ptr.hpp>

namespace cass {

typedef wrapper_ptr<result const> result_const_ptr;

class result {
public:
    static result const * ptr(::CassResult const *p)
    {
        return reinterpret_cast<result const *>(p);
    }

    ::CassResult const * backend() const
    {
        return reinterpret_cast<::CassResult const *>(this);
    }

    inline void free() const;

    inline size_t row_count() const;

    inline size_t column_count() const;

    inline error column_name(size_t index, char const **name,
            size_t *name_length) const;

    inline value_type column_type(size_t index) const;

    CASSA_IMPEXP data_type const * column_data_type(size_t index) const;

    CASSA_IMPEXP row const * first_row() const;

    inline bool has_more_pages() const;

    inline error paging_state_token(char const **paging_state,
            size_t *paging_state_size) const;
};

inline void result::free() const
{
    ::cass_result_free(backend());
}

inline size_t result::row_count() const
{
    return ::cass_result_row_count(backend());
}

inline size_t result::column_count() const
{
    return ::cass_result_column_count(backend());
}

inline error result::column_name(size_t index, char const **name,
        size_t *name_length) const
{
    return (error)::cass_result_column_name(
            backend(), index, name, name_length);
}

inline value_type result::column_type(size_t index) const
{
    return ::cass_result_column_type(backend(), index);
}

inline bool result::has_more_pages() const
{
    return ::cass_result_has_more_pages(backend()) == cass_true;
}

inline error result::paging_state_token(char const **paging_state,
        size_t *paging_state_size) const
{
    return (error)::cass_result_paging_state_token(
            backend(), paging_state, paging_state_size);
}

} // namespace cass

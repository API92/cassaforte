/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/defs.hpp>
#include <cass/wrapper_ptr.hpp>

namespace cass {

typedef wrapper_const_ptr<class result const> result_const_ptr;

class result {
public:
    explicit result(::CassResult const *p) : p(p) {}
    ::CassResult const * backend() const { return p; }

    inline static void free(result const r);

    inline size_t row_count() const;

    inline size_t column_count() const;

    inline error column_name(size_t index, char const **name,
            size_t *name_length) const;

    inline value_type column_type(size_t index) const;

    CASSA_IMPEXP data_type_const_ptr column_data_type(size_t index);

    CASSA_IMPEXP row_const_ptr firw_row() const;

    inline bool has_more_pages() const;

    inline error paging_state_token(char const **paging_state,
            size_t *paging_state_size) const;

private:
    ::CassResult const *p;
};

inline void result::free(result const r)
{
    ::cass_result_free(r.p);
}

inline size_t result::row_count() const
{
    return ::cass_result_row_count(p);
}

inline size_t result::column_count() const
{
    return ::cass_result_column_count(p);
}

inline error result::column_name(size_t index, char const **name,
        size_t *name_length) const
{
    return ::cass_result_column_name(p, index, name, name_length);
}

inline value_type result::column_type(size_t index) const
{
    return ::cass_result_column_type(p, index);
}

inline bool result::has_more_pages() const
{
    return ::cass_result_has_more_pages(p) == cass_true;
}

inline error result::paging_state_token(char const **paging_state,
        size_t *paging_state_size) const
{
    return ::cass_result_paging_state_token(p, paging_state, paging_state_size);
}

} // namespace cass

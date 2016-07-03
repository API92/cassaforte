/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/wrapper_ptr.hpp>

namespace cass {

typedef wrapper_ptr<class data_type> data_type_ptr;
typedef wrapper_const_ptr<class data_type const> data_type_const_ptr;

class data_type {
public:
    data_type(::CassDataType *p) : p(p) {}
    data_type(::CassDataType const *pc) : pc(pc) {}
    ::CassDataType * backend() { return p; }
    ::CassDataType const * backend() const { return pc; }

    inline static void free(data_type const);

private:
    friend class keyspace_meta;
    friend data_type_ptr;
    friend data_type_const_ptr;
    template<typename T, void (*)(T)>
    friend class shared_res;

    data_type(const data_type &) = default;
    data_type(data_type &&) = default;
    void operator = (const data_type &) = delete;
    void operator = (data_type &&) = delete;

    union {
        ::CassDataType *p;
        ::CassDataType const *pc;
    };
};


inline void data_type::free(data_type const d)
{
    ::cass_data_type_free(d.p);
}

} // namespace cass

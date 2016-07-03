/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassert>

#include <cassandra.h>

namespace cass {

class materialized_view_meta {
public:
    explicit materialized_view_meta(::CassMaterializedViewMeta const *p) :
        p(p) {}
    ::CassMaterializedViewMeta const * backend() const { return p; }

private:
    ::CassMaterializedViewMeta const *p;
};

class materialized_view_meta_const_ptr {
public:
    explicit materialized_view_meta_const_ptr(
            ::CassMaterializedViewMeta const *p) : m(p) {}
    operator bool () const { return m.backend() != nullptr; }
    materialized_view_meta const * get() const
    {
        return m.backend() ? &m : nullptr;
    }
    materialized_view_meta const * operator -> () const
    {
        assert(*this);
        return get();
    }
    materialized_view_meta const & operator * () const
    {
        assert(*this);
        return m;
    }

private:
    materialized_view_meta const m;
};

} // namespace cass

/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/session.hpp>
#include <cass/schema_meta.hpp>

namespace cass {

schema_meta_const_ptr session::get_schema_meta() const
{
    return schema_meta_const_ptr(schema_meta(::cass_session_get_schema_meta(p)),
            true);
}

} // namespace cass

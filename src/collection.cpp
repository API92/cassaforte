/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/collection.hpp>

#include <cass/data_type.hpp>
#include <cass/tuple.hpp>
#include <cass/user_type.hpp>

namespace cass {

collection_ptr collection::new_from_data_type(
        cass::data_type const *data_type, size_t item_count)
{
    return collection_ptr(collection::ptr(::cass_collection_new_from_data_type(
                    data_type->backend(), item_count)), true);
}

data_type const * collection::data_type() const
{
    return cass::data_type::ptr(::cass_collection_data_type(backend()));
}

error collection::append(tuple const *value)
{
    return (error)::cass_collection_append_tuple(backend(), value->backend());
}

error collection::append(user_type const *value)
{
    return (error)::cass_collection_append_user_type(
            backend(), value->backend());
}

} // namespace cass

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
    return collection_ptr(collection(::cass_collection_new_from_data_type(
                    data_type->backend(), item_count)), true);
}

data_type_const_ptr collection::data_type() const
{
    return data_type_const_ptr(cass::data_type(::cass_collection_data_type(p)),
            false);
}

error collection::append_tuple(tuple const *value)
{
    return (error)::cass_collection_append_tuple(p, value->backend());
}

error collection::append_user_type(user_type const *value)
{
    return (error)::cass_collection_append_user_type(p, value->backend());
}

} // namespace cass

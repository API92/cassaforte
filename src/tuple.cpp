/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/tuple.hpp>

#include <cass/collection.hpp>
#include <cass/data_type.hpp>
#include <cass/user_type.hpp>

namespace cass {

tuple_ptr tuple::new_from_data_type(cass::data_type const *data_type)
{
    return tuple_ptr(ptr(::cass_tuple_new_from_data_type(
                    data_type->backend())), true);
}

data_type const * tuple::data_type() const
{
    return cass::data_type::ptr(::cass_tuple_data_type(backend()));
}

error tuple::set(size_t index, collection const *value)
{
    return (error)::cass_tuple_set_collection(
                backend(), index, value->backend());
}

error tuple::set(size_t index, user_type const *value)
{
    return (error)::cass_tuple_set_user_type(
                backend(), index, value->backend());
}

} // namespace cass

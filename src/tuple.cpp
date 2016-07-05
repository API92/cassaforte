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
    return tuple_ptr(tuple(::cass_tuple_new_from_data_type(
                    data_type->backend())), true);
}

data_type_const_ptr tuple::data_type() const
{
    return data_type_const_ptr(cass::data_type(::cass_tuple_data_type(p)),
            false);
}

error tuple::set_collection(size_t index, collection const *value)
{
    return ::cass_tuple_set_collection(p, index, value->backend());
}

error tuple::set_user_type(size_t index, user_type const *value)
{
    return ::cass_tuple_set_user_type(p, index, value->backend());
}

} // namespace cass

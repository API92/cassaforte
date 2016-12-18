/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <experimental/string_view>

#include "forward.hpp"

namespace cass {

struct custom {
    std::experimental::string_view class_name;
    bytes_view value;
    custom(std::experimental::string_view class_name, bytes_view value) :
            class_name(class_name), value(value) {}
};

} // namespace cass

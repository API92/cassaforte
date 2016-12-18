/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include "forward.hpp"

namespace cass {

struct decimal {
    byte_t const *varint;
    size_t varint_size;
    int32_t scale;
    decimal(byte_t const *varint = nullptr, size_t varint_size = 0,
            int32_t scale = 0) :
        varint(varint), varint_size(varint_size), scale(scale) {}
};

} // namespace cass

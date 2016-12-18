/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

namespace cass {

class delete_defaults {
    delete_defaults() = delete;
    ~delete_defaults() = delete;
    delete_defaults(delete_defaults const &) = delete;
    void operator = (delete_defaults const &) = delete;
    delete_defaults(delete_defaults &&) = delete;
    void operator = (delete_defaults &&) = delete;
};

} // namespace cass

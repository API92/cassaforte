/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include "forward.hpp"
#include "impexp.hpp"

typedef struct CassUuid_ CassUuid;

namespace cass {

class CASSA_IMPEXP uuid {
public:
    ::CassUuid * backend();
    ::CassUuid const * backend() const;

    static void min_from_time(uint64_t time, uuid *output);

    static void max_from_time(uint64_t time, uuid *output);

    uint64_t timestamp() const;

    uint8_t version() const;

    void string(char *output) const;

    error from_string(char const *str);
    error from_string_n(char const *str, size_t str_length);

    bool operator == (uuid const &rhs) const;

private:
    uint64_t time_and_version;
    uint64_t clock_seq_and_node;
};

} // namespace cass

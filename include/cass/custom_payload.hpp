/*
 * Copyright (C) Andrey Pikas
 */

#include "delete_defaults.hpp"
#include "forward.hpp"
#include "impexp.hpp"

typedef struct CassCustomPayload_ CassCustomPayload;

namespace cass {

class CASSA_IMPEXP custom_payload : delete_defaults {
public:
    static custom_payload * ptr(::CassCustomPayload *p);

    ::CassCustomPayload * backend();
    ::CassCustomPayload const * backend() const;

    void free();

    static custom_payload_ptr new_ptr();

    void set(char const *name, std::byte const *value, size_t value_size);
    void set_n(char const *name, size_t name_length, std::byte const *value,
            size_t value_size);

    void remove(char const *name);
    void remove_n(char const *name, size_t name_length);
};

} // namespace cass

project(cassaforte)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules")

if (${BUILD_SHARED_LIBS})
    set(CMAKE_CXX_VISIBILITY_PRESET hidden)
endif()
set(CMAKE_SHARED_LINKER_FLAGS ${CMAKE_SHARED_LINKER_FLAGS} "-Wl,--no-undefined")

add_definitions(-DCASSA_EXPORTS)

add_library(${PROJECT_NAME}
    include/cass/aggregate_meta.hpp
    include/cass/authenticator.hpp
    include/cass/batch.hpp
    include/cass/cluster.hpp
    include/cass/collection.hpp
    include/cass/column_meta.hpp
    include/cass/custom_payload.hpp
    include/cass/custom.hpp
    include/cass/data_type.hpp
    include/cass/decimal.hpp
    include/cass/delete_defaults.hpp
    include/cass/enums.hpp
    include/cass/error_result.hpp
    include/cass/forward.hpp
    include/cass/function_meta.hpp
    include/cass/future.hpp
    include/cass/impexp.hpp
    include/cass/index_meta.hpp
    include/cass/inet.hpp
    include/cass/iterator.hpp
    include/cass/keyspace_meta.hpp
    include/cass/materialized_view_meta.hpp
    include/cass/misc.hpp
    include/cass/prepared.hpp
    include/cass/result.hpp
    include/cass/retry_policy.hpp
    include/cass/row.hpp
    include/cass/schema_meta.hpp
    include/cass/session.hpp
    include/cass/ssl.hpp
    include/cass/statement.hpp
    include/cass/table_meta.hpp
    include/cass/timestamp_gen.hpp
    include/cass/tuple.hpp
    include/cass/uuid.hpp
    include/cass/uuid_gen.hpp
    include/cass/user_type.hpp
    include/cass/value.hpp
    include/cass/wrapper_ptr.hpp
    include/cass/wrapper_ptr_def.hpp
    src/aggregate_meta.cpp
    src/authenticator.cpp
    src/batch.cpp
    src/cluster.cpp
    src/collection.cpp
    src/column_meta.cpp
    src/custom_payload.cpp
    src/data_type.cpp
    src/enums.cpp
    src/error_result.cpp
    src/function_meta.cpp
    src/future.cpp
    src/index_meta.cpp
    src/inet.cpp
    src/iterator.cpp
    src/keyspace_meta.cpp
    src/materialized_view_meta.cpp
    src/misc.cpp
    src/prepared.cpp
    src/result.cpp
    src/retry_policy.cpp
    src/row.cpp
    src/schema_meta.cpp
    src/session.cpp
    src/ssl.cpp
    src/statement.cpp
    src/table_meta.cpp
    src/timestamp_gen.cpp
    src/tuple.cpp
    src/user_type.cpp
    src/uuid.cpp
    src/uuid_gen.cpp
    src/value.cpp
)

include_directories(include)

if (NOT Cassandra_FOUND)
    find_package(Cassandra REQUIRED)
endif()
include_directories(${Cassandra_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${Cassandra_LIBRARY})

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_EXTENSIONS OFF)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)

project(cassaforte)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules")

if (${BUILD_SHARED_LIBS})
    set(CMAKE_CXX_VISIBILITY_PRESET hidden)
endif()

add_library(${PROJECT_NAME}
    include/cass/aggregate_meta.hpp
    include/cass/authenticator.hpp
    include/cass/batch.hpp
    include/cass/cluster.hpp
    include/cass/column_meta.hpp
    include/cass/data_type.hpp
    include/cass/defs.hpp
    include/cass/function_meta.hpp
    include/cass/future.hpp
    include/cass/impexp.hpp
    include/cass/index_meta.hpp
    include/cass/keyspace_meta.hpp
    include/cass/materialized_view_meta.hpp
    include/cass/retry_policy.hpp
    include/cass/schema_meta.hpp
    include/cass/session.hpp
    include/cass/shared_res.hpp
    include/cass/ssl.hpp
    include/cass/statement.hpp
    include/cass/table_meta.hpp
    include/cass/timestamp_gen.hpp
    include/cass/value.hpp
    include/cass/wrapper_ptr.hpp
    src/cluster.cpp
    src/keyspace_meta.cpp
    src/main.cpp
    src/materialized_view_meta.cpp
    src/schema_meta.cpp
    src/session.cpp
    src/shared_res.cpp
    src/table_meta.cpp
)

include_directories(include)

if (NOT Cassandra_FOUND)
    find_package(Cassandra REQUIRED)
endif()
include_directories(${Cassandra_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${Cassandra_LIBRARY})

if (NOT falloc_FOUND)
    find_package(falloc REQUIRED)
endif()
include_directories(${falloc_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${falloc_LIBRARY})

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_EXTENSIONS OFF)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)

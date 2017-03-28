cmake_minimum_required(VERSION 2.6.4)

include(FindPackageHandleStandardArgs)


#------------------------
#
# Add includes and libraries required for using Cassandra C++ driver.
#
# Output: CASSANDRA_LIBRARY and CASSANDRA_INCLUDE_DIR
#------------------------

# Setup the paths and hints for cassandra c++ driver
set(_CASS_ROOT_PATHS ${Cassandra_ROOT_DIR} $ENV{Cassandra_ROOT_DIR})
if(NOT WIN32)
    set(_CASS_ROOT_PATHS "${_CASS_ROOT_PATHS}" "/usr/" "/usr/local/")
endif()

# Ensure cassandra c++ driver was found
find_path(Cassandra_INCLUDE_DIR
  NAMES cassandra.h
  HINTS ${_CASS_ROOT_PATHS}
  PATH_SUFFIXES include)
find_library(Cassandra_LIBRARY
  NAMES cassandra libcassandra
  HINTS ${_CASS_ROOT_PATHS}
  PATH_SUFFIXES lib lib64 "bin/${CMAKE_CXX_COMPILER_ID}/${CMAKE_BUILD_TYPE}" "build/${CMAKE_CXX_COMPILER_ID}/${CMAKE_BUILD_TYPE}")
find_package_handle_standard_args(Cassandra "Could NOT find cassandra, try to set the path to the cassandra root folder in the system variable Cassandra_ROOT_DIR"
    Cassandra_LIBRARY
    Cassandra_INCLUDE_DIR)


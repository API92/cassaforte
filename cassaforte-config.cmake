# cassaforte-config
# --------------
#
# This module defines
#
# ::
#
#   cassaforte_FOUND - Set to true when falloc is found.
#   cassaforte_INCLUDE_DIR - the directories of the falloc headers
#   cassaforte_LIBRARY - the falloc libraries needed for linking

find_path(cassaforte_INCLUDE_DIR
    NAME cass/defs.hpp
    PATHS ${CMAKE_CURRENT_LIST_DIR}
    PATH_SUFFIXES include)

find_library(cassaforte_LIBRARY
    NAMES cassaforte libcassaforte
    PATHS ${CMAKE_CURRENT_LIST_DIR}
    PATH_SUFFIXES bin/${CMAKE_CXX_COMPILER_ID}/${CMAKE_BUILD_TYPE})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(cassaforte
    "Could NOT find cassaforte, try to set the path to the cassaforte root folder in the variable cassaforte_DIR"
    cassaforte_LIBRARY
    cassaforte_INCLUDE_DIR)

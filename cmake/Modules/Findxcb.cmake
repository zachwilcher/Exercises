# Copyright © 2015 Valve Corporation

#[=======================================================================[.rst:
Findxcb
-------
Finds the xcb library.

Imported Targets
^^^^^^^^^^^^^^^^

This module provides the following imported targets, if found:

``xcb::xcb``
  The xcb library

Result Variables
^^^^^^^^^^^^^^^^

This will define the following variables:

``xcb_FOUND``
  True if the system has the xcb library.
``xcb_INCLUDE_DIRS``
  Include directories needed to use xcb.
``xcb_LIBRARIES``



#]=======================================================================]



find_package(PkgConfig)

find_path(xcb_INCLUDE_DIR
    NAMES xcb.h
    PATH_SUFFIXES xcb
    REQUIRED
)

find_library(xcb_LIBRARY
    NAMES libxcb xcb
    PATH_SUFFIXES xcb
    REQUIRED
)

  if(GLEW_VERBOSE)
    message(STATUS "FindGLEW: CMAKE_FIND_LIBRARY_SUFFIXES for ${shared_or_static}: ${CMAKE_FIND_LIBRARY_SUFFIXES}")
  endif()
endfunction()

include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(xcb
    FOUND_VAR xcb_FOUND
    REQUIRED_VARS xcb_INCLUDE_DIR xcb_LIBRARY
)

if(xcb_FOUND)
    set(xcb_LIBRARIES ${xcb_LIBRARY})
    set(xcb_INCLUDE_DIRS ${xcb_INCLUDE_DIR})
    if(NOT TARGET xcb::xcb)
        add_library(xcb::xcb UNKNOWN IMPORTED GLOBAL)
        target_include_directories(xcb::xcb PUBLIC ${xcb_INCLUDE_DIRS})
        target_link_libraries(xcb::xcb PUBLIC ${xcb_LIBRARIES})
        set_target_properties(xcb::xcb PROPERTIES IMPORTED_LOCATION ${xcb_LIBRARIES})
    endif()
endif()


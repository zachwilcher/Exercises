# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

#[=======================================================================[.rst:
Findasio
-------

Finds the asio library.

Result Variables
^^^^^^^^^^^^^^^^

This will define the following variables:

``asio_FOUND``
  True if the system has the asio library.
``asio_VERSION``
  The version of the asio library which was found.
``asio_INCLUDE_DIRS``
  Include directories needed to use asio.

Cache Variables
^^^^^^^^^^^^^^^

The following cache variables may also be set:

``asio_INCLUDE_DIR``
  The directory containing ``asio.hpp``.

#]=======================================================================]

    
set(asio_ROOT "asio/include")

set(asio_VERSION_ROOT "asio-${asio_VERSION}/include")

find_path(asio_INCLUDE_DIR
		NAMES asio.hpp
		PATHS 
                /usr/include 
                /usr/include/${asio_ROOT} 
                /usr/include/${asio_VERSION_ROOT}	
		/usr/local/include
    	        /usr/local/include/${asio_ROOT}
		/usr/local/include/${asio_VERSION_ROOT}

    	C:/
    	C:/${asio_ROOT}
		C:/${asio_VERSION_ROOT}
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(
	asio
        FOUND_VAR asio_FOUND
        REQUIRED_VARS asio_INCLUDE_DIR
        VERSION_VAR asio_VERSION
)

if(asio_FOUND)
    set(asio_INCLUDE_DIRS ${asio_INCLUDE_DIR})
endif()


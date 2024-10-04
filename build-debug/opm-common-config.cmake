# - Open Porous Media Initiative shared infrastructure config mode
#
# Defines the following variables:
#  opm-common_FOUND        - true
#  opm-common_VERSION      - version of the opm-common library found, e.g. 0.2
#  opm-common_DEFINITIONS  - defines to be made on the command line
#  opm-common_INCLUDE_DIRS - header directories with which to compile
#  opm-common_LINKER_FLAGS - flags that must be passed to the linker
#  opm-common_LIBRARIES    - names of the libraries with which to link
#  opm-common_LIBRARY_DIRS - directories in which the libraries are situated
#
# You should put lines like this in your CMakeLists.txt
#  set (opm-common_DIR "${PROJECT_BINARY_DIR}/../opm-common" CACHE LOCATION "Build tree of opm-common")
#  find_package (opm-common)
#  configure_vars (
#    FILE  CXX  "${PROJECT_BINARY_DIR}/config.h"
#    WRITE ${opm-common_CONFIG_VARS}
#    )

# <http://www.vtk.org/Wiki/CMake/Tutorials/How_to_create_a_ProjectConfig.cmake_file>

# Prevent multiple inclusions
if(NOT opm-common_FOUND)
  # propagate these properties from one build system to the other
  set (opm-common_PREFIX "/home/skpark0111/opm_study/opm-common_study")
  set (opm-common_VERSION "2024.10")
  set (opm-common_DEFINITIONS "")
  set (opm-common_INCLUDE_DIRS "/home/skpark0111/opm_study/opm-common_study;/usr/include;/usr/include/cjson")
  set (opm-common_LIBRARY_DIRS "/usr/lib/x86_64-linux-gnu" "/home/skpark0111/opm_study/opm-common_study/build-debug/lib")
  set (opm-common_LINKER_FLAGS "-Wl,--enable-new-dtags")
  set (opm-common_CONFIG_VARS "HAVE_OPENMP;HAVE_TYPE_TRAITS;HAVE_VALGRIND;HAVE_FINAL;HAVE_ECL_INPUT;HAVE_CXA_DEMANGLE;HAVE_FNMATCH_H")

  # The flag whether embedded Python is supported or not is passed to downstream modules,
  # it is only used to enable/disable regression testing with Python enabled input. The
  # actual code is self contained - and can be used downstream without awareness of this.
  set (opm-common_EMBEDDED_PYTHON OFF)

  # libraries come from the build tree where this file was generated
  set (opm-common_LIBRARY "/home/skpark0111/opm_study/opm-common_study/build-debug/lib/libopmcommon.a")
  set (opm-common_LIBRARIES ${opm-common_LIBRARY} "fmt::fmt;OpenMP::OpenMP_CXX;Boost::system;/usr/lib/x86_64-linux-gnu/libcjson.so")

  # The purpose of this string replacement operation is to enable use of the
  # generated opm-project-config.cmake file also in the situation where 'make
  # install' has been invoked with the DESTDIR option:
  #
  # opm-common/build> cmake .. -DCMAKE_INSTALL_PREFIX=/real/prefix
  # opm-common/budil> make install DESTDIR=/tmp/prefix
  #
  # downstream/build> cmake .. -DDEST_PREFIX=/tmp/prefix -DCMAKE_PREFIX_PATH=/tmp/prefix
  # downstream/build> make install
  #
  # That way the downstream dependency can still use find_package( opm-common )
  # even though the opm-common-config.cmake file is not internally consistent
  # with it's own location in the filesystem.

  if(DEST_PREFIX)
    set(DEST_PREFIX "${DEST_PREFIX}${opm-common_PREFIX}")
    string(REPLACE ${opm-common_PREFIX} ${DEST_PREFIX} opm-common_INCLUDE_DIRS "${opm-common_INCLUDE_DIRS}")
    string(REPLACE ${opm-common_PREFIX} ${DEST_PREFIX} opm-common_LIBRARY_DIRS "${opm-common_LIBRARY_DIRS}")
    string(REPLACE ${opm-common_PREFIX} ${DEST_PREFIX} opm-common_LIBRARY      "${opm-common_LIBRARY}")
    string(REPLACE ${opm-common_PREFIX} ${DEST_PREFIX} opm-common_PYTHON_COMMON_DIR "${opm-common_PYTHON_COMMON_DIR}")
  endif()


  set (HAVE_OPM_COMMON 1)
  mark_as_advanced (opm-common_LIBRARY)

  # not all projects have targets; conditionally add this part
  if (NOT "opmcommon" STREQUAL "")
    # add the library as a target, so that other things in the project including
    # this file may depend on it and get rebuild if this library changes.
    if(NOT TARGET opmcommon)
      get_filename_component(_dir "${CMAKE_CURRENT_LIST_FILE}" PATH)
      include("${_dir}/opm-common-targets.cmake")
    endif()
  endif (NOT "opmcommon" STREQUAL "")

  # same as above, but for C99
  string (REPLACE "-std=c99" "" CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
  string (STRIP "${CMAKE_C_FLAGS}" CMAKE_C_FLAGS)
  set (CMAKE_C_FLAG "-std=c99 ${CMAKE_C_FLAGS}")

  # build with OpenMP if that was found
  if (NOT "-fopenmp" STREQUAL "")
    string (REPLACE "-fopenmp" "" CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
    string (STRIP "${CMAKE_C_FLAGS}" CMAKE_C_FLAGS)
    set (CMAKE_C_FLAG "-fopenmp ${CMAKE_C_FLAGS}")
  endif (NOT "-fopenmp" STREQUAL "")
  if (NOT "-fopenmp" STREQUAL "")
    string (REPLACE "-fopenmp" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    string (STRIP "${CMAKE_CXX_FLAGS}" CMAKE_CXX_FLAGS)
    set (CMAKE_C_FLAG "-fopenmp ${CMAKE_CXX_FLAGS}")
  endif (NOT "-fopenmp" STREQUAL "")

  # this is the contents of config.h as far as our probes can tell:

  # Require correct CMake standard. Needed for user modules as
  # some software will add incompatible compile switches like
  # -std=gnu++11 otherwise when search for (I guess because of
  # imported targets using INTERFACE_COMPILE_FEATURES), and will
  # break compilation because of missing c++17 features.
  if(NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)
  endif()

  # The settings in this block do not mix well with the DEST_PREFIX
  # setting.
  if (NOT DEST_PREFIX)
    # if this file is not processed using the OPM CMake system but
    # simply by a call to find_package(module) then the CMAKE_MODULE_PATH
    # might not include the location of the OPM cmake module yet.
    # Hence we search for opm-common using config mode to set it up.
    # The check for opm-common_PREFIX is there to not do this in
    # opm-common-config.cmake
    if(NOT opm-common_PREFIX
        AND NOT opm-common_FOUND)
      # This needed to find the path to the CMake modules
      find_package(opm-common CONFIG)
    endif()
    # This is required to include OpmPackage /opm-common-prereq.cmake
    set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" /home/skpark0111/opm_study/opm-common_study)

    # extra code from variable OPM_PROJECT_EXTRA_CODE
    #ENABLE_ECL_INPUT is needed by opm-common-prereq.cmake
                                   set(ENABLE_ECL_INPUT ON)
                                   set(OPM_MACROS_ROOT /home/skpark0111/opm_study/opm-common_study)
                                   list(APPEND CMAKE_MODULE_PATH ${OPM_MACROS_ROOT}/cmake/Modules)
                                   include(OpmPackage) #Make macros available after find_package(opm-common)
                                     set(COMPARE_ECL_COMMAND /home/skpark0111/opm_study/opm-common_study/build-debug/bin/compareECL)
                                     set(OPM_PACK_COMMAND /home/skpark0111/opm_study/opm-common_study/build-debug/bin/opmpack)
                                     set(RST_DECK_COMMAND /home/skpark0111/opm_study/opm-common_study/build-debug/bin/rst_deck)
                                       list(APPEND opm-common_INCLUDE_DIRS /home/skpark0111/opm_study/opm-common_study/build-debug/include)
                                         set(HAVE_ECL_INPUT 1)
                                         set(HAVE_ECL_OUTPUT 1)
    # end extra code

    include(OpmPackage)
    include(opm-common-prereqs)
  endif()
endif()
if (DEFINED HAVE_OPENMP AND NOT (("${HAVE_OPENMP}" STREQUAL "") OR ("${HAVE_OPENMP}" STREQUAL "1")))
	message (WARNING "Incompatible value \"${HAVE_OPENMP}\" of variable \"HAVE_OPENMP\"")
endif ()
set (HAVE_OPENMP "1")
if (DEFINED HAVE_TYPE_TRAITS AND NOT (("${HAVE_TYPE_TRAITS}" STREQUAL "") OR ("${HAVE_TYPE_TRAITS}" STREQUAL "1")))
	message (WARNING "Incompatible value \"${HAVE_TYPE_TRAITS}\" of variable \"HAVE_TYPE_TRAITS\"")
endif ()
set (HAVE_TYPE_TRAITS)
if (DEFINED HAVE_VALGRIND AND NOT (("${HAVE_VALGRIND}" STREQUAL "") OR ("${HAVE_VALGRIND}" STREQUAL "1")))
	message (WARNING "Incompatible value \"${HAVE_VALGRIND}\" of variable \"HAVE_VALGRIND\"")
endif ()
set (HAVE_VALGRIND "1")
if (DEFINED HAVE_FINAL AND NOT (("${HAVE_FINAL}" STREQUAL "") OR ("${HAVE_FINAL}" STREQUAL "1")))
	message (WARNING "Incompatible value \"${HAVE_FINAL}\" of variable \"HAVE_FINAL\"")
endif ()
set (HAVE_FINAL)
if (DEFINED HAVE_ECL_INPUT AND NOT (("${HAVE_ECL_INPUT}" STREQUAL "") OR ("${HAVE_ECL_INPUT}" STREQUAL "1")))
	message (WARNING "Incompatible value \"${HAVE_ECL_INPUT}\" of variable \"HAVE_ECL_INPUT\"")
endif ()
set (HAVE_ECL_INPUT "1")
if (DEFINED HAVE_CXA_DEMANGLE AND NOT (("${HAVE_CXA_DEMANGLE}" STREQUAL "") OR ("${HAVE_CXA_DEMANGLE}" STREQUAL "1")))
	message (WARNING "Incompatible value \"${HAVE_CXA_DEMANGLE}\" of variable \"HAVE_CXA_DEMANGLE\"")
endif ()
set (HAVE_CXA_DEMANGLE)
if (DEFINED HAVE_FNMATCH_H AND NOT (("${HAVE_FNMATCH_H}" STREQUAL "") OR ("${HAVE_FNMATCH_H}" STREQUAL "1")))
	message (WARNING "Incompatible value \"${HAVE_FNMATCH_H}\" of variable \"HAVE_FNMATCH_H\"")
endif ()
set (HAVE_FNMATCH_H "1")

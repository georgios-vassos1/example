cmake_minimum_required(VERSION 3.0)
project(TestNamespace VERSION 0.1 DESCRIPTION "" LANGUAGES CXX)

option (BUILD_TESTING "Build the testing tree." ON)
option (USE_SANITIZER "Define CXX Sanitizer (Address, Undefined, Leak, Memory)" "")

set(CMAKE_VERBOSE_MAKEFILE ON)
# set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/config")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
  set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
  set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache)
endif(CCACHE_FOUND)

# if (USE_SANITIZER STREQUAL "Address")
#     set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address")
#     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
# elseif (USE_SANITIZER STREQUAL "Thread")
#     set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=thread")
#     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread")
# elseif (USE_SANITIZER STREQUAL "Undefined")
#     set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=undefined")
#     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined")
# elseif (USE_SANITIZER STREQUAL "Leak")
#     set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=leak")
#     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=leak")
# elseif (USE_SANITIZER STREQUAL "Memory")
#     set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=memory")
#     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=memory")
# endif()

################################################################################
# Libraries
################################################################################

find_package(Armadillo 9.500 QUIET)
if (ARMADILLO_FOUND AND NOT USE_PKG_LIB)
  message ([Main]  " Armadillo FOUND")
  find_package(Armadillo CONFIG REQUIRED)
else()
  message ([Main]  " Using Armadillo included in this package")
  find_package(LAPACK REQUIRED)
  add_subdirectory("lib/armadillo")
  include_directories("lib/armadillo/include")
endif ()
message( [Main] " ARMADILLO_LIBRARIES = ${ARMADILLO_LIBRARIES}")
message( [Main] " ARMADILLO_INCLUDE_DIRS = ${ARMADILLO_INCLUDE_DIRS}")

include_directories("lib/doctest")

# find_package(spdlog QUIET)
# if (spdlog_FOUND AND NOT USE_PKG_LIB)
#   message ([Main]  " spdlog FOUND")
#   find_package(spdlog CONFIG REQUIRED)
#  else()
#   set(SPDLOG_BUILD_TESTS OFF)
#   set(SPDLOG_BUILD_TESTS_HO OFF)
#   message ([Main]  " Using spdlog included in this package")
#   add_subdirectory("lib/spdlog")
#   include_directories("lib/spdlog/include")
# endif()

################################################################################
# Main library
################################################################################

set(LIBTARGET_DIR "${CMAKE_SOURCE_DIR}/src")
set(LIBTARGET_INC "${CMAKE_SOURCE_DIR}/include")
file(GLOB LIBTARGET_SRC ${LIBTARGET_DIR}/*.cpp)
file(GLOB LIBTARGET_HDR ${LIBTARGET_DIR}/*.hpp)
file(GLOB LIBTARGET_PUBLIC ${LIBTARGET_INC}/*.hpp)
add_library(TestNamespace SHARED ${LIBTARGET_SRC} ${LIBTARGET_HDR} ${LIBTARGET_PUBLIC})
message( [Main] " LIBTARGET_DIR = ${LIBTARGET_DIR}")
target_link_libraries(TestNamespace PRIVATE armadillo)
set_target_properties(TestNamespace PROPERTIES VERSION ${PROJECT_VERSION})
target_include_directories(TestNamespace PUBLIC ${LIBTARGET_INC})
set_target_properties(TestNamespace PROPERTIES PUBLIC_HEADER "${LIBTARGET_PUBLIC}")
include(GNUInstallDirs)
# configure_file(config/target.pc.in target.pc @ONLY)

# install(TARGETS target
#   ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
#   RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
#   LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#   PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/target)
# install(FILES ${CMAKE_BINARY_DIR}/target.pc
#     DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig)


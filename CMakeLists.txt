# This file is part of killman.
# 
# killman is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# killman is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with killman.  If not, see <http://www.gnu.org/licenses/>.

# required stuff
cmake_minimum_required(VERSION 2.8.9)
project(killman)
set(CMAKE_BUILD_TYPE Release)

set(CWS_DEFAULT OFF)

if (MINGW OR MSYS)
  set (CWS_DEFAULT ON)
endif (MINGW OR MSYS)

option(COMPILE_WITH_STATIC "Compile with the -static option" ${CWS_DEFAULT})

set(COMPILE_FLAGS "-Iinclude -pthread -Wall `gtk-config --cflags` `gtk-config --libs`")
set(LINK_FLAGS " ")

if (COMPILE_WITH_STATIC)
  set(COMPILE_FLAGS "${COMPILE_FLAGS} -static")
  message(STATUS "Compiling with static libs...")
endif (COMPILE_WITH_STATIC)

# set compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILE_FLAGS}")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${COMPILE_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${LINK_FLAGS}")

# set version information
set(km_VERSION "ALPHA")
set(km_REVISION "1")
set(km_MINOR_REVISION "0")

# get sources
file(GLOB SOURCES "src/*")

if (APPLE)
  set(MACOS_ACTIVE "1")
endif (APPLE)

# do configuration
configure_file (
  "include/killman_config.h.in"
  "include/killman_config.h"
  )

# compile sources
add_executable(killman ${SOURCES})
set_property(TARGET killman PROPERTY CXX_STANDARD 11)
set_property(TARGET killman PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET killman PROPERTY C_STANDARD 11)
set_property(TARGET killman PROPERTY C_STANDARD_REQUIRED ON)

# add installation rules
install(TARGETS killman DESTINATION bin)

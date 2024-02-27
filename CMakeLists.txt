cmake_minimum_required(VERSION 3.20)
project(SpaceDOS)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})
set(SPACEDOS_SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
include_directories(${SPACEDOS_SOURCE_DIR}/headers)
add_executable(SpaceDOS ${SPACEDOS_SOURCE_DIR}/commands.cpp
                        ${SPACEDOS_SOURCE_DIR}/counters.cpp
                        ${SPACEDOS_SOURCE_DIR}/data.cpp
                        ${SPACEDOS_SOURCE_DIR}/main.cpp
                        ${SPACEDOS_SOURCE_DIR}/other.cpp
                        ${SPACEDOS_SOURCE_DIR}/RSP.cpp
                        ${SPACEDOS_SOURCE_DIR}/time_utils.cpp
                        icon.rc version.rc
                        YourLogo.ico)


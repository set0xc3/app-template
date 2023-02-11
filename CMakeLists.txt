cmake_minimum_required(VERSION 3.5)
project(app_template LANGUAGES C)

if(LINUX)
    set(CMAKE_C_COMPILER "/usr/bin/clang")
    set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
endif()

message("CMAKE_BUILD_TYPE:   ${CMAKE_BUILD_TYPE}")
message("CMAKE_C_COMPILER:   ${CMAKE_C_COMPILER}")
message("CMAKE_CXX_COMPILER: ${CMAKE_CXX_COMPILER}")

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message("Setting build type to 'Debug' as none was specified.")

  set(CMAKE_BUILD_TYPE Debug)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

# ==============================================================================
# Headers and sources
# ==============================================================================

set(HEADERS
)

set(SOURCES
    src/main.c
)

# ==============================================================================
# Target definition
# ==============================================================================

set(TARGET app_template)
add_executable(${TARGET} ${HEADERS} ${SOURCES})

# ==============================================================================
# External
# ==============================================================================

target_include_directories(${TARGET} PRIVATE 
    ${PROJECT_SOURCE_DIR}/external/glad/include
)

# ==============================================================================
# Target properties
# ==============================================================================

set_target_properties(${TARGET} PROPERTIES C_STANDARD 11)
set_target_properties(${TARGET} PROPERTIES C_EXTENSIONS OFF)

# ==============================================================================
# Compile options
# ==============================================================================

if(MSVC)
    target_compile_options(${TARGET} PRIVATE /W4 /D_CRT_SECURE_NO_WARNINGS)
    target_compile_options(${TARGET} PRIVATE /fp:fast)
else()
    target_compile_options(${TARGET} PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(${TARGET} PRIVATE -ffast-math)
endif()

if(UNIX AND NOT APPLE)
    target_compile_options(${TARGET} PRIVATE -D_POSIX_C_SOURCE=200809L)
endif()

# ==============================================================================
# Link libraries
# ==============================================================================

if(WIN32)
    target_link_libraries(${TARGET} PRIVATE )
elseif(LINUX)
    target_link_libraries(${TARGET} PRIVATE )
endif()

# ==============================================================================
# Asset files
# ==============================================================================

set(ASSETS_SRC "${CMAKE_SOURCE_DIR}/assets")
set(ASSETS_DST "$<TARGET_FILE_DIR:${TARGET}>/assets")

if(WIN32)
    set(ASSETS_CMD copy_directory)
    set(ASSETS_MSG "Copy assets")
else()
    set(ASSETS_CMD create_symlink)
    set(ASSETS_MSG "Link assets")
endif()

add_custom_command(TARGET ${TARGET} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo
    "${ASSETS_MSG}: ${ASSETS_SRC} to ${ASSETS_DST}"
)
add_custom_command(TARGET ${TARGET} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E ${ASSETS_CMD}
    "${ASSETS_SRC}" "${ASSETS_DST}"
)
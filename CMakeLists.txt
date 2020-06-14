cmake_minimum_required(VERSION 3.8.2)

if (DEFINED PROJECT_NAME)
  set(is_module ON)
endif()

# This project is C++ only but also sets C as language for the sole purpose of
# enabling full compiler checks for both languages. The C language is used by
# the OS target in this project.
project(CoAP VERSION 0.1.0 LANGUAGES CXX)

cmake_policy(SET CMP0079 NEW)


################################################################################
# CMake modules.

if (is_module)
  ##############################################################################
  # Library sources.
  set(_source_dir "src")

  list(APPEND _include_directories
    ${_source_dir}
    .
  )

  list(APPEND _header_files
    code.hpp
  )

  list(APPEND _source_files
    code.cpp
  )

  list(TRANSFORM _include_directories PREPEND "${PROJECT_SOURCE_DIR}/${_source_dir}/")
  list(TRANSFORM _header_files PREPEND "${PROJECT_SOURCE_DIR}/${_source_dir}/")
  list(TRANSFORM _source_files PREPEND "${PROJECT_SOURCE_DIR}/${_source_dir}/")

  list(APPEND _sources
    ${_header_files}
    ${_source_files}
  )

  add_library(${PROJECT_NAME} STATIC)

  target_include_directories(${PROJECT_NAME}
    PUBLIC
      ${_include_directories}
  )

  target_sources(${PROJECT_NAME}
    PRIVATE
      ${_sources}
  )

  target_compile_features(${PROJECT_NAME}
    PUBLIC
      cxx_std_17
  )

  add_library(Sdk::${PROJECT_NAME} ALIAS ${PROJECT_NAME})


else()
  ##############################################################################
  # Test build.
  set(PROJECT_NAME ${PROJECT_NAME}Test)

  set(_dut_source_dir "src")
  set(_test_dir "test")

  list(APPEND _dut_include_directories
    ${_dut_source_dir}
  )

  list(APPEND _dut_header_files
    coap.hpp
    code.hpp
    header.hpp
    section.hpp
    token.hpp
    type.hpp
  )

  list(APPEND _dut_source_files
    coap.cpp
    code.cpp
    header.cpp
    token.cpp
    type.cpp
  )

  list(APPEND _test_include_directories
    .
  )

  list(APPEND _test_helpers_header_files
  )

  list(APPEND _test_helpers_source_files
  )

  list(APPEND _test_helpers_test_source_files
  )

  list(APPEND _test_header_files
  )

  list(APPEND _test_source_files
    code/code.cpp
    code/test-data.hpp
    type/test-data.hpp
    type/type.cpp
    header/header.cpp
    header/test-data.hpp
    coap.cpp
    token/test-data.hpp
    token/token.cpp

    # Runner
    runner.cpp
  )

  list(TRANSFORM _dut_include_directories PREPEND "${PROJECT_SOURCE_DIR}/")
  list(TRANSFORM _dut_header_files PREPEND "${PROJECT_SOURCE_DIR}/${_dut_source_dir}/")
  list(TRANSFORM _dut_source_files PREPEND "${PROJECT_SOURCE_DIR}/${_dut_source_dir}/")
  list(TRANSFORM _test_include_directories PREPEND "${PROJECT_SOURCE_DIR}/")
  list(TRANSFORM _test_helpers_header_files PREPEND "${PROJECT_SOURCE_DIR}/${_test_dir}/")
  list(TRANSFORM _test_helpers_source_files PREPEND "${PROJECT_SOURCE_DIR}/${_test_dir}/")
  list(TRANSFORM _test_helpers_test_source_files PREPEND "${PROJECT_SOURCE_DIR}/${_test_dir}/")
  list(TRANSFORM _test_header_files PREPEND "${PROJECT_SOURCE_DIR}/${_test_dir}/")
  list(TRANSFORM _test_source_files PREPEND "${PROJECT_SOURCE_DIR}/${_test_dir}/")

  list(APPEND _include_directories
    ${_dut_include_directories}
    ${_test_include_directories}
  )
  list(APPEND _sources
    ${_dut_header_files}
    ${_dut_source_files}
    ${_test_helpers_header_files}
    ${_test_helpers_source_files}
    ${_test_helpers_test_source_files}
    ${_test_header_files}
    ${_test_source_files}
  )

  add_executable(${PROJECT_NAME})

  target_include_directories(${PROJECT_NAME}
    PRIVATE
      ${_include_directories}
  )

  target_sources(${PROJECT_NAME}
    PRIVATE
      ${_sources}
  )

  option(CATCH_BUILD_TESTING "Build SelfTest project" OFF)
  option(CATCH_BUILD_EXAMPLES "Build documentation examples" OFF)
  option(CATCH_BUILD_EXTRA_TESTS "Build extra tests" OFF)
  option(CATCH_INSTALL_DOCS "Install documentation alongside library" OFF)
  option(CATCH_INSTALL_HELPERS "Install contrib alongside library" OFF)
  add_subdirectory(modules/catch2)

  target_link_libraries(${PROJECT_NAME}
    PRIVATE
      Catch2::Catch2
  )

  target_compile_features(${PROJECT_NAME}
    PRIVATE
      cxx_std_17
  )

  target_compile_options(${PROJECT_NAME}
    PRIVATE
      -Werror
      -Wall
  )

endif()

set_target_properties(${PROJECT_NAME} PROPERTIES
  VERSION ${PROJECT_VERSION}
)

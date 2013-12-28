project(green-leaf-tests C CXX)

set(BUILD_SHARED_LIBS ON)

set(TEST_DIR ${CMAKE_CURRENT_BINARY_DIR})

include(ExternalProject)
ExternalProject_Add(GoogleMock
  URL "https://googlemock.googlecode.com/files/gmock-1.7.0.zip"
  URL_HASH SHA1=f9d9dd882a25f4069ed9ee48e70aff1b53e3c5a5
  PREFIX "${TEST_DIR}/gmock"
  CMAKE_ARGS -DBUILD_SHARED_LIBS=ON
  INSTALL_COMMAND ""
)

ExternalProject_Get_Property(GoogleMock
  source_dir
  binary_dir
)

file(
  GLOB
  TEST_FILES
  "${TEST_DIR}/*_test.cpp"
)

set(GREEN_LEAF_TESTS_SRC
  ${TEST_FILES}
  runner.cpp
)

add_custom_target(test
  COMMAND green-leaf-tests
  ARGS "--gtest_shuffle"
  DEPENDS green-leaf-tests
)

add_executable(green-leaf-tests
  EXCLUDE_FROM_ALL
  ${GREEN_LEAF_TESTS_SRC}
)

add_dependencies(green-leaf-tests GoogleMock)

include_directories(
  "${TEST_DIR}/../src"
  "${source_dir}/include"
  "${source_dir}/gtest/include"
)

if(APPLE)
  set(SUFFIX ".dylib")
else(APPLE)
  set(SUFFIX ".so")
endif(APPLE)

target_link_libraries(green-leaf-tests
  ${SDL2_LIBRARY}
  ${SDL2_IMAGE_LIBRARY}
  "${binary_dir}/${CMAKE_FIND_LIBRARY_PREFIXES}gmock${SUFFIX}"
  "${binary_dir}/gtest/${CMAKE_FIND_LIBRARY_PREFIXES}gtest${SUFFIX}"
)
cmake_minimum_required(VERSION 2.6)
project(Snake)

# Use FindSDL2* modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${Snake_SOURCE_DIR}/cmake")
set(BIN_DIR ${CMAKE_SOURCE_DIR}/bin)
set(GTEST_ROOT "${Snake_SOURCE_DIR}/deps/googletest/googletest")
set(GMOCK_ROOT "${Snake_SOURCE_DIR}/deps/googletest/googlemock")
set(CMAKE_EXPORT_COMPILE_COMMANDS "ON")

# Bump up warning levels appropriately for clang, gcc & msvc
# Also set debug/optimization flags depending on the build type. IDE users choose this when
# selecting the build mode in their IDE
if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++11")
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG} -g")
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE} -O2")
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
  if (CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
    string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
  endif()
endif()

enable_testing()

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(GTest REQUIRED)
find_package(GMock REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})
include_directories(${SDL2_IMAGE_INCLUDE_DIR})
include_directories(${SDL2_MIXER_INCLUDE_DIR})
include_directories(${SDL2_TTF_INCLUDE_DIR})

include_directories(include)

add_executable(Snake
  src/main.cpp
  src/snake/game.cpp
  src/snake/tilemap.cpp
  src/snake/game_object.cpp
  src/snake/tail_node.cpp
  src/snake/player.cpp
  src/snake/audio.cpp)

target_link_libraries(Snake
  ${SDL2_LIBRARY}
  ${SDL2_IMAGE_LIBRARY}
  ${SDL2_MIXER_LIBRARY}
  ${SDL2_TTF_LIBRARY}
)
install(TARGETS Snake RUNTIME DESTINATION ${BIN_DIR})

add_executable(RunTests test/run_tests.cpp)
target_link_libraries(RunTests ${GTEST_BOTH_LIBRARIES} ${GMOCK_BOTH_LIBRARIES} pthread)
add_test(RunTests RunTests)

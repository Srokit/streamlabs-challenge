
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# expected behaviour
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++lastest")

project(StreamLabsStore)

include_directories(./customer)

set(BUY_SOURCES ./main.cpp ./customer/Customer.cpp)

add_executable(buy_from_stream_labs_store ${BUY_SOURCES})

add_subdirectory(store)

include_directories(./store)
include_directories(./store/nlohmann_json/include)

target_link_libraries(buy_from_stream_labs_store PRIVATE stream_labs_store)
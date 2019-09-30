cmake_minimum_required (VERSION 2.6)
project (road)
add_executable(road simulation.cpp road.cpp vehicle.cpp van.cpp vehicle_factory.hpp bold.cpp cautious.cpp)
target_compile_options(road PRIVATE -std=c++11 -Wall -Werror)

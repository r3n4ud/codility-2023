cmake_minimum_required(VERSION 3.26)
project(codility CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

Include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.1
)

FetchContent_MakeAvailable(Catch2)

add_executable(lesson1 lesson1/binary_gap.cpp)
target_link_libraries(lesson1 PRIVATE Catch2::Catch2WithMain)

add_executable(lesson2 lesson2/cyclic_rotation.cpp lesson2/odd_occurrences_in_array.cpp)
target_link_libraries(lesson2 PRIVATE Catch2::Catch2WithMain)

set(lesson3_items frog_jmp perm_missing_elem tape_equilibrium)
foreach(item IN LISTS lesson3_items)
  add_executable("lesson3-${item}" "lesson3/${item}.cpp")
  target_link_libraries("lesson3-${item}" PRIVATE Catch2::Catch2WithMain)
endforeach()

set(lesson4_items frog_river_one perm_check max_counters missing_integer)
foreach(item IN LISTS lesson4_items)
  add_executable("lesson4-${item}" "lesson4/${item}.cpp")
  target_link_libraries("lesson4-${item}" PRIVATE Catch2::Catch2WithMain)
endforeach()

set(lesson5_items passing_cars count_div genomic_range_query min_avg_two_slice)
foreach(item IN LISTS lesson5_items)
  add_executable("lesson5-${item}" "lesson5/${item}.cpp")
  target_link_libraries("lesson5-${item}" PRIVATE Catch2::Catch2WithMain)
endforeach()

set(lesson6_items distinct max_product_of_three)# triangle number_of_disc_intersections)
foreach(item IN LISTS lesson6_items)
  add_executable("lesson6-${item}" "lesson6/${item}.cpp")
  target_link_libraries("lesson6-${item}" PRIVATE Catch2::Catch2WithMain)
endforeach()


set(tasks_items task1 task2)
foreach(item IN LISTS tasks_items)
  add_executable("tasks-${item}" "tasks/${item}.cpp")
  target_link_libraries("tasks-${item}" PRIVATE Catch2::Catch2WithMain)
endforeach()

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)
catch_discover_tests(lesson1)
catch_discover_tests(lesson2)
foreach(item IN LISTS lesson3_items)
  catch_discover_tests(lesson3-${item})
endforeach()
foreach(item IN LISTS lesson4_items)
  catch_discover_tests(lesson4-${item})
endforeach()
foreach(item IN LISTS lesson5_items)
  catch_discover_tests(lesson5-${item})
endforeach()
foreach(item IN LISTS lesson6_items)
  catch_discover_tests(lesson6-${item})
endforeach()

foreach(item IN LISTS tasks_items)
  catch_discover_tests(tasks-${item})
endforeach()

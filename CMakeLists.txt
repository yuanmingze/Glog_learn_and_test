cmake_minimum_required(VERSION 3.10)
project(GlogLearnAndTest)

find_package(glog REQUIRED)

add_subdirectory(00_severityLevel)
add_subdirectory(01_flagsSetting)
add_subdirectory(02_conditional)
add_subdirectory(03_debugmode)
add_subdirectory(04_checkmacros)
add_subdirectory(05_verbose)
add_subdirectory(06_failureSignalHandler)
add_subdirectory(07_miscellaneous)
cmake_minimum_required(VERSION 3.0)

# set the project name
project(is_prime_prog)

# add the lib
#add_library(mysource SHARED is_prime_prog.cpp)

# add another
#add_library(mysource_2 SHARED sources_2.cpp)

# add the executable
add_executable(main main.cpp)

# do not forget to link
#target_link_libraries(main mysource)

#target_link_libraries(main mysource_2)

cmake_minimum_required(VERSION 3.0)
project(unp)
file(GLOB LIB_SOURCES lib/*.c)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I/usr/include -lc  -std=C99")
include_directories(include)
add_library(libunp.a STATIC ${LIB_SOURCES})

add_executable(daytimetcpcli.out intro/daytimetcpcli.c)
target_link_libraries(daytimetcpcli.out libunp.a)

add_executable(daytimetcpcli1.out intro/daytimetcpcli1.c)
target_link_libraries(daytimetcpcli1.out libunp.a)

add_executable(daytimetcpcliv6.out intro/daytimetcpcliv6.c)
target_link_libraries(daytimetcpcliv6.out libunp.a)

add_executable(daytimetcpsrv.out intro/daytimetcpsrv.c)
target_link_libraries(daytimetcpsrv.out libunp.a)

add_executable(daytimetcpsrv1.out intro/daytimetcpsrv1.c)
target_link_libraries(daytimetcpsrv1.out libunp.a)



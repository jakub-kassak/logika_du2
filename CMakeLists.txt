cmake_minimum_required(VERSION 3.16)
project(logika_du2)

set(CMAKE_CXX_STANDARD 14)

add_executable(logika_du2 src/testlp.cpp src/lphelper.hpp src/cchi.cpp src/main.cpp src/cchi.h)

include_directories(/usr/include/lpsolve/)

find_library(LPSOLVE55_LIBRARY lpsolve55 /usr/lib)
SET(POSTLINKFLAGS -ldl)
target_link_libraries(logika_du2 LINK_PUBLIC ${LPSOLVE55_LIBRARY})



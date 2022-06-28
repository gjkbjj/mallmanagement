cmake_minimum_required(VERSION 3.22)
project(JDultimated)

set(CMAKE_CXX_STANDARD 14)
#声明头文件路径
set(INC_DIR C:\\Program\ Files\\MySQL\\MySQL\ Server\ 5.7\\include)

#声明链接库路径
set(LINK_DIR C:\\Program\ Files\\MySQL\\MySQL\ Server\ 5.7\\lib)
set(CMAKE_EXE_LINKER_FLAGS "-static")
#引入头文件
include_directories(${INC_DIR})

#引入库文件
link_directories(${LINK_DIR})
link_libraries(libmysql)

add_executable(JDultimated main.cpp user/user.cpp user/user.h db/db.cpp db/db.h s.h  s.cpp s.cpp menu.cpp)
target_link_libraries(JDultimated libmysql)
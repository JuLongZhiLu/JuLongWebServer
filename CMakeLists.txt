# 指定 CMake 最低版本要求
cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(WebServer VERSION 0.0.1)

# 添加可执行文件并指定源文件
add_executable(main
    main.cpp
    webserver.hpp
    webserver.cpp
)

message("Project:${PROJECT_NAME} Version: ${PROJECT_VERSION}")


cmake_minimum_required(VERSION 3.27)
project(StaMenu C)

set(CMAKE_C_STANDARD 23)

add_executable(StaMenu main.c
        securereading.c)

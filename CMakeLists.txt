cmake_minimum_required(VERSION 3.10)

project(sh)

set(CMAKE_C_STANDARD 99)

add_executable(sh
    ../src/main.c
    ../src/readLine.c
    ../src/splitLine.c
    ../src/executeCommand.c
    ../src/builtins.c
    ../src/runShell.c
    ../src/commandHistory.c
)
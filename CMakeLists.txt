cmake_minimum_required(VERSION 3.10)
project(Tan C)

set(CMAKE_C_STANDARD 11)

include_directories(Driver/Include)
include_directories(Game/Include)
include_directories(Shared)

add_executable(Tan
        Driver/Include/Driver.h
        Driver/Include/Human.h
        Driver/Include/StringConstants.h
        Driver/Chess.c
        Driver/Driver.c
        Driver/Human.c
        Game/Include/Game.h
        Game/Game.c
        Shared/Elements.h)

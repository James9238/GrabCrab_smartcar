cmake_minimum_required(VERSION 3.17)
project(DC_Control)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(DC_Control
        DC_Control.ino
        Direction_control.ino
        Functions_motor_control.ino
        MAIN.ino
        Serial_Comm.ino
        setup_functions.ino)

cmake_minimum_required(VERSION 3.15)
project(AntsVsBees)

set(CMAKE_CXX_STANDARD 17)

add_executable(AntsVsBees main.cpp Bee.cpp Bee.h Ant.cpp Ant.h AntsVsBees.cpp AntsVsBees.h Ant_Harvester.cpp Ant_Harvester.h Ant_Thrower.cpp Ant_Thrower.h Ant_Fire.cpp Ant_Fire.h Ant_LongThrow.cpp Ant_LongThrow.h Ant_ShortThrow.cpp Ant_ShortThrow.h Ant_Wall.cpp Ant_Wall.h Ant_Ninja.cpp Ant_Ninja.h Ant_Bodyguard.cpp Ant_Bodyguard.h Bug.cpp Bug.h BugBoard.cpp BugBoard.h)
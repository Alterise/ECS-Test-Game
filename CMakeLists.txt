cmake_minimum_required(VERSION 3.10)
project(ecs-test)

add_executable(test
        main.cpp Character.cpp DamageSystem.cpp GameSystem.cpp TargetSystem.cpp)

add_subdirectory(entt)

include_directories(entt/src)
cmake_minimum_required(VERSION 3.24)
project(project_1_team_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)
include_directories(test)

add_executable(project_1_team_1
        src/FlatFileStorageDevice.cpp
        src/FlatFileStorageDevice.h
        src/KeyStorage.h
        src/KeyStorageTanis.cpp
        src/main.cpp
        src/StorageDevice.h
        test/FlatFileStorageDeviceSpec.h test/KeyStorageTanisSpec.h src/KeyStorageAdam.cpp src/KeyStorageAriel.cpp)

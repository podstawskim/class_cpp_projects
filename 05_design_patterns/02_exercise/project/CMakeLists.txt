cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)
project(project)

add_library(utils
        include/Calculator.h
        src/Calculator.cpp)

target_include_directories(utils PUBLIC include)

add_executable(runner src/main.cpp
        include/observer/observers/Observer.h
        include/observer/observers/Observable.h
        include/observer/observers/Displacement.h
        include/observer/observers/Acceleration.h
        include/observer/observers/Speed.h
        src/observer/observers/Observable.cpp
        src/observer/observers/Displacement.cpp
        src/observer/observers/Speed.cpp
        src/observer/observers/Acceleration.cpp
        include/factory/executor/Core.h
        include/factory/executor/AnisotropicCudaCore.h
        src/factory/executor/AnisotropicCudaCore.cpp
        include/factory/executor/ElasticCudaCore.h
        src/factory/executor/ElasticCudaCore.cpp
        include/factory/executor/AcousticCudaCore.h
        src/factory/executor/AcousticCudaCore.cpp
        include/factory/executor/AnisotropicCpuCore.h
        src/factory/executor/AnisotropicCpuCore.cpp
        include/factory/executor/ElasticCpuCore.h
        src/factory/executor/ElasticCpuCore.cpp
        include/factory/executor/AcousticCpuCore.h
        src/factory/executor/AcousticCpuCore.cpp
        include/factory/executor/CoreFactory.h
        include/factory/executor/CudaCoreFactory.h
        src/factory/executor/CudaCoreFactory.cpp
        include/factory/executor/CpuCoreFactory.h
        src/factory/executor/CpuCoreFactory.cpp
        include/factory/executor/Demo.h
        src/factory/executor/Demo.cpp
        include/factory/gui/Widget.h
        include/factory/gui/CheckBoxKdeWidget.h
        src/factory/gui/CheckBoxKdeWidget.cpp
        include/factory/gui/ListKdeWidget.h
        src/factory/gui/ListKdeWidget.cpp
        include/factory/gui/ButtonKdeWidget.h
        src/factory/gui/ButtonKdeWidget.cpp
        include/factory/gui/CheckBoxGnomeWidget.h
        src/factory/gui/CheckBoxGnomeWidget.cpp
        include/factory/gui/ListGnomeWidget.h
        src/factory/gui/ListGnomeWidget.cpp
        include/factory/gui/ButtonGnomeWidget.h
        src/factory/gui/ButtonGnomeWidget.cpp
        include/factory/gui/WidgetFactory.h
        include/factory/gui/KdeWidgetFactory.h
        src/factory/gui/KdeWidgetFactory.cpp
        include/factory/gui/GnomeWidgetFactory.h
        src/factory/gui/GnomeWidgetFactory.cpp
        include/factory/gui/Demo.h
        src/factory/gui/Demo.cpp)
target_link_libraries(runner PRIVATE utils)

add_subdirectory(tests)

cmake_minimum_required(VERSION 3.13)
project(DesignPatterns)

set(CMAKE_CXX_STANDARD 14)

add_executable(DesignPatterns main.cpp Command.h AbstractFactory.h Builder.h Decorator.h FactoryMethod.h Introduction.h Observer.h SimpleFactory.h Singleton.h Strategy.h Test.h Adapter.h)
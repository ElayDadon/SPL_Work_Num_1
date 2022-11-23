cmake_minimum_required(VERSION 3.23)
project(Assignment1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Assignment1 src/main.cpp src/Agent.cpp src/Coalition.cpp src/EdgeWeightSelectionPolicy.cpp src/Graph.cpp src/LastOfferJoinPolicy.cpp src/MandatesJoinPolicy.cpp src/MandatesSelectionPolicy.cpp src/Parser.cpp src/Party.cpp src/Simulation.cpp include/Agent.h include/Coalition.h include/Graph.h include/JoinPolicy.h include/json.hpp include/Parser.h include/Party.h include/SelectionPolicy.h include/Simulation.h)


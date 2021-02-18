set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
cmake_minimum_required(VERSION 2.8)


project(Euchre)

add_executable(euchre main.cpp Euchre.cpp Deck.cpp Player.cpp Card.cpp)

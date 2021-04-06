add_compile_options(-std=c++11) # CMake 2.8.12 or newer


project(Euchre)

add_executable(euchre main.cpp Euchre.cpp Deck.cpp Player.cpp Card.cpp)

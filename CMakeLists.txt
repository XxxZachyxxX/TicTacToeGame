cmake_minimum_required(VERSION 3.10)
project(TicTacToe VERSION 1.0)

# C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include Verzeichnisse
include_directories(include)

# Quellen finden
file(GLOB SOURCES "src/*.cpp")

# Erstelle die ausführbare Datei
add_executable(TicTacToe ${SOURCES})

# Falls du SFML oder andere Abhängigkeiten verwendest
find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)
target_link_libraries(TicTacToe sfml-system sfml-window sfml-graphics sfml-audio)

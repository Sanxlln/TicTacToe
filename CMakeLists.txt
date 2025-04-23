cmake_minimum_required(VERSION 3.10)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    main.cpp
    print.cpp
    winner.cpp
    saveToHistory.cpp
    startGame.cpp
    loadSetting.cpp
    saveSetting.cpp
    showHistory.cpp
)

add_executable(tic_tac_toe ${SOURCES})

cmake_minimum_required(VERSION 3.10)


project(TicTacToe)

option(USE_STATIC_LIB  OFF)
option(USE_SHARED_LIB OFF)


if(USE_STATIC_LIB AND USE_SHARED_LIB)
    message(FATAL_ERROR )
elseif(NOT USE_STATIC_LIB AND NOT USE_SHARED_LIB)
    message(FATAL_ERROR "Потрібно вибрати або статичну (USE_STATIC_LIB=ON), або динамічну (USE_SHARED_LIB=ON) бібліотеку.")
endif()


message("Статична бібліотека: ${USE_STATIC_LIB}")
message("Динамічна бібліотека: ${USE_SHARED_LIB}")


set(LIB_HEADERS
    print.hpp
    winner.hpp
    saveToHistory.hpp
    startGame.hpp
    loadSetting.hpp
    saveSetting.hpp
    showHistory.hpp
)

set(LIB_SOURCES
    print.cpp
    winner.cpp
    saveToHistory.cpp
    startGame.cpp
    loadSetting.cpp
    saveSetting.cpp
    showHistory.cpp
)


if (USE_STATIC_LIB)
    add_library(TicTacToeLib STATIC ${LIB_SOURCES})
elseif(USE_SHARED_LIB)
    add_library(TicTacToeLib SHARED ${LIB_SOURCES})
    target_compile_definitions(TicTacToeLib PRIVATE TicTacToeLib_EXPORTS)
endif()


target_include_directories(TicTacToeLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE TicTacToeLib)


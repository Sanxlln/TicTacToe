#include "showHistory.hpp"
#include <fstream>
#include <iostream>
#include <string>

void showHistory() {
    std::ifstream history("history.txt");
    if (!history.is_open()) {
        std::cout << "No game history available." << std::endl;
        return;
    }
    std::string line;
    std::cout << "Game History:" << std::endl;
    while (std::getline(history, line)) {
        std::cout << line << std::endl;
    }
    history.close();
}

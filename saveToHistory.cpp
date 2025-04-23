#include "saveToHistory.hpp"
#include <fstream>
#include <iostream>

void saveToHistory(const std::string& winner, const std::string& player1, const std::string& player2) {
    std::ofstream history("history.txt", std::ios::app);
    if (!history.is_open()) {
        std::cout << "Error saving to history." << std::endl;
        return;
    }
    history << "Winner: " << winner << " | " << player1 << " vs " << player2 << std::endl;
    history.close();
}

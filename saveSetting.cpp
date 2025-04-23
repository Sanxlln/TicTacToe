#include "saveSetting.hpp"
#include <fstream>
#include <iostream>

void saveSettings(const std::string& player1, const std::string& player2, int boardSize) {
    std::ofstream settings("settings.txt");
    if (!settings.is_open()) {
        std::cout << "Error saving settings." << std::endl;
        return;
    }
    settings << player1 << std::endl << player2 << std::endl << boardSize << std::endl;
    settings.close();
    std::cout << "Settings saved successfully." << std::endl;
}

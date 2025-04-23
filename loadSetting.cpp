#include "loadSetting.hpp"
#include <fstream>

bool loadSettings(std::string& player1, std::string& player2, int& boardSize) {
    std::ifstream settings("settings.txt");
    if (!settings) return false;
    std::getline(settings, player1);
    std::getline(settings, player2);
    settings >> boardSize;
    return true;
}
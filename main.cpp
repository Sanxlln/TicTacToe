#include <iostream>
#include <string>
#include "print.hpp"
#include "startGame.hpp"
#include "loadSetting.hpp"
#include "saveSetting.hpp"
#include "showHistory.hpp"

int main() {
    std::string player1, player2;
    int boardSize = 3;
    if (!loadSettings(player1, player2, boardSize)) {
        std::cout << "No settings found! Set player names and board size first." << std::endl;
    }

    while (true) {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Start New Game" << std::endl;
        std::cout << "2. Parameters" << std::endl;
        std::cout << "3. Game History" << std::endl;
        std::cout << "4. Exit" << std::endl;

        int choice;
        std::cin >> choice;
        if (choice == 1) {
            std::cout << "Game starts!";
            startGame(player1, player2, boardSize);
        } 
        else if (choice == 2) {
            while (true) {
                system("cls");
                std::cout << "Settings Menu:" << std::endl;
                std::cout << "1. Change Player 1 Name: " << player1 << std::endl;
                std::cout << "2. Change Player 2 Name: " << player2 << std::endl;
                std::cout << "3. Change Board Size: " << boardSize << std::endl;
                std::cout << "4. Save and Return to Main Menu" << std::endl;
                std::cout << "Select option: ";
                int settingChoice;
                std::cin >> settingChoice;
                if (settingChoice == 1) {
                    std::cout << "Enter new name for Player 1: ";
                    std::getline(std::cin, player1);
                } 
                else if (settingChoice == 2) {
                    std::cout << "Enter new name for Player 2: ";
                    std::getline(std::cin, player2);
                } 
                else if (settingChoice == 3) {
                    std::cout << "Enter new board size (minimum 3): ";
                    std::cin >> boardSize;
                    if (boardSize < 3) boardSize = 3;
                } 
                else if (settingChoice == 4) {
                    saveSettings(player1, player2, boardSize);
                    break;
                } 
                else {
                    std::cout << "Invalid choice, try again." << std::endl;
                }
            }
        } 
        else if (choice == 3) {
            showHistory();
            std::cout << "Press Enter to return to the menu.";
        } 
        else if (choice == 4) {
            std::cout << "Thanks for playing! Goodbye." << std::endl;
            break;
        } 
        else {
            std::cout << "Invalid choice. Press Enter.";
        }
    }

    return 0;
}

#include <iostream>
#include <vector>
#include"print.hpp"
void printBoard(const std::vector<std::vector<char>>& board) {
    system("cls");
    int size = board.size();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << " " << board[i][j] << " ";
            if (j < size - 1) {
            std::cout << "|";
        }
    }
    std::cout << std::endl;
    if (i < size - 1) {
        for (int j = 0; j < size; j++) {
            std::cout << "---";
            if (j < size - 1) {
                std::cout << "+";
            }
        }
    std::cout << std::endl;
    }
    }
}
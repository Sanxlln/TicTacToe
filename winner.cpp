#include "winner.hpp"
#include<iostream>

bool checkWinner(const std::vector<std::vector<char>>& board, char playerMark) {
    int size = board.size();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= size - 3; j++) {
            if (board[i][j] == playerMark && board[i][j + 1] == playerMark && board[i][j + 2] == playerMark) {
                return true;
            }
        }
    }
    for (int i = 0; i <= size - 3; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] == playerMark && board[i + 1][j] == playerMark && board[i + 2][j] == playerMark) {
                return true;
            }
        }
    }
    for (int i = 0; i <= size - 3; i++) {
        for (int j = 0; j <= size - 3; j++) {
            if (board[i][j] == playerMark && board[i + 1][j + 1] == playerMark && board[i + 2][j + 2] == playerMark) {
                return true;
            }
        }
    }
    for (int i = 0; i <= size - 3; i++) {
        for (int j = 2; j < size; j++) {
            if (board[i][j] == playerMark && board[i + 1][j - 1] == playerMark && board[i + 2][j - 2] == playerMark) {
                return true;
            }
        }
    }
    return false;
}

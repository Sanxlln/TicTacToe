#include "startGame.hpp"
#include "print.hpp"
#include "winner.hpp"
#include "saveToHistory.hpp"
#include <vector>
#include <iostream>

void startGame(std::string player1, std::string player2, int boardSize) {
    std::vector<std::vector<char>> board(boardSize, std::vector<char>(boardSize, ' '));
    bool gameOver = false;
    char currentMark = 'X';
    std::string currentPlayer = player1;

    while (!gameOver) {
        printBoard(board);
        int row, col;
        while (true) {
            std::cout << currentPlayer << ", enter row and column: ";
            std::cin >> row >> col;
            if (row < 1 || row > boardSize || col < 1 || col > boardSize || board[row - 1][col - 1] != ' ') {
                std::cout << "Invalid move! Try again.\n";
                continue;
            }
            break;
        }
        board[row - 1][col - 1] = currentMark;
        if (checkWinner(board, currentMark)) {
            printBoard(board);
            std::cout << currentPlayer << " wins!" << std::endl;
            saveToHistory(currentPlayer, player1, player2);
            gameOver = true;
            break;
        }
        currentMark = (currentMark == 'X') ? 'O' : 'X';
        currentPlayer = (currentPlayer == player1) ? player2 : player1;
    }

    std::cout << "Do you want to start a new game or return to the main menu?" << std::endl;
    std::cout << "1. New Game\n2. Main Menu" << std::endl;
    int choice;
    std::cin >> choice;
    if (choice == 1) {
        startGame(player1, player2, boardSize);
    }
}

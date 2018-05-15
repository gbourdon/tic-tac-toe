#include <iostream>
#include "win.h"
#include "board_utils.h"

int main()
{
    std::cout << "Tic-Tac-Toe \n"
    "How to Play: \n"
    "Enter the value of the space you want to mark in \'x x\' (Row, Collom) format. You can use A-C and 1-3." << std::endl;

    const size_t BOARD_SIZE = 3;
    int board[BOARD_SIZE][BOARD_SIZE] ={{0,0,0},{0,0,0},{0,0,0}};
    int player = 1; // Add option to chose 1st player?

    while (is_filled(board, BOARD_SIZE) == false) {
        std::cout << "It is player "<< player << "'s turn" << std::endl;
        disp_board(std::cout, board, true);
        char c_r, c_c;
        while (true) {
            std::cin >> c_r;
            std::cin >> c_c;
            int r = char_convert(c_r);
            int c = char_convert(c_c);
            if (board[r][c] == 0) {
                board[r][c] = player;
                break;
            } else { std::cout << "Value already filled" << std::endl; }
        }
        if (player == 1) { player = 2;} else {player = 1;}
        std::cout << std::endl;
        if (check_win(board, 1)) {
            std::cout << "Player 1 wins!" << std::endl;
            disp_board(std::cout, board, true);
            return 0;
        }
        if (check_win(board, 2)) {
            std::cout << "Player 2 wins!" << std::endl;
            disp_board(std::cout, board, true);
            return 0;
        }
    }
    std::cout << "Draw!" << std::endl;
    return 0;
}

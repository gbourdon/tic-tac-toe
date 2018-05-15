#include "board_utils.h"

int char_convert(char cha) {
    switch(cha) {
    // Converts lowercase chars
    case 'a':
        return 0;
        break;
    case 'b':
        return 1;
        break;
    case 'c':
        return 2;
        break;
    // Converts uppercase chars
    case 'A':
        return 0;
        break;
    case 'B':
        return 1;
        break;
    case 'C':
        return 2;
        break;
    // Converts numbers
    case '1':
        return 0;
        break;
    case '2':
        return 1;
        break;
    case '3':
        return 2;
        break;
    default:
        return 4;
        break;
    }
}

bool is_filled(int board[][3], size_t BOARD_SIZE) {
    for (int r = 0; r != 3; r++)
        for (int c = 0; c != 3; c++)
           if (board[r][c] == 0)
            return false; // Returns false if any of the spaces in the board is '0', or blank
    return true;
}

char parse_char(int cha) {
    switch(cha) {
    case 0:
        return ' ';
        break;
    case 1:
        return 'X';
        break;
    case 2:
        return 'O';
        break;
    default:
        return ' ';
        break;
    }
}

void disp_board(std::ostream& out,int board[][3], bool parse = false) {
    for (int r = 0; r != 3; r++) {
        for (int c = 0; c != 3; c++) {
            if (parse) {out << parse_char(board[r][c]);} else {out << board[r][c];} // Puts the parsed output out if parsing, otherwise puts the raw output
            if (c != 2)
                out << '|'; // Seperates the rows
        }
        out << std::endl;
    }
}

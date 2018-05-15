#ifndef BOARD_UTILS_H_INCLUDED
#define BOARD_UTILS_H_INCLUDED

#include <iostream>

int char_convert(char cha);
bool is_filled(int board[][3], size_t BOARD_SIZE);
char parse_char(int cha);
void disp_board(std::ostream& out,int board[][3], bool parse);

#endif // BOARD_UTILS_H_INCLUDED

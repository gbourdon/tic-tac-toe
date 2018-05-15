#ifndef WIN_H_INCLUDED
#define WIN_H_INCLUDED

bool check_win(int board[][3], int target);
bool win(int board[][3], int r, int c, int target, int depth, int previousRow, int previousCollum);

#endif // WIN_H_INCLUDED

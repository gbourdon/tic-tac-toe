#include "win.h"

     /** \brief Returns if the current square has three adjacent to it in a row (the condition for winning in tic-tac-toe
      *
      * \param Board int[][3] The board you want to check
      * \param r int The row of the square to check
      * \param c int The collum of the square to check
      * \param target int What do you want to check for?
      * \param depth int Used by the function, shouldn't be used normally, gives how many in a row it found
      * \param previousRow & previousCollum int Used by the function, gives the previous row it was at, used to avoid backtracking
      * \return bool Does the square indicated have three in a row?
      *
      */
bool win(int board[][3], int r, int c, int target, int depth = 1, int previousRow = 10, int previousCollum = 10) {
    if (r >= 4 || r < 0 || c >= 4 || c < 0) // Unless the area is out of bounds
        return false;
    if (target == board[r][c]) {
        //std::cout << depth << std::endl;
        if (depth == 3) {
            return true;
        } else {
            if (previousRow > 4 || previousCollum > 4) {
              if (win(board, r + 1, c + 1, target, depth + 1, r, c) || win(board, r + 1, c, target, depth + 1, r, c) ||
                win(board, r, c + 1, target, depth + 1, r, c) || win(board, r - 1, c - 1, target, depth + 1, r, c) ||
                win(board, r - 1, c - 1, target, depth + 1, r, c) || win(board, r - 1, c, target, depth + 1, r, c) ||
                win(board, r, c - 1, target, depth + 1, r, c) || win(board, r - 1, c + 1, target, depth + 1, r, c) ||
                win(board, r + 1, c - 1, target, depth + 1, r, c)) // Check all adjacent
                    return true;
            } else {
               int next_r = r - previousRow;
               int next_c = c - previousCollum;
               //std::cout << previousRow << "," << previousCollum << " " << r << "," << c << " " << r + next_r << "," << c + next_c << " " << depth << std::endl;
               if (win(board, r + next_r, c + next_c, target, depth + 1, r, c)) // Check the next one in a row of this
                return true;
            }
        }
    }
    return false;
}

/** \brief Returns if there is three in a row on the board
 *
 * \param board The board to check
 * \param target What are you looking for?
 * \return bool Does the board have three in a row?
 *
 */

bool check_win(int board[][3], int target) {
    for (int r = 0; r != 3; r++)
        for (int c = 0; c != 3; c++) {
            if (win(board, r,c, target)) // Checks all cells in the table
                return true;
        }
        return false;

}

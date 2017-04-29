//---------------------------------------------------
// Main program to play Connect4 game
// Author: Christopher Snead
//---------------------------------------------------

#include <iostream>
#include <cstdlib>
#include "connect4.h"
using namespace std;

int main()
{

   // Play game
   srand(time(NULL));
   bool valid;

   Connect4 board;
   board.PrintBoard();

   while (!board.CheckWin('X') && !board.CheckWin('O'))
   {
      cout << "Which column would you like to choose?" << endl;
      int col = 0;
      cin >> col;
      valid = board.MakeMove(col, 'X');

      // Error checking
      while (!valid)
      {
         cout << "Invalid input. Which column would you like to choose?" << endl;
         cin >> col;
         valid = board.MakeMove(col, 'X');
      }

      board.PrintBoard();

      col = rand() % 7;
      valid = board.MakeMove(col, 'O');

      while (!valid)
      {
         col = rand() % 7;
         valid = board.MakeMove(col, 'O');
      }

      board.PrintBoard();

      // Congratulate winner
      if (board.CheckWin('X'))
      {
         cout << "Congraluations, you won!" << endl;
         return 0;
      }
      else if (board.CheckWin('O'))
      {
         cout << "I'm sorry, the computer won." << endl;
         return 0;
      }
   }

   return 0;
}

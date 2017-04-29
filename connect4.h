//---------------------------------------------------
// Purpose:     Header file for the Connect4 class
// Author:      John Gauch
//---------------------------------------------------

#include <iostream>
using namespace std;

#ifndef CONNECT4
#define CONNECT4

// Global constants
const int WIN = 4;
const int ROWS = 6;
const int COLS = 7;

// Class definition
class Connect4
{
   public:
      // Constructor and destructor
      Connect4();
      ~Connect4();

      // Public methods
      void ClearBoard();
      bool MakeMove(int col, char player);
      bool CheckWin(char player);
      void PrintBoard();

   private:
     // Private variables
     char board[ROWS][COLS];
     int count[COLS];
};

#endif

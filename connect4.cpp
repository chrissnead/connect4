//---------------------------------------------------
// Purpose:     Implementation of the Connect4 class
// Author:      John Gauch
//---------------------------------------------------

#include "connect4.h"

//---------------------------------------------------
// Constructor function
//---------------------------------------------------
Connect4::Connect4()
{
   ClearBoard();
}

//---------------------------------------------------
// Destructor function
//---------------------------------------------------
Connect4::~Connect4()
{
   // Intentionally empty
}

//---------------------------------------------------
// Clear the Connect4 board
//---------------------------------------------------
void Connect4::ClearBoard()
{
   // Initialize Connect4 board
   for (int c = 0; c < COLS; c++)
   for (int r = 0; r < ROWS; r++)
      board[r][c] = ' ';

   // Initialize column counters
   for (int c = 0; c < COLS; c++)
      count[c] = 0;
}

//---------------------------------------------------
// Add player's piece to specified column in board
//---------------------------------------------------
bool Connect4::MakeMove(int col, char player)
{
   // Error checking
   if ((col < 0) || (col >= COLS) || (count[col] >= ROWS))
      return false;

   // Make move
   int row = count[col];
   board[row][col] = player;
   count[col]++;
   return true;
}

//---------------------------------------------------
// Check to see if player has won the game
//---------------------------------------------------
bool Connect4::CheckWin(char player)
{
   // Loop over all starting positions
   for (int c = 0; c < COLS; c++)
   for (int r = 0; r < ROWS; r++)
   if (board[r][c] == player)
   {
      // Check row
      int count = 0;
      for (int d = 0; d < WIN; d++)
         if ((r+d < ROWS) &&
            (board[r+d][c] == player)) count++;
      if (count == WIN) return true;

      // Check column
      count = 0;
      for (int d = 0; d < WIN; d++)
         if ((c+d < COLS) &&
            (board[r][c+d] == player)) count++;
      if (count == WIN) return true;

      // Check first diagonal
      count = 0;
      for (int d = 0; d < WIN; d++)
         if ((r+d < ROWS) && (c+d < COLS) &&
            (board[r+d][c+d] == player)) count++;
      if (count == WIN) return true;

      // Check second diagonal
      count = 0;
      for (int d = 0; d < WIN; d++)
         if ((r-d >= 0) && (c+d < COLS) &&
            (board[r-d][c+d] == player)) count++;
      if (count == WIN) return true;
   }
   return false;
}

//---------------------------------------------------
// Print the Connect4 board
//---------------------------------------------------
void Connect4::PrintBoard()
{
   // Print the Connect4 board
   for (int r = ROWS-1; r >= 0; r--)
   {
      // Draw dashed line
      cout << "+";
      for (int c = 0; c < COLS; c++)
         cout << "---+";
      cout << "\n";

      // Draw board contents
      cout << "| ";
      for (int c = 0; c < COLS; c++)
         cout << board[r][c] << " | ";
      cout << "\n";
   }

   // Draw dashed line
   cout << "+";
   for (int c = 0; c < COLS; c++)
      cout << "---+";
   cout << "\n";

   // Draw column numbers
   cout << "  ";
   for (int c = 0; c < COLS; c++)
      cout << c << "   ";
   cout << "\n\n";
}

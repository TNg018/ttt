#include <iostream>
#include <cstdlib>

using namespace std;

const int BOARD_SIZE = 3;

void playGame(string board[BOARD_SIZE][BOARD_SIZE]);
void printBoard(string board[BOARD_SIZE][BOARD_SIZE]);
int getMove(string board[BOARD_SIZE][BOARD_SIZE], string turn);
void updateBoard(string board[BOARD_SIZE][BOARD_SIZE], int position, string turn);
bool gameOver(string board[BOARD_SIZE][BOARD_SIZE]);

int main()
{
  string board[BOARD_SIZE][BOARD_SIZE] = {{"0", "1", "2"},
                                          {"3", "4", "5"},
                                          {"6", "7", "8"}};
  playGame(board);
  return 0;
}

/*                                                                                                                                                                
 * Runs the game in a loop that continues until the game is over.                                                                                                 
 * Input: Game board.                                                                                                                                             
 */
void playGame(string board[BOARD_SIZE][BOARD_SIZE])
{
  string turn = "X";
  while(not gameOver(board))
    {
      printBoard(board);
      int position = getMove(board, turn);
      updateBoard(board, position, turn);

      // Below, we switch whose turn it is.                                                                                                                       
      if (turn == "X"){
        turn = "O";
      }
      else {
        turn = "X";
      }
    }

  printBoard(board);
  cout << "The game is over!" << endl;
}
/*                                                                                                                                                                
 * Prints tic tac toe board.                                                                                                                                      
 * Should print two spaces before/after each number.                                                                                                              
 * Input: 2d array representing board to print.                                                                                                                   
 */
void printBoard(string board[BOARD_SIZE][BOARD_SIZE])
{
  for (int row  = 0; row < BOARD_SIZE; row++) {
    for (int col = 0; col < BOARD_SIZE; col++) {
      cout << board[row][col] << "  ";
    }
  cout << endl;
 }
}
/*                                                                                                                                                                
 * Prompts the user for a move (int 0-9), checks if that is a valid move, and returns the move.                                                                   
 *                                                                                                                                                                
 * A move is invalid if: (1) it is less than 0 or greater than or equal to 9,                                                                                     
 * or (2) if that position on the board is already taken.                                                                                                         
 *                                                                                                                                                                
 * Function assumes that user does indeed provide an integer.                                                                                                     
 *                                                                                                                                                                
 * Input: Game board, and string ("X" or "O") naming whose turn it is.                                                                                            
 * Output: Integer move (0-9) given by user.                                                                                                                      
 */
int getMove(string board[BOARD_SIZE][BOARD_SIZE], string turn)
{
  int position;
  cout << turn << "'s turn. Please enter a free position on the board: " << endl;
  cin >> position;
  do {
   int row = position / 3;
   int col = position % 3;
   if ((position < 0) or (position >= 9)) {
      cout << "Given position is out of range. Please try again." << endl;
      cin >> position;
   }
   else if ((board[row][col] == "X") or (board[row][col] == "O")) {
      cout << "Position already taken. Please try again." << endl;
      cin >> position;
   }
   else {
      return position;
   }
  } while (true);
}
/*                                                                                                                                                                
 * Updates board with an X or O (depending on turn) in given position.                                                                                            
 * Inputs: Game board, position as integer, string turn (X or O).                                                                                                 
 */
void updateBoard(string board[BOARD_SIZE][BOARD_SIZE], int position, string turn)
{
 for (int row = 0; row < BOARD_SIZE; row++) {
  for (int col = 0; col < BOARD_SIZE; col++) {
    if ((row == (position / 3)) and (col == (position % 3))) {
       board[row][col] = turn;
   }
  }
 }
}
//why does board[0][position] work?                                                                                                                               
  /*                                                                                                                                                              
 * Checks whether game is over,                                                                                                                                   
 *  i.e., whether someone has won or the game is a draw.                                                                                                          
 * Input: Game board.                                                                                                                                             
 * Output: Boolean indicating whether game is over.                                                                                                               
 */
bool gameOver(string board[BOARD_SIZE][BOARD_SIZE])
{
 bool endGame = false;
 for (int row = 0; row < BOARD_SIZE; row++) {
  if ((board[row][0] == board[row][1]) and (board[row][1] == board[row][2])) {
     cout << board[row][0] << " is the winner! Row win!" << endl;
     return true;
  }
 }
 for (int col = 0; col < BOARD_SIZE; col++) {
  if ((board[0][col] == board[1][col]) and (board[1][col] == board[2][col])) {
     cout << board[0][col] << " is the winner! Column win!" << endl;
     return true;
  }
 }
 if ((board[2][0] == board[1][1]) and (board[1][1] == board[0][2])) {
    cout << board[2][0] << " is the winner! Diagonal win!" << endl;
    return true;
 }
 else if ((board[0][0] == board[1][1]) and (board[1][1] == board[2][2])) {
    cout << board[0][0] << " is the winner! Diagonal win!" << endl;
    return true;
 }
 else if (
     ((board[0][0] == "X") or (board[0][0] == "O")) and
     ((board[0][1] == "X") or (board[0][1] == "O")) and
     ((board[0][2] == "X") or (board[0][2] == "O")) and
     ((board[1][0] == "X") or (board[1][0] == "O")) and
     ((board[1][1] == "X") or (board[1][1] == "O")) and
     ((board[1][2] == "X") or (board[1][2] == "O")) and
     ((board[2][0] == "X") or (board[2][0] == "O")) and
     ((board[2][1] == "X") or (board[2][1] == "O")) and
     ((board[2][2] == "X") or (board[2][2] == "O"))
    ) {
       cout << "All spaces full. Tie!" << endl;
       return true;
 }
 else {
   return false;
 }
 return endGame;
}


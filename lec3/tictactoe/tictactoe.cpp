// Specifications:
    // A: Initialize two-dimensional char array as game board
        // Initialize each with element with asterisk 
    //B: Should run as a loop 
        // Display contents of board array
        //Asks player 1 for row and column numbers to input X
        //Asks player 2 for row and column numbers to input O
        //Declares winner or tie
            //Victory condition: three symbols in a row, column, or diagnonal across the board.
            //Tie condition: All positions on board are filled up.

#include <iostream>
// #include <vector>
using namespace std;

const int DIM = 3;

// Function prototypes
void printBoard(char board[][DIM]);
void printFinalBoard(char board[][DIM]);
bool tieCheck(char board[][DIM]);
int getNum(int dim);
bool valPos(char board[][DIM], int row, int col);
bool checkMove(char board[][DIM], char symbol);
bool victoryCheck(char board[][DIM], char symbol, int row, int col);
void endResult(char board[][DIM], bool p1v, bool p2v);

int main()
{
    // Initialize variables
    int row, col = 0;
    char symbol = '*';
    bool p1v = false;
    bool p2v = false;
    bool tie = false;

    // Initialize board:
    char board[DIM][DIM]; // Two-dimensional char array
    for(int i = 0; i < DIM; i++)
    {
        for(int j = 0; j < DIM; j++)
        {
            board[i][j] = '*';
        } 
    }

    // Beginning message:
    cout << "\nWelcome to Tic-Tac-Toe! The first to three symbols " 
         << "in a row, column or diagonal is the winner.\n"
         << "Each player must choose a row and column integer "
         << "between " << 0 << " and " << DIM - 1 << "\n"
         << "Player 1's symbol is X — they will move first.\n"
         << "Player 2's symbol is O — they will move second.\n";

    // While no victory or tie:
    while(true)
    {
        printBoard(board);

        // Get Player 1's Move:
            // Validate if symbol already in position
        cout << "\nPlayer 1's Move:\n";
        while(true)
        {
            cout << "Which row would you like to mark?\n";
            row = getNum(DIM);
            cout << "\nWhich column would you like to mark?\n";
            col = getNum(DIM);
            
            if (valPos(board, row, col))  // If position is valid
            {
                break; 
            }
        }
    
        // Input Player 1 move into board and check victory condition
        symbol = 'X';
        board[row][col] = symbol;
        p1v = checkMove(board, symbol);
        tie = tieCheck(board);
        if (p1v == true || tie == true) {break;}

        printBoard(board);

        // Get Player 2's Move:
            // Validate if symbol already in position
        cout << "\nPlayer 2's Move:\n";
        while(true)
        {
            cout << "Which row would you like to mark?\n";
            row = getNum(DIM);
            cout << "\nWhich column would you like to mark?\n";
            col = getNum(DIM);
            
            if (valPos(board, row, col))  // If position is valid
            {
                break; 
            }
        }

        // Input Player 2 move into board and check victory condition
        symbol = 'O';
        board[row][col] = symbol;
        p2v = checkMove(board, symbol);
        tie = tieCheck(board);
        if (p2v == true || tie == true) {break;}
    }

    endResult(board, p1v, p2v);

    return 0;
}

void printBoard(char board[][DIM])
{
    // Print current board state
    cout << "\nCurrent board state: \n";
    for(int i = 0; i < DIM; i++)
    {
        for(int j = 0; j < DIM; j++)
        {
            cout << board[i][j];
        } 
        cout << "\n"; // new row separator
    }
}

void printFinalBoard(char board[][DIM])
{
    // Print current board state
    cout << "\nFinal board state: \n";
    for(int i = 0; i < DIM; i++)
    {
        for(int j = 0; j < DIM; j++)
        {
            cout << board[i][j];
        } 
        cout << "\n"; // new row separator
    }
}

bool tieCheck(char board[][DIM])
{
    for(int i = 0; i < DIM; i++)
    {
        for(int j = 0; j < DIM; j++)
        {
            if (board[i][j] == '*') {return false;};
        } 
    }
    return true; // Game is tied!
}

int getNum(int dim)
{
   int num;
   while(true)
   {
        // Row input
        //cout << "Which row would you like to mark?\n";
        cin >> num;

        // Ensure input is an integer.
        if (cin.fail()) // Detect non-numerical input
        {
            cin.clear(); // Reset error flag back to normal
            cin.ignore(99999, '\n'); // Clear buffer of bad input
            cout << "Please enter a valid number. \n";
            continue;
        }

        // Ensure integer input is in valid range.
        if (num < 0 || num >= dim) 
        {
            cout << "Input outside of board range, please input value between "
            << "0 and " << dim - 1 << "\n";
            continue;
        }

        return num;
    }
}

bool valPos(char board[][DIM], int row, int col)
{
    if (board[row][col] == '*'){return true;}
    else
    {
        cout << "Position already marked, please choose free position.\n";
        return false;
    }
}

bool checkMove(char board[][DIM], char symbol)
{
    bool victory = false;

    for(int i = 0; i < DIM; i++)
    {
        for(int j = 0; j < DIM; j++)
        {
            if (board[i][j] == symbol)
            {
                if (victoryCheck(board, symbol, i, j) == true) {victory = true;}
                //victory = victoryCheck(board, symbol, i, j);
            }
        } 
    }
    return victory;
}

bool victoryCheck(char board[][DIM], char symbol, int row, int col)
{
    int r = row;
    int c = col;
    int vic = 0; // If three symbols found in a row, victory!

    // Check for column win condition
    for (int i = 0; i < DIM; i++)
    {
        if (board[i][c] == symbol) 
        {
            vic++;
            if (vic == 3) {return true;} // Victory!
        }
        // Ensures symbols are directly adjacent (more relevant for larger boards)
        else vic = 0; 
    }
    vic = 0; // Reset victory flag for next dimension assessment.

    // Check for row win condition
    for (int i = 0; i < DIM; i++)
    {
        if (board[r][i] == symbol) 
        {
            vic++;
            if (vic == 3) {return true;} // Victory!
        }
        // Ensures symbols are directly adjacent (more relevant for larger boards)
        else vic = 0;
    }
    vic = 0; // Reset victory flag for next dimension assessment.

    // **Diagonal checks**
    // Start at top left position diagonally from symbol, exit once at edge
    while (r > 0 && c > 0)
    {
        r -= 1;
        c -= 1;
    }

    // Check for top left to bottom right diagonal win condition
    for (; r < DIM && c < DIM; r++, c++)
    {
        if (board[r][c] == symbol) 
        {
            vic++;
            if (vic == 3) {return true;} // Victory!
        }
        // Ensures symbols are directly adjacent (more relevant for larger boards)
        else vic = 0;
    }
    vic = 0; // Reset victory flag for next dimension assessment.
   
    // Reset row and column positions
    r = row;
    c = col;

    // Start at top right position diagonally from symbol, exit once at edge
    while (r > 0 && c < DIM - 1)
    {
        r -= 1;
        c += 1;
    }

    // Check for top right to bottom left diagonal win condition
    for (; r < DIM && c >= 0; r++, c--)
    {
        if (board[r][c] == symbol) 
        {
            vic++;
            if (vic == 3) {return true;} // Victory!
        }
        // Ensures symbols are directly adjacent (more relevant for larger boards)
        else vic = 0;
    }

    return false; // No victory identified.
}

void endResult(char board[][DIM], bool p1v, bool p2v)
{
    if (p1v == true) {cout << "\nPlayer 1 is the winner!\n";}
    else if (p2v == true) {cout << "\nPlayer 2 is the winner!\n";}
    else {cout << "\nThe game is a draw!\n";}
    
    printFinalBoard(board);
}
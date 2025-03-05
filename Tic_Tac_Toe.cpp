#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

int main(){
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    // 2 constants for the 2 players
    const char playerX = 'X';
    const char playerO = 'O';
    // create a 3rd variable to keep track of the current player 
    char currentPlayer = playerX;

    // default values for rows and cols
    int r = -1; // meaning the player hasnt decided yet
    int c = -1; // same here
    char winner = ' ';

    for (int i = 0; i < 9; i++)
    {
        //print the game board
        cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
        cout << "___|___|___" << endl;
        cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
        cout << "___|___|___" << endl;
        cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
        cout << "   |   |   " << endl;

        if (winner != ' ')
        {
            break;
        }

        // Get the player input
        cout << "Current player is " << currentPlayer << endl;
        while (true)
        {
            cout << "Enter 'r', 'c' from (0-2) for rows and columns: ";
            cin >> r >> c;
            if (r < 0 || r > 2 || c < 0 || c > 2)
            {
                cout << "Invalid Input, input must be (0-2)." << endl;
            }
            else if (board[r][c] != ' ')
            {
                cout << "Tile is full, try again." << endl;
            }
            else
            {
                break;
            }
            // reset the values
            r = -1;
            c = -1;
            
            cin.clear(); // clear the error flags () If a user inputs a value that doesn't match the expected data type (e.g., entering a letter when an integer is expected), cin will enter a fail state. cin.clear()
            // cin.ignore has been used to remove (or ignore) characters in the input buffer
            cin.ignore(10000, '\n');
            // (Skips to the next new line \n up to 10000 char) already in input stream

        }

        // update the board
        board[r][c] = currentPlayer;
        // switch the players after each turn 
        currentPlayer = (currentPlayer == playerX) ? playerO : playerX;

        // Check the winners

        // rows - horizantal
        // r below is no the same r we have previosuly used
        for (int row = 0; row < 3; row++)
        {
            // check if the first tile is not empty and the 3 tiles are the same
            if (board[row][0] != ' ' && board [row][0] == board[row][1] && board[row][1] == board[row][2])
            {
                winner = board[row][0];
                break;
            }

            
            // columns - vertical
            for (int cols = 0; cols < 3; cols++)
            {
                // check if the first tile is not empty and the 3 tiles are the same
                if (board[0][cols] != ' ' && board[0][cols] == board[1][cols] && board[1][cols] == board[2][cols])
                {
                    winner = board[0][cols];
                    break;
                }
            }
            
            // diagonals
            if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
            {
                winner = board[0][0];
            }
            else if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
            {
                winner = board[0][2];
            }
        }
    }

    // print the winner
    if (winner != ' ')
    {
        cout << "Player" << winner << " is the winner!" << endl;
    }
    else 
    {
        cout << "Tie!";
    }
}



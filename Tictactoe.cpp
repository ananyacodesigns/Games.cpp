#include <iostream>
#include <vector>

using namespace std;

// Function to draw the Tic Tac Toe board
void drawBoard(const vector<char>& board) {
    cout << " 1 | 2 | 3 " << endl;
    cout << "-----------" << endl;
    cout << " 4 | 5 | 6 " << endl;
    cout << "-----------" << endl;
    cout << " 7 | 8 | 9 " << endl << endl;

    cout << "Current Board:" << endl;
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << "-----------" << endl;
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl << endl;
}

// Function to check if someone wins
bool checkWin(const vector<char>& board, char player) {
    // Check rows, columns, and diagonals
    return (
        (board[0] == player && board[1] == player && board[2] == player) ||
        (board[3] == player && board[4] == player && board[5] == player) ||
        (board[6] == player && board[7] == player && board[8] == player) ||
        (board[0] == player && board[3] == player && board[6] == player) ||
        (board[1] == player && board[4] == player && board[7] == player) ||
        (board[2] == player && board[5] == player && board[8] == player) ||
        (board[0] == player && board[4] == player && board[8] == player) ||
        (board[2] == player && board[4] == player && board[6] == player)
    );
}

int main() {
    vector<char> board = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int currentPlayer = 1; // Player 1 starts

    cout << "Welcome to Tic Tac Toe!" << endl << endl;
    drawBoard(board);

    int move;
    while (true) {
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        if (move < 1 || move > 9) {
            cout << "Invalid move! Please enter a number between 1 and 9." << endl;
            continue;
        }

        if (board[move - 1] == 'X' || board[move - 1] == 'O') {
            cout << "That position is already taken! Please choose another." << endl;
            continue;
        }

        char marker = (currentPlayer == 1) ? 'X' : 'O';
        board[move - 1] = marker;
        drawBoard(board);

        // Check if someone wins
        if (checkWin(board, marker)) {
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        // Check for a draw
        bool isFull = true;
        for (char cell : board) {
            if (cell != 'X' && cell != 'O') {
                isFull = false;
                break;
            }
        }

        if (isFull) {
            cout << "It's a draw!" << endl;
            break;
        }

        // Switch players
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }

    return 0;
}

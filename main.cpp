#include <iostream>
using namespace std;

char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
char currentPlayer = 'X';

void drawBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        if (i < 2) cout << "\n---|---|---\n";
    }
    cout << "\n\n";
}

bool placeMark(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (slot < 1 || slot > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "Invalid move! Try again.\n";
        return false;
    }

    board[row][col] = currentPlayer;
    return true;
}

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        // Rows & Columns
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i]))
            return true;
    }

    // Diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
        return true;

    return false;
}

bool isBoardFull() {
    for (int i = 1; i <= 9; ++i) {
        int r = (i - 1) / 3;
        int c = (i - 1) % 3;
        if (board[r][c] != 'X' && board[r][c] != 'O')
            return false;
    }
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    int move;
    cout << "Welcome to Tic Tac Toe!\n";
    drawBoard();

    while (true) {
        cout << "Player with " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        if (placeMark(move)) {
            drawBoard();

            if (checkWin()) {
                cout << "Player " << currentPlayer << " wins!\n";
                break;
            }

            if (isBoardFull()) {
                cout << "It's a draw!\n";
                break;
            }

            switchPlayer();
        }
    }

    return 0;
}

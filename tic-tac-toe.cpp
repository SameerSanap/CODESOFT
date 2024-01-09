#include <bits/stdc++.h>
using namespace std;

// Display
void displayBoard(const vector<vector<char>> &board)
{
    cout << "-------------" << endl;
    for (int i = 0; i < 3; ++i)
    {
        cout << "| ";
        for (int j = 0; j < 3; ++j)
        {
            cout << board[i][j] << " | ";
        }
        cout << endl<< "-------------" << endl;
    }
}

// Check Winner
bool checkWinner(const vector<vector<char>> &board, char player)
{
    for (int i = 0; i < 3; ++i)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return true;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
        {
            return true;
        }
    }
    // Diagonal Check
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    {
        return true;
    }
    return false;
}

// Check is a draw
bool checkDraw(const vector<vector<char>> &board)
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i][j] == '-')
            {
                return false;
            }
        }
    }
    return true;
}

void initializeBoard(vector<vector<char>> &board)
{
    for (int i = 0; i < 3; ++i)
    {
        vector<char> row(3, '-');
        board.push_back(row);
    }
}

// index to board
pair<int, int> convertInput(int move)
{
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    return {row, col};
}

char switchPlayer(char currentPlayer)
{
    if (currentPlayer == 'X')
    {
        return 'O';
    }
    return 'X';
}

int main()
{
    vector<vector<char>> board;
    initializeBoard(board);

    char currentPlayer = 'X';
    bool gameWon = false, gameDraw = false;

    while (!gameWon && !gameDraw)
    {
        displayBoard(board);

        int move;
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        if (move <= 0 || move >= 10)
        {
            cout << "Invalid move! Enter a number from 1 to 9." << endl;
            continue;
        }

        pair<int, int> coordinates = convertInput(move);
        int row = coordinates.first;
        int col = coordinates.second;

        if (board[row][col] != '-')
        {
            cout << "Invalid move! Cell already occupied. Try again." << endl;
            continue;
        }

        board[row][col] = currentPlayer;

        gameWon = checkWinner(board, currentPlayer);
        gameDraw = checkDraw(board);

        currentPlayer = switchPlayer(currentPlayer);
    }

    displayBoard(board);
    currentPlayer = switchPlayer(currentPlayer);
    if (gameWon)
    {
        cout << "Player " << currentPlayer << " wins!" << endl;
    }
    else
    {
        cout << "It's a draw!" << endl;
    }

    return 0;
}

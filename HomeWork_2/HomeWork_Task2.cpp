#include <iostream>
using namespace std;

size_t boardSize;

void initialiseBoard(short **&chessBoard)
{
    cout << "Enter board size: ";
    cin >> boardSize;

    chessBoard = new short *[boardSize];
    for (int i = 0; i < boardSize; i++)
    {
        chessBoard[i] = new short[boardSize];
    }
    // initializing chess board
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            chessBoard[i][j] = -1;
        }
    }
}

bool dfs(short **chessBoard, int x, int y, int move_count)
{
    if (x < 0 || x >= boardSize || y < 0 || y >= boardSize)
    {
        return false;
    }
    if (chessBoard[x][y] != -1)
    {
        return false;
    }

    chessBoard[x][y] = move_count;
    if (move_count == boardSize * boardSize - 1)
    {
        return true;
    }

    int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

    for (int i = 0; i < 8; i++)
    {
        int new_x = x + dx[i];
        int new_y = y + dy[i];

        if (dfs(chessBoard, new_x, new_y, move_count + 1))
        {
            return true;
        }
    }

    chessBoard[x][y] = -1;
    return false;
}

void deleteBoard(short **board)
{
    for (int i = 0; i < boardSize; i++)
    {
        delete[] board[i];
    }

    delete[] board;
}

void printPath(short **chessBoard, bool canVisitAll)
{
    if (canVisitAll)
    {
        cout << "There is solution!" << endl;

        for (int i = 0; i < boardSize; i++)
        {
            for (int j = 0; j < boardSize; j++)
            {
                cout << chessBoard[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "There is no solution!" << endl;
    }
}

int main()
{
    short **chessBoard;
    initialiseBoard(chessBoard);
    bool canVisitAll = dfs(chessBoard, 0, 0, 0);

    printPath(chessBoard, canVisitAll);

    deleteBoard(chessBoard);
}

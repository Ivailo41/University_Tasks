#include <iostream>
using namespace std;

const int MAX_BOARD_SIZE = 9;
const int MIN_BOARD_SIZE = 3;

char **createBoard(size_t boardSize)
{
    char **board = new char *[boardSize];

    for (size_t i = 0; i < boardSize; i++)
    {
        board[i] = new char[boardSize];

        for (size_t j = 0; j < boardSize; j++)
        {
            board[i][j] = ' ';
        }
    }

    return board;
}

void validateInput(size_t &inputSize)
{
    do
    {
        cout << "Please enter board size between " << MIN_BOARD_SIZE << " and " << MAX_BOARD_SIZE << endl;
        cin >> inputSize;
    } while (inputSize < MIN_BOARD_SIZE || inputSize > MAX_BOARD_SIZE);
}

void print(char **board, size_t boardSize)
{
    for (size_t i = 0; i < boardSize; i++)
    {
        for (size_t j = 0; j < boardSize; j++)
        {
            cout << '[' << board[i][j] << ']';
        }
        cout << endl;
    }
    cout << endl;
}

bool isValidInput(unsigned short x, unsigned short y, size_t boardSize)
{
    return (x >= 0 && x < boardSize) && (y >= 0 && y < boardSize);
}
bool isCellFree(char **board, unsigned short x, unsigned short y)
{
    return board[x][y] == ' ';
}
void inputCoordinates(char **board, size_t boardSize, unsigned short &x, unsigned short &y)
{
    do
    {
        cout << "Enter valid cell coordinates: ";
        cin >> x >> y;
    } while (!isValidInput(x, y, boardSize) || !isCellFree(board, x, y));
}

bool checkIfRowColContainsSameMarks(char **board, size_t boardSize, char mark, unsigned short markRow, unsigned short markCol, bool checkRow)
{
    unsigned short row = checkRow ? markRow : 0;
    unsigned short col = checkRow ? 0 : markCol;

    for (; row < boardSize && col < boardSize; row += !checkRow, col += checkRow)
    {
        if (board[row][col] != mark)
        {
            return false;
        }
    }
    return true;
}
bool isRowOrColFull(char **board, size_t boardSize, char mark, unsigned short markRow, unsigned short markCol)
{
    return checkIfRowColContainsSameMarks(board, boardSize, mark, markRow, markCol, true) ||
           checkIfRowColContainsSameMarks(board, boardSize, mark, markRow, markCol, false);
}

bool isInFirstDiagonal(unsigned short markRow, unsigned short markCol)
{
    return markRow == markCol;
}
bool isInSecondDiagonal(unsigned short markRow, unsigned short markCol)
{
    return markRow + markCol == MAX_BOARD_SIZE - 1;
}

bool checkIfDiagonalContainsSameMarks(char **board, size_t boardSize, char mark, unsigned short markRow, unsigned short markCol, bool checkPrincipal)
{
    int row = checkPrincipal ? 0 : boardSize - 1;
    int col = 0;
    int updateRow = checkPrincipal ? 1 : -1;
    int updateCol = 1;

    for (; row >= 0 && row < boardSize && col >= 0 && col < boardSize; row += updateRow, col += updateCol)
    {
        if (board[row][col] != mark)
        {
            return false;
        }
    }
    return true;
}
bool diagonalsFilledWithMark(char **board, size_t boardSize, char mark, unsigned short markRow, unsigned short markCol)
{
    return (isInFirstDiagonal(markRow, markCol) && checkIfDiagonalContainsSameMarks(board, boardSize, mark, markRow, markCol, true)) ||
           (isInSecondDiagonal(markRow, markCol) && checkIfDiagonalContainsSameMarks(board, boardSize, mark, markRow, markCol, false));
}

bool isWinner(char **board, size_t boardSize, char mark, unsigned short markRow, unsigned short markCol)
{
    return isRowOrColFull(board, boardSize, mark, markRow, markCol) || diagonalsFilledWithMark(board, boardSize, mark, markRow, markCol);
}

void deleteDynamicMatrix(char **matrix, size_t matrixSize)
{
    for (size_t i = 0; i < matrixSize; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main()
{
    size_t boardSize;
    validateInput(boardSize);

    char **board = createBoard(boardSize);
    print(board, boardSize);

    bool isFirstPlayersTurn = true;
    unsigned short x, y;

    do
    {
        cout << "It's " << (isFirstPlayersTurn ? "first" : "second") << " player's turn!" << endl;
        inputCoordinates(board, boardSize, x, y);

        board[x][y] = isFirstPlayersTurn ? 'x' : 'o';
        print(board, boardSize);

        isFirstPlayersTurn = !isFirstPlayersTurn;
    } while (!isWinner(board, boardSize, board[x][y], x, y));

    deleteDynamicMatrix(board, boardSize);
    cout << "You won!";
}
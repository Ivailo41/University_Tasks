#include <iostream>

using namespace std;

const int N = 5; // Size of the chess board

int dx[] = {2, 2, 1, -1, -2, -2, -1, 1}; // Possible x-coordinate moves for a knight
int dy[] = {1, -1, -2, -2, -1, 1, 2, 2}; // Possible y-coordinate moves for a knight

// Function to check if a given square is inside the chess board
bool isInside(int x, int y)
{
    return x >= 0 && x < N && y >= 0 && y < N;
}

// Function to check if a knight can reach every square on the chess board
bool dfs(int visited[][N], int path[][N], int x, int y, int move)
{
    // Mark the current square as visited and store the move number in path array
    visited[x][y] = 1;
    path[x][y] = move;

    // Check if all squares on the chess board have been visited
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j])
            {
                bool found = false;
                // Try moving to all 8 possible squares
                for (int k = 0; k < 8; k++)
                {
                    int x2 = x + dx[k];
                    int y2 = y + dy[k];
                    if (isInside(x2, y2) && !visited[x2][y2])
                    {
                        found = true;
                        if (dfs(visited, path, x2, y2, move + 1))
                        {
                            return true;
                        }
                    }
                }
                if (!found)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    // initializing chess board
    int visited[N][N], path[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            visited[i][j] = 0;
            path[i][j] = -1;
        }
    }
    // SEPARATE FUNCTION

    int starting_x, starting_y;
    cout << "Enter starting x coordinate for the knight: ";
    cin >> starting_x;
    cout << "Enter starting y coordinate for the knight: ";
    cin >> starting_y;
    // SEPARATE FUNCTION

    bool can_visit_all = dfs(visited, path, starting_x, starting_y, 0);

    if (can_visit_all)
    {
        cout << "The knight can visit every square on the chess board without repeating any squares." << endl;
        cout << "Path taken by the knight:" << endl;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << path[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "The knight can not visit every square on the chess board without repeating any squares." << endl;
    }
    // Separate function

    return 0;
}

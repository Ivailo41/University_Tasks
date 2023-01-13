#include <iostream>
#include <cmath>
using namespace std;

const unsigned short BACTERY_STATS_COUNT = 3;
const double MAX_INFECTION_VALUE_DIFF = 1;

typedef unsigned char bactery[BACTERY_STATS_COUNT];

void copyBactery(const bactery origBactery, bactery copyBactery)
{
    for (size_t i = 0; i < BACTERY_STATS_COUNT; i++)
    {
        copyBactery[i] = origBactery[i];
    }
}

void copyColony(const bactery *const *const colony, bactery **copy, size_t height, size_t width)
{
    for (size_t i = 0; i < height; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            copyBactery(colony[i][j], copy[i][j]);
        }
    }
}

unsigned short charToNum(char symbol)
{
    return (unsigned short)symbol;
}

unsigned short numToChar(unsigned short num)
{
    return (unsigned char)num;
}

void inputBacteryStats(bactery &bactery)
{
    unsigned short input;
    for (size_t i = 0; i < BACTERY_STATS_COUNT; i++)
    {
        cin >> input;
        bactery[i] = (unsigned char)input;
    }
}

double getBacteryAvarageStat(const bactery bactery)
{
    double avarage = 0;
    for (size_t i = 0; i < BACTERY_STATS_COUNT; i++)
    {
        avarage += charToNum(bactery[i]);
    }
    return avarage / BACTERY_STATS_COUNT;
}

void infectBactery(bactery &bactery)
{
    for (size_t i = 0; i < BACTERY_STATS_COUNT; i++)
    {
        bactery[i] = numToChar(0);
    }
}

bool isInfected(const bactery bactery)
{
    for (size_t i = 0; i < BACTERY_STATS_COUNT; i++)
    {
        if (bactery[i] != numToChar(0))
            return false;
    }
    return true;
}

bool canBeInfected(const bactery infectedBactery, const bactery victim)
{
    if (isInfected(victim))
        return false;

    return abs(getBacteryAvarageStat(infectedBactery) - getBacteryAvarageStat(victim)) <= MAX_INFECTION_VALUE_DIFF;
}

bactery **initialiseColony(size_t height, size_t width)
{
    bactery **colony = new bactery *[height];

    for (size_t i = 0; i < height; i++)
    {
        colony[i] = new bactery[width];

        for (size_t j = 0; j < width; j++)
        {
            cout << "Bactery[" << i << "][" << j << "] Stats: ";
            inputBacteryStats(colony[i][j]);
        }
    }

    return colony;
}

void infectHelper(const bactery *const *colony, bactery **infectedColony, size_t height, size_t width, size_t row, size_t col)
{
    infectBactery(infectedColony[row][col]);
    //  CHECK ALL DIRECTIONS
    if (row + 1 < height && canBeInfected(colony[row][col], infectedColony[row + 1][col]))
    {
        infectHelper(colony, infectedColony, height, width, row + 1, col);
    }
    if (col + 1 < width && canBeInfected(colony[row][col], infectedColony[row][col + 1]))
    {
        infectHelper(colony, infectedColony, height, width, row, col + 1);
    }
    if (row - 1 < height && canBeInfected(colony[row][col], infectedColony[row - 1][col]))
    {
        infectHelper(colony, infectedColony, height, width, row - 1, col);
    }
    if (col - 1 < width && canBeInfected(colony[row][col], infectedColony[row][col - 1]))
    {
        infectHelper(colony, infectedColony, height, width, row, col - 1);
    }

    infectBactery(infectedColony[row][col]);
}

bactery **infect(const bactery *const *colony, size_t height, size_t width, size_t row, size_t col)
{
    bactery **infectedColony;

    infectedColony = new bactery *[height];

    for (size_t i = 0; i < height; i++)
    {
        infectedColony[i] = new bactery[width];
    }

    // copy original colony to infected colony
    copyColony(colony, infectedColony, height, width);

    infectHelper(colony, infectedColony, height, width, row, col);
    return infectedColony;
}

void printColony(const bactery *const *const colony, size_t rows, size_t cols)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            cout << "[" << getBacteryAvarageStat(colony[i][j]) << "] ";
        }
        cout << endl;
    }
}

void deleteMatrix(bactery **matrix, size_t rows)
{
    for (size_t i = 0; i < rows; i++)
    {
        delete[] * matrix[i];
    }

    delete[] matrix;
}

int main()
{
    size_t rows, cols;
    cin >> cols >> rows;

    bactery **colony = initialiseColony(rows, cols);

    bactery **newColony = infect(colony, rows, cols, 0, 0);

    printColony(newColony, rows, cols);

    deleteMatrix(colony, rows);
    deleteMatrix(newColony, rows);
}

// SHOULD MAKE ROW AND COL INPUT
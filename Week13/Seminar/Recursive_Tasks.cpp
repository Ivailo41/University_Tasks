#include <iostream>
using namespace std;

size_t strlen(char *string)
{
    size_t result = 0;
    while (string[result] != '\0')
    {
        result++;
    }
    return result;
}

printBitstring(bool *bitString, char *elements, size_t size)
{
    cout << '{';

    for (size_t i = 0; i < size; i++)
    {
        if (bitString[i])
        {
            cout << ' ' << elements[i] << ' ';
        }
    }
    cout << '}' << endl;
}

void makeCombinations(char *elements, size_t n, bool *bitString, size_t pos)
{
    if (pos == n)
    {
        printBitstring(bitString, elements, n);
        return;
    }

    bitString[pos] = 0;
    makeCombinations(elements, n, bitString, pos + 1);

    bitString[pos] = 1;
    makeCombinations(elements, n, bitString, pos + 1);
}

void printCombinations(char *elements, size_t n)
{
    bool *bitString = new bool[n];
    makeCombinations(elements, n, bitString, 0);
    delete[] bitString;
}

int main()
{
    char elements[] = {'a', 'c', 'f', 'g', 'r', '\0'};
    size_t size = strlen(elements);
    printCombinations(elements, size);
}
#include <iostream>
using namespace std;

char *strCopyWord(char *toString, char *fromString)
{
    if (toString == nullptr || fromString == nullptr)
        return fromString;

    while (*fromString != '\0' && *fromString != ' ')
    {
        *toString = *fromString;
        toString++;
        fromString++;
    }
    *toString = '\0';

    return fromString + 1;
}

bool strCompare(char *string, const char compString[15])
{
    while (*string != '\0' || *compString != '\0')
    {
        if (*string != *compString)
            return false;

        string++;
        compString++;
    }
    return true;
}

size_t countWords(const char *string)
{
    size_t result = 0;

    if (string == nullptr)
        return result;

    while (*string != '\0')
    {
        string++;

        if (*string == ' ')
            result++;
    }

    return result + 1;
}

size_t wordLen(const char *string)
{
    size_t result = 0;
    if (string == nullptr)
        return result;

    while (*string != '\0' && *string != ' ')
    {
        result++;
        string++;
    }

    return result;
}

char **splitStringToArray(char *string, size_t size)
{
    size_t textWordCount = countWords(string);

    char **text = new char *[size];

    for (size_t i = 0; i < size; i++)
    {
        size_t wordSize = wordLen(string);

        char *word = new char[wordSize];
        string = strCopyWord(word, string);

        text[i] = word;
    }

    return text;
}

void printText(char **text, size_t size, bool *bitString)
{
    for (size_t i = 0; i < size; i++)
    {
        if (bitString[i])
        {
            cout << "*" << ' ';
        }
        else
        {
            cout << text[i] << ' ';
        }
    }
    cout << endl;
}

void commandPrompt(char **text, size_t size)
{
    char command[20];

    bool *bitString = new bool[size];
    for (size_t i = 0; i < size; i++)
    {
        bitString[i] = 0;
    }

    size_t index;

    while (!strCompare(command, "quit"))
    {
        cout << "Enter command: ";
        cin >> command;

        if (strCompare(command, "censore"))
        {
            cin >> index;
            bitString[index] = 1;
        }

        if (strCompare(command, "uncensore"))
        {
            cin >> index;
            bitString[index] = 0;
        }

        printText(text, size, bitString);
    }

    delete[] bitString;
}

int main()
{
    char inputString[2048];
    cin.getline(inputString, 2048);

    size_t size = countWords(inputString);

    char **text = splitStringToArray(inputString, size);

    commandPrompt(text, size);
}
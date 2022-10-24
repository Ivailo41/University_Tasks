#include <iostream>
using namespace std;

void Task1(); // Takes years inputs based on integer and prints out how many of the years have 366 days
void Task2(); // Prints all prime numbers in given range
void Task7(); // Makes input x input table with ascending numbers in snake pattern

int main()
{
    Task7();
}

void Task1()
{
    int input, year;
    int result = 0;
    cin >> input;

    for(int i = 0; i < input; i++)
    {
        cin >> year;

        if(year%4 == 0)
        result++;
    }
    cout << result;

}

void Task2()
{
    int start, end;
    bool isPrime = true;
    
    cin >> start >> end;

    while(start <= 0 || end <= 0)
    {
        cout << "Invalid input" << endl;
        cin >> start >> end;
    }

    //0 and 1 are not prime
    if(start == 0 || start == 1)
    start = 2;

    while(start < end)
    {
        for (int i = 2; i <= start/2; ++i) 
        {
            if (start % i == 0)
            {
                isPrime = false;
            }
        }

        if(isPrime)
        cout << start << " ";

        isPrime = true;
        start++;
    }
}

void Task7()
{
    int input;
    cin >> input;

    for(int i = 1; i <= input; i++)
    {
        for(int j = 1; j <= input; j++)
        {
            if(i%2 != 0)
            cout << j+input*(i-1) << " ";
            else
            cout << input*i-j+1 << " ";
        }
        cout << endl;
    }
}
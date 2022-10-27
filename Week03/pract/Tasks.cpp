#include <iostream>
#include <cmath>
using namespace std;

//task container
void zad0()
{
    int n;
    int result = 1;
    cin >> n;

    for(size_t i = 1; i <= n; i++)
    {
        result *= i;
    }

    cout << result << endl;
}

void zad1()
{
    int input;
    cin >> input;

    for(size_t i = 1; i < input; i++)
    {
       cout << i*i + 3*i << endl;
    }
}

void zad2()
{
    int numCount, result, numInput;
    cin >> numCount;
    result = INT_MIN;

    for(size_t i = 0; i < numCount; i++)
    {
        cin >> numInput;

        if(numInput < 0 && numInput > result)
        result = numInput;
    }

    cout << result;
}

void zad3()
{
    int n, result, firstNum, secondNum;
    firstNum = 1;
    secondNum = 0;
    cin >> n;

    if(n == 1)
    cout << 0 << endl;
    else if(n == 2)
    cout << 1 << endl;
    else
    {
        for(size_t i = 3; i <= n; i++)
        {
            result = firstNum + secondNum;
            secondNum = firstNum;
            firstNum = result;
        }

        cout << result;
    }

}

void zad4()
{
    int num, result;

    while (true)
    {
        cin >> num;
        result += num;

        if(num == 0)
        break;
    }

    cout << "The sum of all numbers is: " << result << endl;
    
}

void zad5()
{
    int num, result;
    cin >> num;

    while(num > 0)
    {
        result += num%10;
        num /= 10;
    }

    cout << result;
}

void zad6()
{
    int num, power, result; //100 = (num^10)^10
    result = 1;
    cin >> num >> power;

    for (size_t i = 0; i < power; i++)
    {
        result *= num;
    }

    cout << result;
    

}

void zad7()
{
    int num;
    bool isPrime = true;

    cin >> num;

    for (size_t i = 2; i <= sqrt(num); i++)
    {
        if(num % i == 0)
        {
            isPrime = false;
            break;
        }
    }

    cout << boolalpha << isPrime;
    
}

void zad8()
{
    for (size_t i = 66; i <= 90; i++)
    {
        if(!(i == 69 || i == 73 || i == 79 || i == 85))
        cout << char(i);
    }
    
}

//end of task container

int main()
{
    zad8();
}
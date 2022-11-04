#include <iostream>
#include <cmath>
using namespace std;


void zad3()
{
    int input, max, min, indexOfMax, indexOfMin;
    int arr[100];

    cin >> input;

    max = INT_MIN;
    min = INT_MAX;
    
    for (size_t i = 0; i < input; i++)
    {
        cin >> arr[i];
        if (arr[i] < min)
        {
        min = arr[i];
        indexOfMin = i;
        }
        if (arr[i] > max)
        {
        max = arr[i];
        indexOfMax = i;
        }
    }

    cout << "The maximum is: " << arr[indexOfMax] << " ; The minimum is: " << arr[indexOfMin] << endl;;

    int tempElementHolder = arr[indexOfMax];
    arr[indexOfMax] = arr[indexOfMin];
    arr[indexOfMin] = tempElementHolder;

    for (size_t i = 0; i < input; i++)
    {
        cout << arr[i] << ":";
    }
        
}

void task5() //print n elements in the row 122333...
{
    int n, elementValue, itterations;
    itterations = 0;
    elementValue = 1;

    cin >> n;

    for (size_t i = 1; i <= n; i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            if(itterations == n)
            break;

            cout << elementValue;
            itterations++;
        }
        elementValue++;  
    }    
}

void task4() //calculate profit based on ticket price and discount
{
    int pplCount;
    double discont, ticketPrice, sum;

    cin >> pplCount >> ticketPrice;

    if(pplCount >= 5 && pplCount <= 10)
    discont = 0.05;
    else if(pplCount >= 11 && pplCount <= 20)
    discont = 0.1;
    else if(pplCount > 20)
    discont = 0.15;

    sum = pplCount * (ticketPrice - (ticketPrice * discont));
    cout << sum;

}

void task2() //find if a number divides a number and if the square of the divider divides other number
{
    int firstNum, secondNum;
    bool isDivider = false;
    cin >> firstNum >> secondNum;

    for (size_t i = 2; i <= firstNum/2; i++)
    {
        if(firstNum % i == 0 && secondNum % i*i == 0)
        {
            isDivider = true;
            break;
        }
    }
    cout << boolalpha << isDivider;
}

void task1()
{
    int firstNum, secondNum;
    cin >> firstNum >> secondNum;


}

void task0() // checks if inputed number contains 1
{
    int num;
    bool contains1 = false;
    cin >> num;

    while(num > 0)
    {
        if(num % 10 == 1)
        {
            contains1 = true;
            break;
        }
        num /= 10;
    }
    cout << boolalpha << contains1;
}

void zad4()
{
    int length, sum;
    bool startSum = false;
    cin >> length;

    int arr[100];

    for (size_t i = 0; i < length; i++)
    {
        cin >> arr[i];

        sum += arr[i] * startSum;

        if(arr[i] < 0 && !startSum)
        startSum = true;
    }

    cout << sum;
    
}

void zad5()
{
    int length;
    int arr[100];

    cin >> length;

    for (size_t i = 0; i < length; i++)
    {
        cin >> arr[i];
    }

    for (size_t i = length; i > 0; i--)
    {
       cout << arr[i-1]; 
    }
    
    
}

int main()
{
    zad5();
}
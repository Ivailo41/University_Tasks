#include <iostream>
using namespace std;

void Task0();
void Task1();
void Task2();
void Task3();
void Task4();
void Task5();
void Task6();
void Task7();

int main()
{
    Task1();
}

void Task0()
{
    cout << "Program for coffe" << endl;
}

void Task1()
{
    int number;

    if(!(number / 100) > 0)
    {
        cin >> number;

        cout << "first digit: " << number/100 << endl;
        cout << "second digit: " << number / 10 % 10 << endl;
        cout << "third digit: " << number%10 << endl;
    }
}

void Task2()
{
    int a,b;
    cin >> a >> b;
    a = a + b;
    b = a-b;
    a = a - b;
    cout << a << ":" << b;
}

void Task3()
{
    int a,b;
    cin >> a >> b;
    cout << boolalpha << !(a%b);
}

void Task4()
{
    int a,b;
    cin >> a >> b;
    int result = a*b;
    cout << result << endl << result%10 << endl << boolalpha << !(result%2);
}

void Task5()
{
    int a,b,c;
    cin >> a >> b >> c;
    cout << boolalpha << (a + b > c && a + c > b && b + c > a);
}

void Task6()
{
    int a,b,c;
    cin >> a >> b >> c;
    cout<<max(max(a,b),c) << endl;
    cout<<min(min(a,b),c);
}

void Task7()
{
    int x,a,b;
    cin >> x >> a >> b;
    cout << boolalpha << (x >= a && x <= b);
}
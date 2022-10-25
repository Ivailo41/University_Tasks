#include <iostream>

using namespace std;

void Zad1();
void Zad2();
void Zad3();
void Zad4();
void Zad5();
void Zad6();
void Zad7();

int main()
{
    Zad7();
}

void Zad0()
{
    double firstNum,secondNum;
    char operation;

    cin>> firstNum >> secondNum >> operation;

    switch(operation)
    {
        case '+': cout<<firstNum+secondNum<<endl;break;
        case '-': cout<<firstNum-secondNum<<endl;break;
        case '*': cout<<firstNum*secondNum<<endl;break;
        case '/': cout<<firstNum/secondNum<<endl;break;
    }
}

void Zad1()
{
    int year;
    cin>>year;

    switch(year%4)
    {
        case 0: cout<<"leap year";break;
        default: cout<<"not leap year";
    }
}

void Zad2()
{
    char simbol;
    cin >> simbol;

    if(64<simbol && simbol <91)
    {
        cout<<"The lower case character corresponding to " << simbol <<" is " << char(simbol + 32);
    }
    else if(96 < simbol && simbol < 123)
    {
        cout<<"The upper case character corresponding to " << simbol <<" is " << char(simbol - 32);
    }
    else
    {
        cout<<simbol<<" is not a letter";
    }
}

void Zad3()
{
    int monthNumber;
    cin >> monthNumber;

    switch(monthNumber)
    {
        case 1: cout << "It's winter";break;
        case 2: cout << "It's winter";break;
        case 3: cout << "It's spring";break;
        case 4: cout << "It's spring";break;
        case 5: cout << "It's spring";break;
        case 6: cout << "It's summer";break;
        case 7: cout << "It's summer";break;
        case 8: cout << "It's summer";break;
        case 9: cout << "It's authum";break;
        case 10: cout << "It's authum";break;
        case 11: cout << "It's authum";break;
        case 12: cout << "It's winter";break;
        default: cout << monthNumber << " is not a month number";
    }
}

void Zad4()
{
    int a,b;
    cin >> a >> b;

    if(a == 0 && b == 0)
    cout << "INF";

    else if((-b%a) != 0)
    cout << "NO";

    else
    cout << -b/a;
}

void Zad5()
{
    int monthNumber,year;
    cin >> monthNumber >> year;

    if(monthNumber > 12)
    {
        cout << monthNumber << " Is not a month number";
        return;
    }

    if(monthNumber == 4 || monthNumber == 6 || monthNumber == 9 || monthNumber == 11)
    cout << 30;

    else if(monthNumber == 2)
    {
        if(year%4 == 0)
        cout << 28;
        else
        cout << 29;
    }
    else
    cout << 31;

}

void Zad6()
{
    int usbPorts,ram;
    bool haveSSD, willbuy;

    cin >> usbPorts >> ram >> haveSSD;

    willbuy = usbPorts >= 3 && (ram >= 8 || haveSSD);

    cout << boolalpha << willbuy;
}

void Zad7()
{
    int number, firstD, secondD, thirdD, forthD;
    cin >> number;

    if(number/1000 < 1 || number < 0)
    {
        cout << "This is not 4 digid positive number";
        return;
    }

    firstD = number/1000;
    secondD = (number/100)%10;
    thirdD = (number/10)%10;
    forthD = number%10;

    if(max(max(max(firstD,secondD),thirdD),forthD) == firstD && firstD%2 == 0)
    cout << "true";
    else
    cout << "false";
}
#include <iostream>
#include "SmartFactory.h"
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <iomanip>
#include <iostream>
#include "Stack.h"
#include <string>
#include <windows.h>

using namespace std;

void clear()
{

    cout << endl;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
    cout << "saving";
    for (int i = 2; i > 0; i--)
    {
        cout << ".";
        Sleep(1000);
    }
    system("CLS");

}
void check()
{

    int ch;
    cout << endl;
    cout << "\033[33mPress Esc to return back to the main screen. \033[0m";
    do
    {
        ch = _getch();
        if (ch == 27)
        {
            system("CLS");
            Sleep(1000);
        }
    } while (ch != 27);

}
void Header(string x)
{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << setw(50) << setfill('*') << "" << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
    cout << setw(32) << setfill(' ') << x << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << setw(50) << setfill('*') << "" << endl;
    cout << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

}
void StartScreen()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "*****************************************************" << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "*                                                   *" << endl;
    cout << "*";
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
    cout << "              SMART FACTORY SYSTEM                 ";
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "*" << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "*                                                   *" << endl;
    cout << "*****************************************************" << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "\033[33m| 1 |\033[0m" << " Create Product" << endl;
    cout << "\033[33m| 2 |\033[0m" << " Release Product" << endl;
    cout << "\033[33m| 3 |\033[0m" << " View Products" << endl;
    cout << "\033[33m| 4 |\033[0m" << " Manage Products Order" << endl;
    cout << "\033[33m| 0 |\033[0m" << " Exit" << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "==========================================" << endl;
    cout << "Type your option : ";
}
void CreateMenu(SmartFactory<string>* factory)
{
    int key;
    system("CLS");
    Header("Product Creation");
    cout << "\033[33m| 1 |\033[0m"
        << " Add Steps" << endl;
    cout << "\033[33m| 2 |\033[0m"
        << " View Steps" << endl;
    cout << "\033[33m| 3 |\033[0m"
        << " Save Product" << endl;
    cout << "\033[33m| 0 |\033[0m"
        << " Return Main" << endl << endl;
    cout << "[*] "
        << "\033[33mChoose The Method You Want To Search With: \033[0m";
    cin >> key;
    cout << "\n\n";

    if (key == 1)
    {
        system("CLS");
        Header("ADD STEP");
        factory->productSequenceManagement();
        clear();
        CreateMenu(factory);
    }

    else if (key == 2)
    {
        system("CLS");
        Header("VIEW STEPS");
        factory->operationViewCurrStep();
        check();
        CreateMenu(factory);
    }

    else if (key == 3)
    {
        system("CLS");
        Header("SAVE PROJECT");
        factory->operationInformationStorage();
        check();
    }
    else
    {
        system("CLS");
    }
}
void ViewProduct(SmartFactory<string>* factory)
{
    int key;
    system("CLS");
    Header("Product Creation");
    cout << "\033[33m| 1 |\033[0m"
         << " Show Products" << endl;
    cout << "\033[33m| 2 |\033[0m"
         << " Show Total Products Count" << endl;
    cout << "\033[33m| 3 |\033[0m"
         << " Show Top Product Steps" << endl;
    cout << "\033[33m| 0 |\033[0m"
         << " Return Main" << endl << endl;
    cout << "[*] "
         << "\033[33mChoose The Method You Want To Search With: \033[0m";
    cin  >> key;
    cout << "\n\n";

    if (key == 1)
    {
        system("CLS");
        Header("ADD STEP");
        factory->operationInformationProduct();
        check();
        ViewProduct(factory);
    }

    else if (key == 2)
    {
        system("CLS");
        Header("VIEW STEPS");
        factory->TotalProduct();
        check();
        ViewProduct(factory);
    }
    else if (key == 3)
    {
        system("CLS");
        Header("VIEW STEPS");
        factory->operationInformationProductStep();
        check();
        ViewProduct(factory);
    }
    else
    {
        system("CLS");
    }

}

int main()
{
    int d;
    SmartFactory<string> factory;
    while (true)
    {
        StartScreen();
        cin >> d;
        cout << "\n\n\n";

        if (d == 0)
        {
            cout << "\033[33mThanks for using my project :) \033[0m" << endl;
            break;
        }

        if (d == 1)
        {
            system("CLS");
            CreateMenu(&factory);
        }

        if (d == 2)
        {
            system("CLS");
            Header("RELEASE PRODUCT");
            factory.operationInformationRelease();
            check();
        }

        if (d == 3)
        {
            system("CLS");
            Header("VIEW PRODUCTS");
            ViewProduct(&factory);
        }

        if (d == 4)
        {
            system("CLS");
            Header("MANAGE ORDER");
            factory.OrderManagement();
            check();
        }
    }
    return 0;
}

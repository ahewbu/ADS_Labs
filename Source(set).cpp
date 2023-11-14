#include <conio.h>
#include <string>
#include <iostream>
#include <utility>
#include "Set.h"

bool InputControl()
{
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        std::cout << "Enter the element of right type!" << "\n";
        system("pause");
        return false;
    }
    return true;
}

int main()
{
    srand(time(NULL));

    Set<std::string> AS;
    Set<std::string> BS;
    Set<std::string> CS;

    Set<int> AI;
    Set<int> BI;
    Set<int> CI;

    Set<float> AF;
    Set<float> BF;
    Set<float> CF;

    Set<std::pair<int, double>> AP;
    Set<std::pair<int, double>> BP;
    Set<std::pair<int, double>> CP;

    int Choice = 0;
    int Menu = 0;
    int NumberI = 0;
    float NumberF = 0;
    std::string Sequence;
    int NumberPairI = 0;
    double NumberPairD = 0;
    std::pair<int, double> temp;
    int Index;

    for (;;)
    {
        std::cout << "Laboratory work 1. Choose the type of sets to work with:" << "\n";
        std::cout << "1. std::string" << "\n";
        std::cout << "2. Integer" << "\n";
        std::cout << "3. Float" << "\n";
        std::cout << "4. Pair<int, double>" << "\n";
        std::cout << "Your choice:" << "\n";
        std::cin >> Choice;
        if ((Choice == 1) || (Choice == 2) || (Choice == 3) || (Choice == 4)) break;
        system("cls");
    }
    for (;;)
    {
        system("cls");
        std::cout << "1.Get an element by index" << "\n";
        std::cout << "2.Combining sets" << "\n";
        std::cout << "3.Difference of sets" << "\n";
        std::cout << "4.Add a number" << "\n";
        std::cout << "5.Delete a number" << "\n";
        std::cout << "6.Intersection of sets" << "\n";
        std::cout << "7.Check value in set" << "\n";
        std::cout << "8.Find unique elements" << "\n";
        std::cout << "Esc.Exit" << "\n";
        switch (Choice)
        {
        case 1:std::cout << "First set:" << AS << "\n";
            std::cout << "Second set:" << BS << "\n";
            break;
        case 2:std::cout << "First set:" << AI << "\n";
            std::cout << "Second set:" << BI << "\n";
            break;
        case 3:std::cout << "First set:" << AF << "\n";
            std::cout << "Second set:" << BF << "\n";
            break;
        case 4:std::cout << "First set:" << AP << "\n";
            std::cout << "Second set:" << BP << "\n";
            break;
        }
        Menu = _getch();
        if (Menu == 27) break;
        switch (Menu)
        {
        case 49:for (;;) //Взятие числа по индексу
        {
            system("cls");
            std::cout << "Select a set:" << "\n";
            switch (Choice)
            {
            case 1:std::cout << "1:" << AS << "\n";
                std::cout << "2:" << BS << "\n";
                break;
            case 2:std::cout << "1:" << AI << "\n";
                std::cout << "2:" << BI << "\n";
                break;
            case 3:std::cout << "1:" << AF << "\n";
                std::cout << "2:" << BF << "\n";
                break;
            case 4:std::cout << "1:" << AP << "\n";
                std::cout << "2:" << BP << "\n";
                break;
            }
            std::cout << "Esc.Back to main menu" << "\n";
            Menu = _getch();
            if (Menu == 27) break;
            switch (Menu)
            {
            case 49:
                std::cout << "Enter the index:";
                std::cin >> Index;
                if (InputControl() == false) break;
                try
                {
                    switch (Choice)
                    {
                    case 1: std::cout << "This is your number:" << AS[Index - 1] << "\n";
                        break;
                    case 2: std::cout << "This is your number:" << AI[Index - 1] << "\n";
                        break;
                    case 3: std::cout << "This is your number:" << AF[Index - 1] << "\n";
                        break;
                    case 4: std::cout << "This is your number:" << AP[Index - 1] << "\n";
                        break;
                    }
                }
                catch (const char* err)
                {
                    std::cerr << err << "\n";
                    system("pause");
                    break;
                }
                system("pause");
                break;
            case 50:std::cout << "Enter the index:";
                std::cin >> Index;
                if (InputControl() == false) break;
                try {
                    switch (Choice)
                    {
                    case 1: std::cout << "This is your number:" << BS[Index - 1] << "\n";
                        break;
                    case 2: std::cout << "This is your number:" << BI[Index - 1] << "\n";
                        break;
                    case 3: std::cout << "This is your number:" << BF[Index - 1] << "\n";
                        break;
                    case 4: std::cout << "This is your number:" << BP[Index - 1] << "\n";
                        break;
                    }
                }
                catch (const char* err)
                {
                    std::cerr << err << "\n";
                    system("pause");
                    break;
                }
                system("pause");
                break;
            }
        }
               break;

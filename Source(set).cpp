#include <conio.h>
#include <string>
#include <iostream>
#include <utility>
#include "set.h"

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

int* Create_Arr(size_t size) { // Функция создания массива
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10;
    }
    return arr;
}

bool Check(int* arr, int value, size_t size) { // Проверка существования элемента в массиве
    bool f = false;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value || (arr[i] == 0 && value == 0))
            f = true;
    }
    return f;
}

void Print_Arr(int* arr, size_t size) { // Печать массива
    std::cout << "[";
    for (size_t i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "]";
}

void Add_El(int*& arr, int value, size_t& size) { // Добавить элемент в массив
    int* temp = new int[size + 1];
    for (size_t i = 0; i < size; i++) { temp[i] = arr[i]; }
    temp[size] = value;
    delete[] arr;
    arr = temp;
    size++;
}

void Remove_El(int*& arr, int index, size_t& size) { // Удалить элемент из массива
    if (index < 0 || index >= size) {
        std::cout << std::endl << "Element by this index doesn't exist\n";
    }
    else {
        int* temp = new int[size - 1];
        for (size_t i = 0; i < index; i++) { temp[i] = arr[i]; }
        for (size_t i = index + 1; i < size; i++) { temp[i - 1] = arr[i]; }
        delete[] arr;
        arr = temp;
        size--;
    }
}

void Find_Eq_Elems(int*& arr, size_t& size, int*& ResultSet, int*& Result, size_t& s_a, size_t& s_b) { // Найти все повторяющиеся элементы
    for (int i = 0; i < size; i++) {
        if (Check(ResultSet, arr[i], size) && !Check(Result, arr[i], size)) {
            Add_El(Result, arr[i], s_a);
        }
        else {
            Add_El(ResultSet, arr[i], s_b);
        }
    }
    std::cout << std::endl << "Equal elements: ";
    for (int i = 0; i < s_a; i++) {
        std::cout << Result[i] << " ";
    }
    std::cout << std::endl;
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


    /* Вплоть до Choice - элементы для работы с массивом*/
    int* arr = Create_Arr(10);
    size_t size = 10;
    int* Res_a = new int[0]; int* Res_b = new int[0];
    size_t s_a = 0, s_b = 0;
    int val = 0, in = 0;

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
        std::cout << "8.Find equal elements" << "\n";
        std::cout << "9.Make set" << "\n";
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
        
        case 50:std::cout << "Result of combining:";//Объединение множеств
            switch (Choice)
            {
            case 1:CS = AS + BS;
                std::cout << CS << "\n";
                system("pause");
                break;
            case 2:CI = AI + BI;
                std::cout << CI << "\n";
                system("pause");
                break;
            case 3:CF = AF + BF;
                std::cout << CF << "\n";
                system("pause");
                break;
            case 4:CP = AP + BP;
                std::cout << CP << "\n";
                system("pause");
                break;
            }
            break;

        case 51:std::cout << "From which set to subtract?" << "\n";//Разность множеств
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
            Menu = _getch();
            switch (Menu)
            {
            case 49:
                std::cout << "Result of subtract:";
                switch (Choice)
                {
                case 1:CS = AS - BS;
                    std::cout << CS << "\n";
                    system("pause");
                    break;
                case 2:CI = AI - BI;
                    std::cout << CI << "\n";
                    system("pause");
                    break;
                case 3:CF = AF - BF;
                    std::cout << CF << "\n";
                    system("pause");
                    break;
                case 4:CP = AP - BP;
                    std::cout << CP << "\n";
                    system("pause");
                    break;
                }
                break;
            case 50:std::cout << "Result of subtract:";
                switch (Choice)
                {
                case 1:CS = BS - AS;
                    std::cout << CS << "\n";
                    system("pause");
                    break;
                case 2:CI = BI - AI;
                    std::cout << CI << "\n";
                    system("pause");
                    break;
                case 3:CF = BF - AF;
                    std::cout << CF << "\n";
                    system("pause");
                    break;
                case 4:CP = BP - AP;
                    std::cout << CP << "\n";
                    system("pause");
                    break;
                }
            }
            break;

        case 52:for (;;) //Добавить элемент
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
                switch (Choice)
                {
                case 1:std::cout << "Enter the sequence:";
                    std::cin >> Sequence;
                    break;
                case 2:std::cout << "Enter the number:";
                    std::cin >> NumberI;
                    break;
                case 3:std::cout << "Enter the number:";
                    std::cin >> NumberF;
                    break;
                case 4:std::cout << "Enter the int number:";
                    std::cin >> NumberPairI;
                    std::cout << "\nEnter the double number:";
                    std::cin >> NumberPairD;
                    break;
                }
                try
                {
                    switch (Choice)
                    {
                    case 1:AS + Sequence;
                        break;
                    case 2:AI + NumberI;
                        break;
                    case 3:AF + NumberF;
                        break;
                    case 4:temp = std::make_pair(NumberPairI, NumberPairD);
                        AP + temp;
                        break;
                    }
                }
                catch (const char* err)
                {
                    std::cout << err << "\n";
                    system("pause");
                    break;
                }
                break;
            case 50:switch (Choice)
            {
            case 1:std::cout << "Enter the sequence:";
                std::cin >> Sequence;
                break;
            case 2:std::cout << "Enter the number:";
                std::cin >> NumberI;
                break;
            case 3:std::cout << "Enter the number:";
                std::cin >> NumberF;
                break;
            case 4:std::cout << "Enter the int number:";
                std::cin >> NumberPairI;
                std::cout << "\nEnter the double number:";
                std::cin >> NumberPairD;
                break;
            }
                   try
                   {
                       switch (Choice)
                       {
                       case 1:BS + Sequence;
                           break;
                       case 2:BI + NumberI;
                           break;
                       case 3:BF + NumberF;
                           break;
                       case 4:temp = std::make_pair(NumberPairI, NumberPairD);
                           BP + temp;
                           break;
                       }
                   }
                   catch (const char* err)
                   {
                       std::cout << err << "\n";
                       system("pause");
                       break;
                   }
                   break;
            }
        }
               break;
        case 53:
            for (;;) //Убрать элемент
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
                    switch (Choice)
                    {
                    case 1:std::cout << "Enter the sequence:";
                        std::cin >> Sequence;
                        break;
                    case 2:std::cout << "Enter the number:";
                        std::cin >> NumberI;
                        break;
                    case 3:std::cout << "Enter the number:";
                        std::cin >> NumberF;
                        break;
                    case 4:std::cout << "Enter the int number:";
                        std::cin >> NumberPairI;
                        std::cout << "\nEnter the double number:";
                        std::cin >> NumberPairD;
                        break;
                    }
                    try
                    {
                        switch (Choice)
                        {
                        case 1:AS - Sequence;
                            break;
                        case 2:AI - NumberI;
                            break;
                        case 3:AF - NumberF;
                            break;
                        case 4:temp = std::make_pair(NumberPairI, NumberPairD);
                            AP - temp;
                            break;
                        }
                    }
                    catch (const char* err)
                    {
                        std::cout << err << "\n";
                        system("pause");
                        break;
                    }
                    break;
                case 50:switch (Choice)
                {
                case 1:std::cout << "Enter the sequence:";
                    std::cin >> Sequence;
                    break;
                case 2:std::cout << "Enter the number:";
                    std::cin >> NumberI;
                    break;
                case 3:std::cout << "Enter the number:";
                    std::cin >> NumberF;
                    break;
                case 4:std::cout << "Enter the int number:";
                    std::cin >> NumberPairI;
                    std::cout << "\nEnter the double number:";
                    std::cin >> NumberPairD;
                    break;
                }
                       try
                       {
                           switch (Choice)
                           {
                           case 1:BS - Sequence;
                               break;
                           case 2:BI - NumberI;
                               break;
                           case 3:BF - NumberF;
                               break;
                           case 4:temp = std::make_pair(NumberPairI, NumberPairD);
                               BP - temp;
                               break;
                           }
                       }
                       catch (const char* err)
                       {
                           std::cout << err << "\n";
                           system("pause");
                           break;
                       }
                       break;
                }
            }
            break;

        case 54:std::cout << "Result of intersection:";//Пересечение множеств
            switch (Choice)
            {
            case 1:CS = AS.Intersection(BS);
                break;
            case 2:CI = AI.Intersection(BI);
                break;
            case 3:CF = AF.Intersection(BF);
                break;
            case 4:CP = AP.Intersection(BP);
            }
            switch (Choice)
            {
            case 1:std::cout << CS << "\n";;
                break;
            case 2:std::cout << CI << "\n";;
                break;
            case 3:std::cout << CF << "\n";;
                break;
            case 4:std::cout << CP << "\n";;
                break;
            }
            system("pause");
            break;
        
        case 55:std::cout << "Result of availability check:";//Проверка наличия значения в множестве
            for (;;)
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
                    switch (Choice)
                    {
                    case 1:std::cout << "Enter the sequence:";
                        std::cin >> Sequence;
                        break;
                    case 2:std::cout << "Enter the number:";
                        std::cin >> NumberI;
                        break;
                    case 3:std::cout << "Enter the number:";
                        std::cin >> NumberF;
                        break;
                    case 4:std::cout << "Enter the int number:";
                        std::cin >> NumberPairI;
                        std::cout << "\nEnter the double number:";
                        std::cin >> NumberPairD;
                        break;
                    }
                    try
                    {
                        switch (Choice)
                        {
                        case 1:if (AS.Check_Value(Sequence))
                            std::cout << "Value exists\n";
                              else
                            std::cout << "Value doesn't exist\n";
                            system("pause");
                            break;
                        case 2:if (AI.Check_Value(NumberI))
                            std::cout << "Value exists\n";
                              else
                            std::cout << "Value doesn't exist\n";
                            system("pause");
                            break;
                        case 3:if (AF.Check_Value(NumberF))
                            std::cout << "Value exists\n";
                              else
                            std::cout << "Value doesn't exist\n";
                            system("pause");
                            break;
                        case 4:temp = std::make_pair(NumberPairI, NumberPairD);
                            if (AP.Check_Value(temp))
                                std::cout << "Value exists\n";
                            else
                                std::cout << "Value doesn't exist\n";
                            system("pause");
                            break;
                        }
                    }
                    catch (const char* err)
                    {
                        std::cout << err << "\n";
                        system("pause");
                        break;
                    }
                    break;
                case 50:switch (Choice)
                {
                case 1:std::cout << "Enter the sequence:";
                    std::cin >> Sequence;
                    break;
                case 2:std::cout << "Enter the number:";
                    std::cin >> NumberI;
                    break;
                case 3:std::cout << "Enter the number:";
                    std::cin >> NumberF;
                    break;
                case 4:std::cout << "Enter the int number:";
                    std::cin >> NumberPairI;
                    std::cout << "\nEnter the double number:";
                    std::cin >> NumberPairD;
                    break;
                }
                       try
                       {
                           switch (Choice)
                           {
                           case 1:if (BS.Check_Value(Sequence))
                               std::cout << "Value exists\n";
                                 else
                               std::cout << "Value doesn't exist\n";
                               system("pause");
                               break;
                           case 2:if (BI.Check_Value(NumberI))
                               std::cout << "Value exists\n";
                                 else
                               std::cout << "Value doesn't exist\n";
                               system("pause");
                               break;
                           case 3:if (BF.Check_Value(NumberF))
                               std::cout << "Value exists\n";
                                 else
                               std::cout << "Value doesn't exist\n";
                               system("pause");
                               break;
                           case 4:temp = std::make_pair(NumberPairI, NumberPairD);
                               if (BP.Check_Value(temp))
                                   std::cout << "Value exists\n";
                               else
                                   std::cout << "Value doesn't exist\n";
                               system("pause");
                               break;
                           }
                       }
                       catch (const char* err)
                       {
                           std::cout << err << "\n";
                           system("pause");
                           break;
                       }
                       break;
                }
            }
            break;
        
        case 56:std::cout << "Equal elements in: \n";
            for (;;) {
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
                    try
                    {
                        switch (Choice)
                        {
                        case 1:
                            AS.Find_Equal_Elems();
                            std::cout << "Equal elements in first set:\n";
                            system("pause");
                            break;
                        case 2:
                            AI.Find_Equal_Elems();
                            std::cout << "Equal elements in first set:\n";
                            system("pause");
                            break;
                        case 3:
                            AF.Find_Equal_Elems();
                            std::cout << "Equal elements in first set:\n";
                            system("pause");
                            break;
                        case 4:
                            AP.Find_Equal_Elems();
                            std::cout << "Equal elements in first set:\n";
                            system("pause");
                            break;
                        }
                    }
                    catch (const char* err)
                    {
                        std::cout << err << "\n";
                        system("pause");
                        break;
                    }
                    break;
                case 50:
                    try
                    {
                        switch (Choice)
                        {
                        case 1:
                            BS.Find_Equal_Elems();
                            std::cout << "Equal elements in second set:\n";
                            system("pause");
                            break;
                        case 2:
                            BI.Find_Equal_Elems();
                            std::cout << "Equal elements in second set:\n";
                            system("pause");
                            break;
                        case 3:
                            BF.Find_Equal_Elems();
                            std::cout << "Equal elements in second set:\n";
                            system("pause");
                            break;
                        case 4:
                            BP.Find_Equal_Elems();
                            std::cout << "Equal elements in second set:\n";
                            system("pause");
                            break;
                        }
                    }
                    catch (const char* err)
                    {
                        std::cout << err << "\n";
                        system("pause");
                        break;
                    }
                    break;
                }
            }
        case 57:std::cout << "Make set" << std::endl;//преобразование массива в множество
            for (;;)
            {
                switch (Choice)
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
                }
                std::cout << "Esc.Back to main menu" << "\n";
                Menu = _getch();
                if (Menu == 27) break;
                switch (Menu)
                {
                case 49:
                    try {
                        switch (Choice)
                        {
                        case 1:AS = AS.Make_Set();
                            break;
                        case 2:AI = AI.Make_Set();
                            break;
                        case 3:AF = AF.Make_Set();
                            break;
                        case 4:AP = AP.Make_Set();
                        }
                    }
                    catch (const char* err)
                    {
                        std::cout << err << "\n";
                        system("pause");
                        break;
                    }
                    break;

                case 50:
                    try {
                        switch (Choice)
                        {
                        case 1:BS = BS.Make_Set();
                            break;
                        case 2:BI = BI.Make_Set();
                            break;
                        case 3:BF = BF.Make_Set();
                            break;
                        case 4:BP = BP.Make_Set();
                        }
                    }
                    catch (const char* err)
                    {
                        std::cout << err << "\n";
                        system("pause");
                        break;
                    }
                    break;
                }

                system("pause");
                break;
            }
        case 27: //Esc
            break;
        }
    }
    return 0;
}
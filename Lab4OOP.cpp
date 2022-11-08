// Lab4OOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "PriorityStack.h"
using namespace std;


int main()
{
    setlocale(LC_ALL, "ru");
    PriorityStack stack1, stack2,  stack3;
    bool isRun = true;
    int action;double value; int priority;
    while (isRun)
    {
        cout << " 1 - добавить элемент в первый стек " << endl;
        cout << " 2 - добавить элемент в второй стек " << endl;
        cout << " 3 - извлечь элемент из стека 1" << endl;
        cout << " 4 - извлечь элемент из стека 2" << endl;
        cout << " 5 - извлечь элементы с определенным приоритетом из стека 1" << endl;
        cout << " 6 - проверка наличия элемента" << endl;
        cout << " 7 - объединение стеков" << endl;
        cout << " 8 - пересечение стеков" << endl;
        cin >> action; 
        switch (action)
        {
        case 1: 
            cout << " введите значение и приоритет: ";
            cin >> value >> priority;
            stack1.Push(value, priority);
            break;
        case 2: cout << " введите значение и приоритет: ";
            cin >> value >> priority;
            stack2.Push(value, priority);
            break;
        case 3: stack1.Pop(); break;
        case 4: stack2.Pop(); break;
        case 5: cout << " введите необходимый приоритет: ";
            cin >> priority;
            /* cout << " извлеченные элементы:\n " <<*/
            stack3 = stack1.PopPri(priority); 
            cout << stack3 << endl;
            break;
        case 6: cout << " введите значение и приоритет " << endl;
            cin >> value >> priority;
            cout << (stack1.ExistItem(value, priority)? "yes" : "no") << endl;
            break;
        case 7: stack3 = (stack1 + stack2);
            cout << stack3 << endl; break;
        case 8: cout << stack1.StackCross(stack2); break;
        case 9: isRun = false; break;
        }
        cout << " стек 1:\n" << stack1 << endl;
        cout << " стек 2:\n" << stack2 << endl;
        system("PAUSE >> VOID");
        system("cls");
    }
    /*PriorityStack a;
    a.Push(1, 1);
    a.Push(3, 2);
    cout << a;

    PriorityStack m = a;
    cout << m;*/
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

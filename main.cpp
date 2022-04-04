#include <iostream>
#include <fstream>
#include "EmployerFunctions.h"
#include "EmployeeFunctions.h"
#include <Windows.h>
#include "Employer.h"
#include "Employee.h"
// g++ -o main.exe main.cpp EmployerFunctions.cpp EmployerFunctions.h EmployeeFunctions.cpp EmployeeFunctions.h Employer.h Employee.h
using namespace std;


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Hello! Select, who you are:"
        "\n1.Employer"
        "\n2.Worker"
        "\n3.Manager (not for public using!)"
        "\n-->> ";
    int choise{};
    cin >> choise;
    cin.ignore();
    cin.clear();
    system("cls");

    switch (choise)
    {
    case 1:
    {
        cout << "\nIn case 1: ";
        Employer temp;
        temp = getEmployerInfo();
        writeEmployerInfo(temp);
        printEmployerInfo();
        /* launch of employer script */
        break;
    }
    case 2:
    {
        cout << "\nIn case 2: ";
        Employee workerTemp;
        workerTemp = getEmployeeInfo();
        writeEmployeeInfo(workerTemp);
        printEmployeeInfo();
        break;
    }
    default:
        cout << "\nSomething going wrong ";
        break;
    }
    system("pause");
    return 0;
}

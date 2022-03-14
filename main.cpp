#include <iostream>
#include <fstream>
#include "EmployerFunctions.h"
#include <Windows.h>
#include "Employer.h"
#include "Employee.h"
// g++ -o main.exe main.cpp EmployerFunctions.cpp EmployerFunctions.h Employer.h Employee.h
using namespace std;


Employee getEmployeeInfo();
void writeEmployeeInfo(Employee _employee);
void printEmployeeInfo();

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

    Employee workerTemp;
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

Employee getEmployeeInfo()
{
    Employee _employee;

    cout << "\n||___Соискатель____||\n\nДобро пожаловать, потенциальный сотрудник!\nПожалуйста, введите необходимые данные для заполнения анкеты:\n\n";
    cout << "1. Ваша фамилия: ";
    getline(cin, _employee.surname);
    cout << "\n2. Ваше имя: ";
    getline(cin, _employee.name);
    cout << "\n3. Ваше отчество: ";
    getline(cin, _employee.patronymic);
    cout << "\n4. Ваша квалификация: ";
    getline(cin, _employee.qualificationLevel);
    cout << "\n5. Желаемая должность: ";
    getline(cin, _employee.profession);
    cout << "\n\nСпасибо за ваше время! Менеджер скоро просмотрит вашу анкету. Мы сообщим вам, если появится подходящая вакансия.\n\n";
    system("pause");

    return _employee;
}

void writeEmployeeInfo(Employee _employee)
{
    ofstream inputTo("employeesList.txt", ios::app | ios::in);
    if (!inputTo.is_open()) cout << "Error! There are something wrong with file";

    inputTo.write((char*)&_employee, sizeof(_employee));

    inputTo.close();
}

void printEmployeeInfo()
{
    Employee _employee; //
    ifstream outputFrom("employeesList.txt", ios::out);
    if (!outputFrom.is_open()) cout << "Error! There are something wrong with file";

    outputFrom.seekg(0, ios_base::beg);

    while (outputFrom.read((char*)&_employee, sizeof(_employee)))
    {
        cout << _employee.surname << endl
            << _employee.name << endl
            << _employee.patronymic << endl
            << _employee.qualificationLevel << endl
            << _employee.profession << "\n\n";
    }
    outputFrom.close();
    cout << endl;
}

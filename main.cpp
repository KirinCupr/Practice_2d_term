#include <iostream>
#include <fstream>

#include <Windows.h>
#include "Employer.h"
#include "Employee.h"
using namespace std;


/*struct Worker
{
    string lastname;
    string name;
    string patronymic;
    string levelQualification;
};*/


Employer getEmloyerInfo();
void writeEmloyerInfo(Employer _employer);
void printEmloyerInfo();
Employee getEmployeeInfo();
void writeEmployeeInfo(Employee _employee);
void printEmployeeInfo();
int main()
{
    cout << "Hello! Select, who you are:"
        "\n1.Employer"
        "\n2.Worker"
        "\n3.Manager (not for public using!)"
        "\n-->> ";
    int choise{};
    Employer temp;
    Employee workerTemp;
    cin >> choise;
    cin.ignore();
    cin.clear();
    system("cls");

    switch (choise)
    {
    case 1:
        cout << "\nIn case 1: ";
        temp = getEmloyerInfo();
        writeEmloyerInfo(temp);
        printEmloyerInfo();
        /* launch of employer script */
        break;

    case 2:
        cout << "\nIn case 2: ";
        /* launch of employee script */
        workerTemp = getEmployeeInfo();
        writeEmployeeInfo(workerTemp);
        printEmployeeInfo();
        break;
    default:
        cout << "\nSomething going wrong ";
        break;
    }
    system("pause");
    return 0;
}

Employer getEmloyerInfo()
{
    Employer _employer;

    cin.clear();
    cout << "\n||___Employer____||"
        "\nPlease, write information about you:\n";

    cout << "\n1. Title of Your organization: ";
    getline(cin, _employer.title); cout << endl;

    cout << "\n2. Type of activity of Your organization: ";
    getline(cin, _employer.activityType); cout << endl;

    cout << "\n3. Address of Your organization: ";
    getline(cin, _employer.address); cout << endl;

    cout << "\n4. Phone number of Your organization: ";
    getline(cin, _employer.phoneNumber); cout << endl;

    cout << "\n\nDo you confirm the opening of a vacancy(Yes = 1, No = 0): ";
    cin >> _employer.onOpenVacancy; cout << endl;

    cout << "Thank You for using our product!\nThe manager has already started searching for suitable candidates\n";

    return _employer;
}

void writeEmloyerInfo(Employer _employer)
{
    ofstream inputTo("employersList.txt", ios::app | ios::in);
    if (!inputTo.is_open()) cout << "Error! There are something wrong with file";

    inputTo.write((char*)&_employer, sizeof(_employer));

    inputTo.close();
}

void printEmloyerInfo()
{
    Employer _employer; //
    ifstream outputFrom("employersList.txt", ios::out);
    if (!outputFrom.is_open()) cout << "Error! There are something wrong with file";

    outputFrom.seekg(0, ios_base::beg);

    while (outputFrom.read((char*)&_employer, sizeof(_employer)))
    {
        cout << _employer.title << endl
            << _employer.activityType << endl
            << _employer.address << endl
            << _employer.phoneNumber << endl
            << _employer.onOpenVacancy << "\n\n";
    }
    outputFrom.close();
    cout << endl;
}

Employee getEmployeeInfo()
{
    Employee _employee;
    
    cout << "\n||___Employer____||\n\nWelcome, potential worker!\nPlease add the required information to complete your form:\n\n";
    cout << "1. Enter your surname: ";
    getline(cin, _employee.surname);
    cout << "\n2. Enter your name: ";
    getline(cin, _employee.name);
    cout << "\n3. Enter your patronymic: ";
    getline(cin, _employee.patronymic);
    cout << "\n4. Enter your qualification level: ";
    getline(cin, _employee.qualificationLevel);
    cout << "\n5. Enter the profession you are looking for: ";
    getline(cin, _employee.profession);
    cout << "\n\nThank you for your time! The manager is going to be assigned to your form. We'll contact you once we find a suitable vacancy.\n\n";

    return _employee;
}

void writeEmloyeeInfo(Employee _employee)
{
    ofstream inputTo("employeesList.txt", ios::app | ios::in);
    if (!inputTo.is_open()) cout << "Error! There are something wrong with file";

    inputTo.write((char*)&_employee, sizeof(_employee));

    inputTo.close();
}

void printEmloyeeInfo()
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

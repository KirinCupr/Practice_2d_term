#include "EmployeeFunctions.h"

using namespace std;

Employee getEmployeeInfo()
{
    Employee _employee;
    char check;

    do
    {
        cout << "\n||___Employee____||\n\nWelcome, potential worker!\nPlease, enter the following data:\n\n";
        cout << "1. Enter your surname: ";
        getline(cin, _employee.surname);
        cout << "\n2. Enter your name: ";
        getline(cin, _employee.name);
        cout << "\n3. Enter your patronymic: ";
        getline(cin, _employee.patronymic);
        cout << "\n4. Enter your qualification: ";
        getline(cin, _employee.qualification);
        cout << "\n5. Enter your prefered profession: ";
        getline(cin, _employee.profession);
        cout << "\nIs the information correct? (Enter 'Y' - Yes, 'N' - No)\n-->>";

        cin.clear(); cin >> check; cin.ignore();
        if (check == 'N' || check == 'n') cout << "\n||___Rewriting info___||\n";
    } while (check == 'N' || check == 'n');
    
    cout << "\n\nThank you for your time! Our manager will look through your form soon. We will inform you in case of an open position that you're looking for.\n\n";
    system("pause");

    return _employee;
}

void writeEmployeeInfo(Employee _employee)
{
    ofstream inputTo("employeesList.txt", ios::out | ios::binary | ios::app);
    if (!inputTo.is_open()) cout << "Error! There are something wrong with file";

    inputTo << _employee.surname << '\t' << _employee.name << '\t'
        << _employee.patronymic << '\t' << _employee.qualification << '\t'
        << _employee.profession << '\n';

    inputTo.close();
}

void printEmployeeInfo()
{
    Employee _employee; 
    ifstream outputFrom("employeesList.txt", ios::in | ios::binary);
    if (!outputFrom.is_open()) cout << "Error! There are something wrong with file";

    outputFrom.seekg(0, ios_base::beg);

    while (true)
    {
        getline(outputFrom, _employee.surname, '\t');
        getline(outputFrom, _employee.name, '\t');
        getline(outputFrom, _employee.patronymic, '\t');
        getline(outputFrom, _employee.qualification, '\t');
        getline(outputFrom, _employee.profession, '\n');

        if (outputFrom.eof()) break;
        cout << _employee.surname << '\t' << _employee.name << '\t'
            << _employee.patronymic << '\t' << _employee.qualification << '\t'
            << _employee.profession << endl;
    }
    outputFrom.close();
    cout << endl;
}
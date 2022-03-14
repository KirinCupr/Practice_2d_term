#include "EmployerFunctions.h"

using namespace std;

Employer getEmployerInfo()
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

    cout << "\n5. Enter name of open vacancy: ";
    cin >> _employer.vacancy; cout << endl;

    cout << "\nThank You for using our product!\nThe manager has already started searching for suitable candidates\n";
    system("pause");

    return _employer;
}

void writeEmployerInfo(Employer _employer)
{
    ofstream inputTo("employersList.txt", ios::out | ios::binary | ios::app);
    if (!inputTo.is_open()) cout << "Error! There are something wrong with file";

    inputTo << _employer.title << '\t' << _employer.activityType << '\t'
            << _employer.address << '\t' << _employer.phoneNumber << '\t'
            << _employer.vacancy << endl;

    inputTo.close();
}

void printEmployerInfo()
{
    Employer _employer;
    ifstream outputFrom("employersList.txt", ios::in | ios::binary);
    if (!outputFrom.is_open()) cout << "Error! There are something wrong with file";

    outputFrom.seekg(0, ios_base::beg);

    while (!outputFrom.eof())
    {
        getline (outputFrom, _employer.title, '\t');
        getline (outputFrom, _employer.activityType, '\t');
        getline (outputFrom, _employer.address, '\t');
        getline (outputFrom, _employer.phoneNumber, '\t');
        getline (outputFrom, _employer.vacancy, '\n');
        cout << _employer.title << '\t' << _employer.activityType << '\t'
             << _employer.address << '\t' << _employer.phoneNumber << '\t'
             << _employer.vacancy << endl;
    }
    outputFrom.close();
    cout << endl;
}

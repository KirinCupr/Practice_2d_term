#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

struct Employer
{
    string title;
    string activityType;
    string address;
    string phoneNumber;
    bool onOpenVacancy;
};

/*struct Worker
{
    string lastname;
    string name;
    string patronymic;
    string levelQualification;
};*/


Employer GetEmloyerInfo();
void WriteEmloyerInfo(Employer _employer);
void PrintEmloyerInfo();
int main()
{
    cout << "Hello! Select, who you are:"
            "\n1.Employer"
            "\n2.Worker"
            "\n3.Manager (not for public using!)"
            "\n-->> ";
    int choise{};
    Employer temp;
    cin >> choise;
    cin.ignore();
    cin.clear();

    switch (choise)
    {
    case 1:
        cout << "\nIn case 1: ";
        temp = GetEmloyerInfo();
        WriteEmloyerInfo(temp);
        PrintEmloyerInfo();
        /* launch of employer script */
        break;

    case 2:
        cout << "\nIn case 2: ";
         /* launch of employer script */
         break;
    default:
        cout << "\nSomething going wrong ";
        break;
    }
    system("pause");
    return 0;
}

Employer GetEmloyerInfo()
{
    Employer _employer;

    cin.clear();
    cout << "\n||___Employer____||"
            "\nPlease, write information about you:\n";

    cout << "\n1. Title of Your organization: ";
    getline (cin, _employer.title); cout << endl;

    cout << "\n2. Type of activity of Your organization: ";
    getline (cin, _employer.activityType); cout << endl;

    cout << "\n3. Address of Your organization: ";
    getline (cin, _employer.address); cout << endl;

    cout << "\n4. Phone number of Your organization: ";
    getline (cin, _employer.phoneNumber); cout << endl;

    cout << "\n\nDo you confirm the opening of a vacancy(Yes = 1, No = 0): ";
    cin >> _employer.onOpenVacancy; cout << endl;

    cout << "Thank You for using our product!\nThe manager has already started searching for suitable candidates\n";

    return _employer;
}

void WriteEmloyerInfo(Employer _employer)
{
    ofstream inputTo("employersList.txt", ios::app | ios::in);
    if (!inputTo.is_open()) cout << "Error! There are something wrong with file";

    inputTo.write((char *) &_employer, sizeof(_employer));

    inputTo.close();
}

void PrintEmloyerInfo()
{
    Employer _employer; //
    ifstream outputFrom ("employersList.txt", ios::out);
    if (!outputFrom.is_open()) cout << "Error! There are something wrong with file";

    outputFrom.seekg(0, ios_base::beg);

    while (outputFrom.read((char *) &_employer, sizeof (_employer)))
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

/*
    password generator with diffrent options
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Password
{
private:
    string name = "?Empty?";
    char password[64];
    int passwordLength = 0;
    bool letters = false;
    bool upperCaseLetters = false;
    bool specialCharacters = false;

public:
    void getName();
    void setProperties();
    void generate();
    void displayData();
    bool checkName(string iName);
};

void Password::getName()
{
    cout << "Please enter name: ";
    getline(cin, name);
}

void Password::setProperties()
{
    string input;
    bool check = true;
    cout << "\nHow long do you want your password to be? \n->";
    getline(cin, input);
    while (check)
    {
        if (57 > input[0] && input[0] > 47)
        {
            this->passwordLength = stoi(input);
            if (this->passwordLength < 6)
            {
                cerr << "Password can't be less thank 6 characters\n->";
                getline(cin, input);
            }
            else
                check = false;
        }
        else
        {
            cerr << "Wrong Input!\n->";
            getline(cin, input);
        }
    }
    check = true;
    cout << "\nDo you want letters? (y/n)\n->";
    getline(cin, input);
    while (check)
    {
        switch (input[0])
        {
        case 'y':
            this->letters = true;
            check = false;
            break;
        case 'n':
            this->letters = false;
            check = false;
            break;
        default:
            cerr << "Wrong Input\n->";
            getline(cin, input);
        }
    }
    check = true;
    cout << "\nDo you want upper case letters? (y/n)\n->";
    getline(cin, input);
    while (check)
    {
        switch (input[0])
        {
        case 'y':
            this->upperCaseLetters = true;
            check = false;
            break;
        case 'n':
            this->upperCaseLetters = false;
            check = false;
            break;
        default:
            cerr << "Wrong Input\n->";
            getline(cin, input);
        }
    }
    check = true;
    cout << "\nDo you want special characters? (y/n)\n->";
    getline(cin, input);
    while (check)
    {
        switch (input[0])
        {
        case 'y':
            this->specialCharacters = true;
            check = false;
            break;
        case 'n':
            this->specialCharacters = false;
            check = false;
            break;
        default:
            cerr << "Wrong Input\n->";
            getline(cin, input);
        }
    }
}

void Password::generate()
{
    srand(time(0));

    for (int i = 0; passwordLength > i; i++)
    {
        if (0 + (rand() % 2))
        {
            this->password[i] = (48 + (rand() % 10));
        }
        if (0 + (rand() % 2) && upperCaseLetters)
        {
            this->password[i] = (65 + (rand() % 26));
        }
        if (0 + (rand() % 2) && specialCharacters)
        {
            this->password[i] = (33 + (rand() % 15));
        }
        if (0 + (rand() % 2) && letters)
        {
            this->password[i] = (97 + (rand() % 26));
        }
    }
    cout << "\nYour password is: ";
    for (int i = 0; this->passwordLength > i; i++)
        cout << this->password[i];
    cout << endl;
}
void Password::displayData()
{
    cout << "\nName    : " << this->name;
    cout << "\nPassword: ";
    for (int i = 0; this->passwordLength > i; i++)
        cout << this->password[i];
    cout << endl;
}

bool Password::checkName(string iName)
{
    if (iName == this->name)
    {
        return true;
    }
    else
        return false;
}

int main()
{
    Password accounts[30];
    bool check = true, namecheck = false;
    string input;
    int accountsNum = 0;

    cout << "\nPress s to stop\n";
    do
    {
        cout << "\n---Menu---\n";
        cout << "1. Make account\n";
        cout << "2. Display account\n";
        cout << "3. Generate new password\n";
        cout << "->";
        getline(cin, input);

        switch (input[0])
        {
        case '1':
            accounts[accountsNum].getName();
            accounts[accountsNum].setProperties();
            accounts[accountsNum].generate();
            accountsNum++;
            break;
        case '2':
            cout << "Enter name of account: ";
            getline(cin, input);
            for (int i = 0; accountsNum > i; i++)
            {
                if (accounts[i].checkName(input))
                {
                    namecheck = true;
                    accounts[i].displayData();
                }
            }
            if (!namecheck)
            {
                cout << "\nNo such user exists! \n";
            }
            namecheck = false;
            break;
        case '3':
            cout << "Enter name of account: ";
            getline(cin, input);
            for (int i = 0; accountsNum > i; i++)
            {
                if (accounts[i].checkName(input))
                {
                    namecheck = true;
                    cout << "Do you want new setProperties ? (y/n)\n->";
                    getline(cin, input);
                    bool check2 = true;
                    while (check2)
                    {
                        switch (input[0])
                        {
                        case 'y':
                            accounts[i].setProperties();
                            accounts[i].generate();
                            check2 = false;
                            break;
                        case 'n':
                            accounts[i].generate();
                            check2 = false;
                            break;

                        default:
                            cerr << "\nWrong input!\n->";
                            getline(cin, input);
                            break;
                        }
                    }
                }
            }
            if (!namecheck)
            {
                cout << "No such user exists! \n";
            }
            namecheck = false;
            break;
        case 's':
            check = false;
            break;
        default:
            cerr << "\nWrong input!\n";
            break;
        }

    } while (check);

    return 0;
}
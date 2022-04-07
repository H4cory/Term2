/*
    password generator with diffrent options
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class passwords
{
private:
    string name = "?Empty?";
    char password[64];
    int passwordLength;
    bool letters = false;
    bool upperCaseLetters = false;
    bool specialCharacters = false;

public:
    void getName();
    void properties();
    void generate();
    void displayData();
    bool checkName(string iName);
};

void passwords::getName()
{
    cout << "Please enter name: ";
    getline(cin, name);
}

void passwords::properties()
{
    string input;
    bool check = true;
    cout << "\nHow long do you want your password to be? \n->";
    getline(cin, input);
    while (check)
    {
        if (57 > input[0] && input[0] > 47)
        {
            passwordLength = stoi(input);
            if (passwordLength < 6)
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
            letters = true;
            check = false;
            break;
        case 'n':
            letters = false;
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
            upperCaseLetters = true;
            check = false;
            break;
        case 'n':
            upperCaseLetters = false;
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
            specialCharacters = true;
            check = false;
            break;
        case 'n':
            specialCharacters = false;
            check = false;
            break;
        default:
            cerr << "Wrong Input\n->";
            getline(cin, input);
        }
    }
}

void passwords::generate()
{
    srand(time(0));

    for (int i = 0; passwordLength > i;)
    {
        if (0 + (rand() % 2))
        {
            password[i++] = (48 + (rand() % 10));
        }
        if (0 + (rand() % 2) && upperCaseLetters)
        {
            password[i++] = (65 + (rand() % 26));
        }
        if (0 + (rand() % 2) && specialCharacters)
        {
            password[i++] = (33 + (rand() % 15));
        }
        if (0 + (rand() % 2) && letters)
        {
            password[i++] = (97 + (rand() % 26));
        }
    }
    cout << "\nYour password is: ";
    for (int i = 0; passwordLength > i; i++)
        cout << password[i];
    cout << endl;
}
void passwords::displayData()
{
    cout << "\nName    : " << name;
    cout << "\nPassword: ";
    for (int i = 0; passwordLength > i; i++)
        cout << password[i];
    cout << endl;
}

bool passwords::checkName(string iName)
{
    if (iName == name)
    {
        return true;
    }
    else
        return false;
}

int main()
{
    passwords accounts[30];
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
            accounts[accountsNum].properties();
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
                    cout << "Do you want new properties ? (y/n)\n->";
                    getline(cin, input);
                    bool check2 = true;
                    while (check2)
                    {
                        switch (input[0])
                        {
                        case 'y':
                            accounts[i].properties();
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
        case '4':
            /* code */
            break;
        case '5':
            /* code */
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
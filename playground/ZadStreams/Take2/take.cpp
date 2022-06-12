/*

*/
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{

    string input;
    fstream textFile;
    string name;
    string EGN;
    string bDate;
    bool check = true;
    int br = 0, i = 0;

    textFile.open("saveData.txt", ios::app);
    textFile.close();
    textFile.open("saveData.txt");
    if (!textFile)
        cout << "\nCouldn't open file!\n";

    getline(textFile, input);
    if (!input.empty())
    {

        for (;; i++)
        {
            if (input[i] == '$')
            {
                name = input.substr(br, i);
                br = i + 1;
                i++;

                break;
            }
        }
        for (;; i++)
        {
            if (input[i] == '$')
            {
                EGN = input.substr(br, i - br);
                br = i + 1;
                i++;

                break;
            }
        }
        for (;; i++)
        {
            if (input[i] == '$')
            {
                bDate = input.substr(br, i - br);
                br = i + 1;
                i++;

                break;
            }
        }
    }

    textFile.close();

    cout << "\nPress s to stop";
    while (check)
    {
        cout << "\n\n1.Get Data";
        cout << "\n2.Display Data";
        cout << "\n3.Example";
        cout << "\n->";
        getline(cin, input);

        switch (input[0])
        {
        case '1':

            cout << "\nName: ";
            getline(cin, name);
            cout << "EGN: ";
            getline(cin, EGN);
            cout << "bDate: ";
            getline(cin, bDate);

            textFile.open("saveData.txt",ios::out | ios::trunc);
            if (!textFile)
                cout << "\nThere was an error with the file!\n";
            else
            {
                textFile << name << "$" << EGN << "$" << bDate << "$";
                textFile.close();
            }

            break;

        case '2':
            cout << "\nName: " << name;
            cout << "\nEGN: " << EGN;
            cout << "\nBdate: " << bDate;
            break;
        case '3':
            break;
        case 's':
            check = false;
            break;
        default:
            cout << "\nWrong input!\n";
            break;
        }
    }

    return 0;
}
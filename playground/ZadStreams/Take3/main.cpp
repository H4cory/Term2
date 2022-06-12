/*
V gradinski tsentar se prodavat rasteniya (naimenovanie, tsena, broy), koito bivat darveta (visochina,
vid(iglolistni/shirokolistni)) i tsvetya (tsvyat). Dannite za vsyako rastenie se sahranyava v masiv.
Da se sastavi programa, koyato izpalnyava ot menyu slednite operatsii:
-    dobavya kam masiva dannite na novo rastenie;
-    izvezhda vsichki vavedeni danni;
-    izvezhda danni za iglolistnite darveta;
-    sazdava masiv s dannite na rasteniyata s tsena pod 10lv.
*/

#include <iostream>
#include <string>
#include <array>
#include <fstream>

using namespace std;

class Abstr
{
private:
public:
    virtual void getData() = 0;
    virtual void displayData() = 0;
    virtual bool checkName(string) = 0;

    virtual string saveData() = 0;
};

class Plants : public Abstr
{
private:
    string name;
    string price;
    string units;
    fstream textFile;

public:
    Plants()
    {
    }

    Plants(string input)
    {
        // gets data from file
        int i = 0;
        int count = 0;
        getData(input, i, count, name);
        getData(input, i, count, price);
        getData(input, i, count, units);
    }

    void getData(string input, int &i, int &count, string &answer)
    {
        while (true)
        {
            if (input[i] == '$')
            {
                answer = input.substr(count, i - count);
                count = i + 1;
                i++;
                break;
            }
            else
                i++;
        }
    }
    void getData()
    {
        cout << "\nName: ";
        getline(cin, name);
        cout << "Price: ";
        getline(cin, price);
        cout << "Units: ";
        getline(cin, units);
        textFile.open("saveData.txt", ios::app);
        if (textFile.is_open())
        {
            textFile << name << "$" << price << "$" << units << "$\n";
            textFile.close();
        }
        else
            cout << "\nFile couldn't open!";
    }

    void displayData()
    {
        cout << "\nName: " << name;
        cout << "\nPrice: " << price;
        cout << "\nUnits: " << units;
    }
    bool checkName(string input)
    {
        if (input == name)
        {
            return true;
        }
        else
            return false;
    }

    string saveData()
    {
        return name + "$" + price + "$" + units + "$\n";
    }
};

int main()
{

    fstream textFile;

    Abstr *plant[50];
    int pCount = 0;
    string input, holder;
    array<bool, 10> check;
    check.fill(true);

    // checks if file exists
    textFile.open("saveData.txt", ios::app);
    textFile.close();

    // gets data from files
    textFile.open("saveData.txt");
    if (textFile.is_open())
    {
        while (!textFile.eof())
        {
            getline(textFile, input);
            if (input.empty())
            {
                break;
            }
            else
                plant[pCount++] = new Plants(input);
        }
        textFile.close();
    }
    else
        cout << "\nFile couldn't open!";

    // menu
    cout << "\nPress s to stop\n";

    while (check[0])
    {
        cout << "\n<----MENU---->\n";
        cout << "\n1.Get Data";
        cout << "\n2.Display";
        cout << "\n3.Delete plant";
        cout << "\nSmt";
        cout << "\n-->";
        getline(cin, input);

        switch (input[0])
        {
        case '1':
            plant[pCount] = new Plants();
            plant[pCount++]->getData();
            break;

        case '2':
            for (int i = 0; i < pCount; i++)
            {
                plant[i]->displayData();
                cout << endl;
            }

            break;
        case '3':
            cout << "\nName of plant: ";
            getline(cin, input);

            // delete in class
            for (int i = 0; i < pCount; i++)
            {
                if (plant[i]->checkName(input))
                {
                    for (int j = i; j < pCount; j++)
                    {
                        plant[j] = plant[j + 1];
                    }
                    pCount--;
                }
            }

            // rewrite file
            textFile.open("saveData.txt", ios::out | ios::trunc);
            if (textFile.is_open())
            {
                for (int i = 0; i < pCount; i++)
                {

                    textFile << plant[i]->saveData();
                }
                textFile.close();
            }
            else
                cout << "\nFile couldn't open!";
            cout << "\nDONE!";
            break;
        case '4':

            break;
        case 's':
            check[0] = false;

            break;
        default:
            cerr << "\nWrong input!\n";
        }
    }

    return 0;
}
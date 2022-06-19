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
#include "Plants.h"

using namespace std;

// displays data
void display(int pCount, Abstr *plant[])
{
    for (int i = 0; i < pCount; i++)
    {
        plant[i]->displayData();
        cout << endl;
    }
}
// gets data
void get(int &pCount, Abstr *plant[])
{
    plant[pCount] = new Plants();
    plant[pCount++]->getData();
}

// deletes object from class
void deleteFromClass(int &pCount, Abstr *plant[], string input)
{
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
}

// saves all data from class
void saveData(int &pCount, Abstr *plant[])
{
    fstream textFile;
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
    {
        cout << "\nFile couldn't open!";
    }
    cout << "\nDONE!\n";
}

// gets data from file
void getSavedData(int &pCount, Abstr *plant[])
{
    string input;
    fstream textFile;

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
            {
                plant[pCount++] = new Plants(input);
            }
        }
        textFile.close();
    }
    else
    {
        cout << "\nFile couldn't open!";
    }
}

// MAIN
int main()
{

    Abstr *plant[50];
    int pCount = 0;
    string input, holder;
    array<bool, 10> check;
    check.fill(true);

    // Gets saved data
    getSavedData(pCount, plant);

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
            // Creates a new object and gets data
        case '1':

            get(pCount, plant);
            break;

            // displays all data
        case '2':

            display(pCount, plant);

            break;

            // deletes an object
        case '3':
            cout << "\nName of plant: ";
            getline(cin, input);

            // deletes object in class
            deleteFromClass(pCount, plant, input);

            // rewrite file
            saveData(pCount, plant);

            display(pCount, plant);
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
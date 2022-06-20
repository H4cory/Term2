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
#include <fstream>
#include "Trees.h"
#include "Flowers.h"
using namespace std;

// gets data
void get(int &pCount, Abstr *plant[])
{
    string input;
    cout << "\nEnter: \n1.Trees\n2.Flowers\n-->";
    getline(cin, input);
    if (input[0] == '1')
    {
        plant[pCount] = new Trees;
        plant[pCount++]->getData();
    }
    else if (input[0] == '2')
    {
        plant[pCount] = new Flowers;
        plant[pCount++]->getData();
    }
    else
        cout << "\nWrong input!\n";
}

// displays data
void display(int pCount, Abstr *plant[])
{
    if (pCount > 0)
    {
        for (int i = 0; i < pCount; i++)
        {
            plant[i]->displayData();
            cout << endl;
        }
    }
    else
        cout << "\nThere is nothing to display!\n";
}

// deletes object from class
bool deleteFromClass(int &pCount, Abstr *plant[], string input)
{
    int match = false;
    for (int i = 0; i < pCount; i++)
    {
        if (plant[i]->checkName(input))
        {
            for (int j = i; j < pCount; j++)
            {
                plant[j] = plant[j + 1];
            }
            pCount--;
            match = true;
        }
    }
    return match;
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
    bool checkFile = false;

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
                switch (input[0])
                {
                case 't':
                    plant[pCount++] = new Trees(input);
                    break;
                case 'f':
                    plant[pCount++] = new Flowers(input);
                    break;
                default:
                    cout << "\nData for item is broken, file would be reset after reading all!\n";
                    checkFile = true;
                }
            }
        }
        textFile.close();
    }
    else
    {
        cout << "\nFile couldn't open!";
    }

    if (checkFile)
    {
        saveData(pCount, plant);
    }
}

// display all Coniferous trees
void checkCon(int pCount, Abstr *plant[])
{
    bool mathc = false;
    for (int i = 0; i < pCount; i++)
    {
        if (plant[i]->isCon())
        {
            plant[i]->displayData();
            cout << endl;
            mathc = true;
        }
    }
    if (!mathc)
    {
        cout << "\nNo Coniferous trees found !\n";
    }
}

// save plants under 10$
void savePlants(int pCount, Abstr *plant[], int &nPCount, Abstr *nPlant[])
{
    nPCount = 0;
    bool match = false;
    for (int i = 0; i < pCount; i++)
    {
        if (plant[i]->checkPr())
        {
            nPlant[nPCount++] = plant[i];
            match = true;
        }
    }
    if (!match)
    {
        cout << "\nNo such plants were found!!\n";
    }
    else
        cout << "\nDONE!\n";
}

// MAIN
int main()
{

    Abstr *plant[50], *nPlant[50];
    int pCount = 0, nPCount = 0;
    string input, holder;
    bool check = true;

    // Gets saved data
    getSavedData(pCount, plant);

    // menu
    cout << "\nPress s to stop\n";

    while (check)
    {
        cout << "\n<----MENU---->\n";
        cout << "\n1.Get Data";
        cout << "\n2.Display";
        cout << "\n3.Delete plant";
        cout << "\n4.Display coniferous trees";
        cout << "\n5.Save all plants under 10$";
        cout << "\n6.Display all plants under 10$";
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
            if (deleteFromClass(pCount, plant, input))
            {

                // rewrite file
                saveData(pCount, plant);
                display(pCount, plant);
            }
            else
            {
                cout << "\nNo such plant was found!!\n";
            }

            break;
        case '4':

            // display all Coniferous trees
            checkCon(pCount, plant);

            break;
        case '5':

            // saves all plant under 10$
            savePlants(pCount, plant, nPCount, nPlant);
            break;
        case '6':
            // displays all plants under 10$
            display(nPCount, nPlant);
            break;
        case 's':
            check = false;

            break;
        default:
            cerr << "\nWrong input!\n";
        }
    }

    return 0;
}
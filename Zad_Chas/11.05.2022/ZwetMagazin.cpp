/*
V gradinski tsentar se prodavat rasteniya (naimenovanie, tsena, broy),
koito bivat darveta (visochina, vid(iglolistni/shirokolistni)) i tsvetya
(tsvyat). Dannite za vsyako rastenie se sahranyava v masiv.
Da se sastavi programa, koyato izpalnyava ot menyu slednite operatsii:
-       dobavya kam masiva dannite na novo rastenie;
-       izvezhda vsichki vavedeni danni;
-       izvezhda dannite na darvetata s visochina nad 2metra;
-       sazdava masiv s dannite na vsichki tsvetya.


*/

#include <iostream>
#include <string>
#include <array>
#include "Trees.h"
#include "Flowers.h"
using namespace std;

void error()
{
    cerr << "\nWrong input!";
}

void getPlants(AbstractPlants *Plants[], int &plantNum)
{
    string input;
    cout << "\nEnter: \n1.Trees\n2.Flowers\n-->";
    getline(cin, input);
    if (input[0] == '1')
    {
        Plants[plantNum] = new Trees;
        Plants[plantNum++]->getData();
    }
    else if (input[0] == '2')
    {
        Plants[plantNum] = new Flowers;
        Plants[plantNum++]->getData();
    }
    else
        error();
}

void displayAll(AbstractPlants *Plants[], int plantNum)
{
    for (int i = 0; i < plantNum; i++)
    {
        Plants[i]->displayData();
        cout << endl;
    }
}

void displayExpensive(AbstractPlants *Plants[], int plantNum)
{
    for (int i = 0; i < plantNum; i++)
    {
        if (Plants[i]->tall())
        {
            Plants[i]->displayData();
            cout << endl;
        }
    }
}

void saveFlowers(AbstractPlants *Plants[], int plantNum, AbstractPlants *newFlowers[], int &flowerNum)
{
    for (int i = 0; i < plantNum; i++)
    {
        if (Plants[i]->flower())
        {
            newFlowers[flowerNum] = new Flowers;
            newFlowers[flowerNum++] = Plants[i];
        }
    }

    cout << "\nDONE!\n";
}

void displayAllFlowers(AbstractPlants *newFlowers[], int flowerNum)
{
    for (int i = 0; i < flowerNum; i++)
    {
        newFlowers[i]->displayData();
        cout << endl;
    }
}

int main()
{
    AbstractPlants *Plants[30];
    int plantNum = 0, flowerNum = 0;
    AbstractPlants *newFlowers[30];
    string input;
    array<bool, 10> check;
    check.fill(true);

    cout << "\nPress s to stop\n";

    while (check[0])
    {
        cout << "\n<----MENU---->\n";
        cout << "\n1.Enter a new plant.";
        cout << "\n2.Display all plants.";
        cout << "\n3.Display trees over 2 meters.";
        cout << "\n4.Save all flowers.";
        cout << "\n5.Display saved flowers.";
        cout << "\n-->";
        getline(cin, input);

        switch (input[0])
        {
        case '1':
            getPlants(Plants, plantNum);
            break;
        case '2':
            displayAll(Plants, plantNum);

            break;
        case '3':
            displayExpensive(Plants, plantNum);

            break;
        case '4':
            saveFlowers(Plants, plantNum, newFlowers, flowerNum);

            break;
        case '5':
            displayAllFlowers(newFlowers, flowerNum);
            break;
        case 's':
            check[0] = false;

            break;
        default:
            error();
        }
    }

    return 0;
}
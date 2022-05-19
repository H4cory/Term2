/*
V gradinski tsentar se prodavat rasteniya (naimenovanie, tsena, broy),
koito bivat darveta (visochina, vid(iglolistni/shirokolistni)) i tsvetya
(tsvyat). Dannite za vsyako rastenie se sahranyava v masiv.
Da se sastavi programa, koyato izpalnyava ot menyu slednite operatsii:
-       dobavya kam masiva dannite na novo rastenie;
-       izvezhda vsichki vavedeni danni;
-       izvezhda rastenieto s nay-visoka tsena;
-       sazdava masiv s naimenovaniyata na chervenite tsvetya.
*/

#include <iostream>
#include <string>
#include <array>
#include <cfloat>

using namespace std;

// Abstract class
class AbstractPlants
{
public:
    virtual void getData() = 0;
    virtual void displayData() = 0;
    virtual bool colorCheck() = 0;
};

// Class CPLANTS
class CPlants : public AbstractPlants
{
private:
    string name;
    string units;
    float price;

public:
    CPlants() : name("?"), units("?"), price(0.0)
    {
    }
    CPlants(string n) : units("?"), price(0.0)
    {
        name = n;
    }

    bool comparePrice(float &compare)
    {
        if (price > compare)
        {
            compare = price;
            return true;
        }
        else
            return false;
    }

    void getData()
    {
        cout << "\nName: ";
        getline(cin, name);
        cout << "Available units: ";
        getline(cin, units);
        cout << "Price per unit: ";
        cin >> price;
        cin.ignore();
    }
    void displayData()
    {
        cout << "\nName: " << name;
        cout << "\nAvailable units: " << units;
        cout << "\nPrice per unit: " << price;
    }
    void displayData(int a)
    {
        cout << "\nName: " << name;
    }

    string returnName()
    {
        return name;
    }
    bool colorCheck()
    {
        return false;
    }
};

// class Trees
class Trees : public CPlants
{
private:
    string height;
    string type;

public:
    Trees() : height("?"), type("?")
    {
    }

    void getData()
    {
        CPlants::getData();
        cout << "Height: ";
        getline(cin, height);
        cout << "\n1.Coniferous\n2.Deciduous\n~Or just enter the species you want.\nType: ";
        getline(cin, type);
        if (type[0] == '1')
        {
            type = "Coniferous";
        }
        else if (type[0] == '2')
        {
            type = "Deciduous";
        }
    }

    void displayData()
    {
        CPlants::displayData();
        cout << "\nHeight: " << height;
        cout << "\nType: " << type;
    }

    bool colorCheck()
    {
        return false;
    }
};

// class Flowers
class Flowers : public CPlants
{
private:
    string color;

public:
    Flowers() : color("?")
    {
    }

    void getData()
    {
        CPlants::getData();
        cout << "Color: ";
        getline(cin, color);
    }

    void displayData()
    {
        CPlants::displayData();
        cout << "\nColor: " << color;
    }
    bool colorCheck()
    {
        if (color == "red" || color == "Red")
        {
            return true;
        }
        else
            return false;
    }
};

// error
void error()
{
    cerr << "\nWrong input!";
}

// input plants
void getPlants(CPlants *Plants[], int &plantNum)
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

// display all plants
void displayAll(CPlants *Plants[], int plantNum)
{
    for (int i = 0; i < plantNum; i++)
    {
        Plants[i]->displayData();
        cout << endl;
    }
}

// display most expensive plant
void displayExpensive(CPlants *Plants[], int plantNum)
{
    float compare = FLT_MIN;
    int holder = 0;
    for (int i = 0; i < plantNum; i++)
    {
        if (Plants[i]->comparePrice(compare))
        {
            holder = i;
        }
    }
    Plants[holder]->displayData();
}

// save red flowers
void saveFlowers(CPlants *Plants[], int plantNum, CPlants *newFlowers[], int &flowerNum)
{
    for (int i = 0; i < plantNum; i++)
    {
        if (Plants[i]->colorCheck())
        {
            newFlowers[flowerNum++] = new CPlants(Plants[i]->returnName());
        }
    }

    cout << "\nDONE!\n";
}

// display saved flowers
void displayAllFlowers(CPlants *newFlowers[], int flowerNum)
{
    for (int i = 0; i < flowerNum; i++)
    {
        newFlowers[i]->displayData(1);
        cout << endl;
    }
}

// main
int main()
{
    CPlants *Plants[30];
    int plantNum = 0, flowerNum = 0;
    CPlants *newFlowers[30];
    string input;
    array<bool, 10> check;
    check.fill(true);

    cout << "\nPress s to stop\n";

    while (check[0])
    {
        cout << "\n<----MENU---->\n";
        cout << "\n1.Enter a new plant.";
        cout << "\n2.Display all plants.";
        cout << "\n3.Display most expensive plant.";
        cout << "\n4.Save name of flowers with the color red.";
        cout << "\n5.Display names of flowers with the color red.";
        cout << "\n-->";
        getline(cin, input);

        switch (input[0])
        {

        case '1': // enter new plant
            getPlants(Plants, plantNum);
            break;
        case '2': // display all plants
            displayAll(Plants, plantNum);

            break;
        case '3': // most expensive plant
            displayExpensive(Plants, plantNum);

            break;
        case '4': // save red flowers
            saveFlowers(Plants, plantNum, newFlowers, flowerNum);

            break;
        case '5': // display saved flowers
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
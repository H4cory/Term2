/*
2. V magazin za mebeli se predlagat mebeli (naimenovanie i tsena), kato te bivat stolove (naimenovanie, tsena, tsvyat)
i masi (naimenovanie, tsena, broy mesta na masata) Dannite da se sahranyavat v edna obshta dannova struktura,
naprimer podhodyasht masiv (polimorfizam).
Da se sastavi programa, koyato izpalnyava ot menyu slednite operatsii:
-dobavya kam masiva danni za stol ili masa
-izvezhda vsICHKI VAVEDeni danni;
-iztriva danni za mebel po zadadeno naimenovanie;
-izvezhda dannite za vsichki beli stolove;
-sazdava masiv s dannite na vsichki masi za chetirima.
*/

#include <iostream>
#include <string>

using namespace std;

class Abst
{
public:
    virtual void getData() = 0;
    virtual void displayData() = 0;
    virtual bool returnColorW() = 0;
    virtual bool returnSpots4() = 0;
};

class Furniture : public Abst
{
private:
    string name;
    string price;

public:
    Furniture() : name("?"), price("?")
    {
    }

    void getData()
    {
        cout << "\nName: ";
        getline(cin, name);
        cout << "Price: ";
        getline(cin, price);
    }

    void displayData()
    {
        cout << "\nName: " << name;
        cout << "\nPrice: " << price;
    }
    bool reurnName(string input)
    {
        if(name == input)
        return true;
        else 
        return false;
    }
};

class Chair : public Furniture
{
private:
    string color;

public:
    Chair() : color("?")
    {
    }

    void getData()
    {
        Furniture::getData();
        cout << "Color: ";
        getline(cin, color);
    }

    void displayData()
    {
        Furniture::displayData();
        cout << "\nColor: " << color;
    }

    bool returnColorW()
    {
        if (color == "white" || color == "White")
            return true;
        else
            return false;
    }
    bool returnSpots4()
    {
        return false;
    }
};

class Table : public Furniture
{
private:
    int spots;

public:
    Table() : spots(0)
    {
    }
    void getData()
    {
        Furniture::getData();
        cout << "Table spots: ";
        cin >> spots;
        cin.ignore();
    }

    void displayData()
    {
        Furniture::displayData();
        cout << "\nColor: " << spots;
    }

    bool returnColorW()
    {
        return false;
    }
    bool returnSpots4()
    {
        if (spots == 4)
            return true;
        else
            return false;
    }
};

void wrongInput()
{
    cerr << "\nWrong input!!!!\n";
}

int main()
{
    Furniture *Fur[100];
    Furniture *Tab[100];
    int FurC = 0, TabC = 0;
    string input;
    bool check = true;

    cout << "\n Press s to stop";
    while (check)
    {
        cout << "\n1.Get data";
        cout << "\n2.Display Data";
        cout << "\n3.Delete";
        cout << "\n4.Return color white";
        cout << "\n5.Save 4 spoted tables";
        cout << "\n6.Display saved tables";
        cout << "\n-->";
        getline(cin, input);

        switch (input[0])
        {
        case '1':
            cout << "\n1. Chair\n2. Table\n->";
            getline(cin, input);
            if (input[0] == '1')
            {
                Fur[FurC] = new Chair;
                Fur[FurC++]->getData();
            }
            else if (input[0] == '2')
            {
                Fur[FurC] = new Table;
                Fur[FurC++]->getData();
            }
            else
                wrongInput();
            break;
        case '2':
            for (int i = 0; i < FurC; i++)
            {

                Fur[i]->displayData();
                cout << endl;
            }
            break;
        case '3':
            cout << "\nName: ";
            getline(cin, input);
            for (int i = 0; i < FurC; i++)
            {
                if (Fur[i]->reurnName(input))
                {
                    for (int j = i; j < FurC; j++)
                    {
                        Fur[j] = Fur[j + 1];
                    }
                    FurC--;
                }
            }
            cout << "\nDone!\n";
            break;
        case '4':
            for (int i = 0; i < FurC; i++)
            {
                if (Fur[i]->returnColorW())
                {
                    Fur[i]->displayData();
                    cout<<endl;
                }
            }
            break;
        case '5':
            for (int i = 0; i < FurC; i++)
            {
                if (Fur[i]->returnSpots4())
                {
                    Tab[TabC++] = Fur[i];
                }
            }
            cout << "\nDone!";
            break;
        case '6':
            for (int i = 0; i < TabC; i++)
            {

                Tab[i]->displayData();
                cout << endl;
            }
            break;
        case 's':
            check = false;
            break;
        default:
            wrongInput();
        }
    }

    return 0;
}
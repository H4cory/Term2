/*
Da se sastavi programa, koyato sahranyava v masiv slednata informatsiya za lekarstvata v edna apteka:
-	naimenovanie simvolen niz;
-	tsena - realno chislo;
-	nalichno kolichestvo - tsyalo chislo;
-	data, do koyato e godno za upotreba

i izvarshva slednite operatsii, izbirani ot menyu:
-	dobavya kam masiva  dannite na novo lekarstvo;
-	izvezhda vsichki vavedeni danni;
-	izvezhda imenata na lekarstvata s tsena nad 5 lv.;
-	sazdava nov masiv s dannite na lekarstvata s nalichni kolichestva pod 10 broya;
-	sazdava nov masiv s imenata na lekarstvata s iztichasht srok na godnost na zadadena data.

Zabelezhka:
Sazdayte klas za operirane s data, koyto da izpolzvate kato chlen danni za srok na godnost.


*/
#include <iostream>
#include <string>

using namespace std;
class exDate
{
public:
    int D, M, Y;

    void setExDate()
    {
        cout << "Day: ";
        cin >> D;
        cout << "Month: ";
        cin >> M;
        cout << "Year: ";
        cin >> Y;
    }
    void displayExDate()
    {
        cout << "Day: " << D << endl;

        cout << "Month: " << M << endl;

        cout << "Year: " << Y << endl;
    }
};

class drugs
{

private:
    string name;
    float price;
    int amount;
    exDate date;

public:
    void getData();
    void displayData();
    void displayDrugsOver5();
    int checkAmount();
    int checkExDate(exDate Date);
    string GetName();
};

class exDateName
{
private:
    string name;

public:
    void Name(string a)
    {
        name = a;
    }
    void display()
    {
        cout << "Name: " << name << endl;
    }
};

void drugs::getData()
{
    cout << "Name: ";
    getline(cin, name);
    cout << "Price: ";
    cin >> price;
    cout << "Available amount: ";
    cin >> amount;
    date.setExDate();
}

void drugs::displayData()
{
    cout << "Name: " << name << endl;

    cout << "Price: " << price << endl;

    cout << "Available amount: " << amount << endl;
    date.displayExDate();
}
void drugs::displayDrugsOver5()
{
    if (price > 5)
        cout << "Name: " << name << endl;
}
int drugs::checkAmount()
{
    if (amount < 10)
        return true;
    else
        return false;
}

int drugs::checkExDate(exDate aDate)
{
    if (date.Y == aDate.Y && date.M == aDate.M && date.D == aDate.D)
        return true;
    else
        return false;
}

string drugs::GetName()
{
    return name;
}

// MAIN @@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int main()
{
    exDate aDate;
    drugs medication[100];
    drugs medicationUnderAmount[100];
    exDateName medicationAfterExDateName[100];
    bool check = true;
    int input, medNum = 0, MUAC = 0, MAEDN = 0;

    while (check)
    {
        cout << "1. Add Drug \n";
        cout << "2. Display all drugs \n";
        cout << "3. Display drugs over 5lv \n";
        cout << "4. Group all drugs with less than 10 in stock \n";
        cout << "5. Group all drugs with ex. date after set date \n";
        cout << "-> ";
        cin >> input;
        cin.ignore();

        switch (input)
        {
        case 1:
            medication[medNum++].getData();
            break;

        case 2:
            for (int i = 0; i < medNum; i++)
            {
                cout << "Med NUM " << i + 1 << " :\n";
                medication[i].displayData();
            }

            break;

        case 3:
            for (int i = 0; i < medNum; i++)
            {

                medication[i].displayDrugsOver5();
            }

            break;

        case 4:
            for (int i = 0; i < medNum; i++)
            {
                if (medication[i].checkAmount())
                {
                    medicationUnderAmount[MUAC] = medication[i];
                    MUAC++;
                }
            }

            for (int i = 0; i < MUAC; i++)
            {
                medicationUnderAmount[i].displayData();
            }

            break;

        case 5:
            aDate.setExDate();

            for (int i = 0; i < medNum; i++)
            {
                if (medication[i].checkExDate(aDate))
                {
                    medicationAfterExDateName[MAEDN].Name(medication[i].GetName());
                    MAEDN++;
                }
            }
            for (int i = 0; i < MAEDN; i++)
            {
                medicationAfterExDateName[i].display();
            }

            break;

        case 666:
            check = false;
            break;

        default:
            cerr << "Incorect input\n";
        }
    }

    return 0;
}
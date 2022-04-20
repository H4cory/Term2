/*
Grupa delegati na natsionalna konferentsiya:
(ime, EGN, naseleno myasto, patni razhodi) sa
 nastaneni v nyakolko
hotela ( ime na hotela, nomer na stayata,
 tsena na noshtuvkata).
Vseki delegat poluchava delegatska karta s
 vpisani:
delegatski nomer (6 znaka), data na pristigane,
 data na otpatuvane.
Dannite za vseki delegat, hotela, v koyto e
nastanen, i negovata delegatska karta se
sahranyavat v masiv.
Da se sastavi programa, koyato izpalnyava ot
menyu slednite operatsii:

-	dobavya kam masiva dannite na nov delegat,
 delegatskata mu karta i hotela, v koyto e
 nastanen;

-	izvezhda vsichki vavedeni danni;

-	namira sumata, koyato tryabva da se
 zaplati na posochen hotel za noshtuvkite
 na delegatite ot
 zadadeno naseleno myasto;

-	izvezhda imeto na nay-rano pristignaliya
delegat mazh i dannite za hotela, v koyto e
nastanen;

-	sazdava masiv s dannite za delegatite
(ime, EGN, naseleno myasto, patni razhodi)
 ot posocheno naseleno
 myasto.

*/
#include <iostream>
#include <string>
using namespace std;

class CDate
{
private:
    int arrDate[3];
    int depDate[3];

public:
    CDate() : arrDate{0}, depDate{0}
    {
    }

    void getArrDate()
    {
        cout << "\nDay: ";
        cin >> arrDate[0];
        cout << "Month: ";
        cin >> arrDate[1];
        cout << "Year: ";
        cin >> arrDate[2];
        cin.ignore();
    }
    void getDepDate()
    {
        cout << "\nDay: ";
        cin >> depDate[0];
        cout << "Month: ";
        cin >> depDate[1];
        cout << "Year: ";
        cin >> depDate[2];
        cin.ignore();
    }
    void displayDepDate()
    {
        cout << depDate[0] << '.' << depDate[1] << '.' << depDate[2] << " y.";
    }
    void displayArrDate()
    {
        cout << arrDate[0] << '.' << arrDate[1] << '.' << arrDate[2] << " y.";
    }
    int returnDays()
    {
        return depDate[0] - arrDate[0];
    }

    int returnEarlyDays()
    {
        return arrDate[0] + arrDate[1] * 30;
    }
};

class Delegate
{
private:
    string name;
    string EGN;
    string oPlace;
    float roadExp;

public:
    Delegate()
    {
        roadExp = 0;
        name = '?';
        EGN = '?';
        oPlace = '?';
    }
    void getData()
    {
        cout << "\nName: ";
        getline(cin, name);
        cout << "EGN:";
        getline(cin, EGN);
        cout << "Place of origin: ";
        getline(cin, oPlace);
        cout << "Road expenses: ";
        cin >> roadExp;
        cin.ignore();
    }

    void displayData()
    {
        cout << "\nName: " << name;
        cout << "\nEGN: " << EGN;
        cout << "\nPlace of origin: " << oPlace;
        cout << "\nRoad expenses: " << roadExp;
    }

    string returnOPlace()
    {
        return oPlace;
    }
    string returnName()
    {
        return name;
    }
    string returnEGN()
    {
        return EGN;
    }
    float returnReoadExp()
    {
        return roadExp;
    }
    void getNewData(string oplace, string nName, string nEGN, float nRoadExp)
    {
        oPlace = oplace;
        name = nName;
        EGN = nEGN;
        roadExp = nRoadExp;
    }
};

class Hotel
{
private:
    string hName;
    string roomN;
    float overnightP;

public:
    Hotel()
    {
        hName = '?';
        roomN = '?';
        overnightP = 0;
    }

    void getData()
    {
        cout << "\nHotel name: ";
        getline(cin, hName);
        cout << "Room number: ";
        getline(cin, roomN);
        cout << "Price for a night: ";
        cin >> overnightP;
        cin.ignore();
    }
    void displayData()
    {
        cout << "\nHotel name: " << hName;
        cout << "\nRoom number: " << roomN;
        cout << "\nPrice for a night: " << overnightP;
        cout << endl;
    }
    string returnHName()
    {
        return hName;
    }
    float returnOvernightP()
    {
        return overnightP;
    }
};

class DelegateCard : public Delegate, public Hotel
{
private:
    string delegateNum;
    CDate Dates;

public:
    void getData()
    {
        cout << "\nDelegate number: ";
        getline(cin, delegateNum);
        while (true)
        {
            if (delegateNum.size() != 6)
            {
                cout << "Wrong input!";
                cout << "\nDelegate number: ";
                getline(cin, delegateNum);
            }
            else
                break;
        }

        cout << "Date of arrival";
        Dates.getArrDate();
        cout << "Date of departure";
        Dates.getDepDate();

        Delegate::getData();
        Hotel::getData();
    }
    void displayData()
    {
        cout << "\nDelegate number: " << delegateNum;
        cout << "\nDate of arrival: ";
        Dates.displayArrDate();
        cout << "\nDate of departure: ";
        Dates.displayDepDate();
        Delegate::displayData();
        Hotel::displayData();
    }

    bool checkHotel(string input)
    {
        if (input == returnHName())
        {
            return true;
        }
        else
            return false;
    }

    bool checkOPlace(string input)
    {
        if (input == returnOPlace())
        {
            return true;
        }
        else
            return false;
    }
    void calculateSum()
    {
        int days;
        days = Dates.returnDays();
        cout << "\nName: " << returnName();
        cout << "\nBill: " << days * returnOvernightP();
    }

    bool isMale()
    {
        if ((stoi(returnEGN().substr(8, 1))) % 2 == 0)
        {
            return true;
        }
        else
            return false;
    }

    int returnDays()
    {
        return Dates.returnEarlyDays();
    }

    void displayNameHotel()
    {
        cout << "\nName: " << Delegate::returnName();
        Hotel::displayData();
    }
};

int main()
{
    string input;
    bool check = true;
    DelegateCard delegates[100];
    Delegate newDelegates[100];
    int delegateNum = 0, newDelegateNum = 0;
    int earDel[2]{0, INT_MAX};
    bool check2 = true;
    bool check3 = true;
    bool check4 = true;

    cout << "\nWrite s to stop the program";

    while (check)
    {

        cout << "\n\n---->MENU<----\n";
        cout << "\n1. Add a delegate";
        cout << "\n2. Display all delegates";
        cout << "\n3. Calculate bill for delegates from the same place of origin";
        cout << "\n4. Display name of earliest male delegate";
        cout << "\n5. Save info of delegates from place of origin";
        cout << "\n6. Display info of delegates from place of origin";
        cout << "\n->";
        getline(cin, input);

        switch (input[0])
        {
        case '1':
            delegates[delegateNum++].getData();

            break;
        case '2':
            for (int i = 0; i < delegateNum; i++)
            {
                delegates[i].displayData();
            }

            break;
        case '3':

            cout << "\nName of hotel: ";
            getline(cin, input);
            for (int i = 0; i < delegateNum; i++)
            {

                string input2;
                if (delegates[i].checkHotel(input))
                {
                    check4 = false;
                    cout << "\nPlace of origin: ";
                    getline(cin, input2);
                    for (int j = 0; j < delegateNum; j++)
                    {

                        if (delegates[j].checkOPlace(input2))
                        {
                            check3 = false;
                            delegates[j].calculateSum();
                        }
                    }
                    break;
                }
            }
            if (check4)
            {
                cerr << "\nNo such Hotel was found!";
            }

            if (check3 && !check4)
            {
                cerr << "\nNo delegates from this place!";
            }
            check3 = true;
            check4 = true;

            break;
        case '4':

            for (int i = 0; i < delegateNum; i++)
            {
                if (delegates[i].isMale())
                {
                    if (earDel[1] > delegates[i].returnDays())
                    {
                        earDel[1] = delegates[i].returnDays();
                        earDel[0] = i;
                    }
                }
            }
            delegates[earDel[0]].displayNameHotel();

            break;

        case '5':
            // masiwyt ne iztriva starite danni ako se izvika wtori pyt
            // ako ne wi hareswa taka premahmete "//" ot dolniq komentar
            //  newDelegateNum = 0;
            cout << "\nName of place of origin: ";
            getline(cin, input);
            for (int i = 0; i < delegateNum; i++)
            {
                if (delegates[i].checkOPlace(input))
                {
                    check2 = false;
                    newDelegates[newDelegateNum++] = delegates[i];
                }
            }
            if (check2)
            {
                cerr << "\nNo such place of origin found!";
            }
            else
                cout << "\nDONE!";
            check2 = true;

            break;
        case '6':
            for (int i = 0; i < newDelegateNum; i++)
            {
                newDelegates[i].displayData();
                cout << endl;
            }
            break;

        case 's':
            check = false;
            break;

        default:
            cerr << "\nWrong input!";
            break;
        }
    }

    return 0;
}
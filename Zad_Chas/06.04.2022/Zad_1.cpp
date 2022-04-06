/*
Zadacha 1:
Da se sazdade klas CPerson, sadarzhasht slednite chlenove:
-	ime;
-	EGN;
-	konstruktori – bez argumenti i s vhodni argumenti za vsichki danni;
-	chlen-funktsii getData i display.
Da se sazdade proizvoden klas CStudent, koyto sadarzha:
-	fakulteten nomer;
-	otsenki po 5 distsiplini;
-	konstruktori (s izvikvane na konstruktor na bazoviya klas);
-	chlen-funktsii getData i display;
-	chlen-funktsiya za izchislyavane na sreden uspeh.
Da se sazdade klas-konteyner CGroup, koyto sahranyava dannite za grupa studenti, s chlen-funktsii:
-	za dobavyane na nov student;
-	za namirane na sredniya uspeh na grupata.

Da se sastavi programa, koyato chrez menyu, upravlyava edin obekt ot klas CGroup.

Zadacha 2:
-	da se dobavi i broy otsenki k (k<=10) na edin student;
-	v CStudent da se dobavi chlen-funktsiya, koyato proveryava dali studenta ima pone edna 2-ka;
-	v CGroup da se dobavi funktsiya, koyato izvezhda dannite na studentite s dvoyki.


*/
#include <iostream>
#include <string>

using namespace std;

class CPersone
{
private:
    string name;
    string EGN;

public:
    CPersone()
    {
    }

    CPersone(string a, string b)
    {
        name = a;
        EGN = b;
    }

    void getData()
    {
        cout << "Name: ";
        getline(cin, name);
        cout << "EGN: ";
        getline(cin, EGN);
    }
    void displayData()
    {
        cout << "\nName: " << name << endl;
        cout << "EGN: " << EGN << endl;
    }
};

class CStudent
{
private:
    CPersone persone;
    string FakNom;
    float marks[10];
    int numMarks = 0;

public:
    CStudent()
    {
    }
    CStudent(string a, float b[])
    {
        FakNom = a;
        for (int i = 0; i < 10; i++)
        {
            marks[i] = b[i];
        }
    }

    void getData()
    {
        persone.getData();
        cout << "\nFakNom: ";
        getline(cin, FakNom);
        while (true)
        {
            cout << "Number of marks: ";
            cin >> numMarks;
            if (numMarks <= 10)
            {
                break;
            }
            else
                cerr << "Wrong Input!!!";
        }
        cout << "Marks: \n";

        for (int i = 0; i < numMarks; i++)
        {
            cout << i + 1 << ": ";
            cin >> marks[i];
        }
        cin.ignore();
    }
    void displayData()
    {
        persone.displayData();
        cout << "\nFakNom: " << FakNom << endl;
        cout << "Marks: \n";
        for (int i = 0; i < numMarks; i++)
        {
            cout << i + 1 << ": " << marks[i] << endl;
        }
    }

    int avgMarks()
    {
        float avg = 0;
        for (int i = 0; i < numMarks; i++)
        {
            avg += marks[i];
        }
        return (avg / numMarks);
    }
    bool badMarks()
    {
        bool check = false;
        for (int i = 0; i < numMarks; i++)
        {
            if (marks[i] <= 2)
            {
                check = true;
            }
        }
        return check;
    }
};

class CGroup
{
private:
    CStudent student[100];
    int studnum = 0;

public:
    CGroup()
    {
    }

    void getData()
    {

        student[studnum++].getData();
    }
    void displayData()
    {
        for (int i = 0; i < studnum; i++)
        {
            cout << "\nStudent " << i + 1 << ": \n";
            student[i].displayData();
        }
    }

    void avgGroupMark()
    {
        float avg = 0;
        for (int i = 0; i < studnum; i++)
        {
            avg += student[i].avgMarks();
        }
        cout << "\nAverage group mark: " << (avg / studnum) << endl;
        ;
    }
    void displayStudBadMarks()
    {
        for (int i = 0; i, studnum; i++)
        {
            if (student[i].badMarks())
            {
                student[i].displayData();
            }
        }
    }
};

int main()
{
    CGroup group;
    bool check = true;
    int input;

    while (check)
    {
        cout << "\n<--Menu-->\n";
        cout << "1. Add Student\n";
        cout << "2. Display student group\n";
        cout << "3. Display group avg mark\n";
        cout << "4. Display students with bad marks\n";
        cout << "--> ";
        cin >> input;
        cin.ignore();

        switch (input)
        {
        case 1:
            group.getData();

            break;
        case 2:
            group.displayData();

            break;
        case 3:
            group.avgGroupMark();

            break;
        case 4:
            group.displayStudBadMarks();

            break;
        case 66:
            check = false;

            break;
        default:
            cerr << "\nWrong input!\n";
        }
    }

    return 0;
}
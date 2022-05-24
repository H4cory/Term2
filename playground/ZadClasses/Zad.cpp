/*
Do uchastiye v natsionalna olimpiada po programirane se dopuskat studenti
(ime, YEGN, universitet, fakultet, spetsialnost, s"brani tochki) i uchenitsi
(ime, YEGN, uchilishche, klas, s"brani tochki). Dannite za vsichki uchastnitsi se
s"khranyavat v yedin masiv.
Da se s"stavi programa, koyato izp"lnyava ot menyu slednite operatsii:
- dobavya k"m masiva dannite na poreden uchastnik;
- izvezhda vsichki v"vedeni danni;
- izvezhda dannite na uchastnika s nay-mnogo tochki;
- syzdava masiv s dannite na vsichki uchastnichki s poveche ot 30 tochki.
*/

#include "cPersone.h"
#include <iostream>
#include <string>

using namespace std;

void displayWinner(cPersone parti[], int partiNum)
{
    int compare = INT_MIN, position = 0;

    for (int i = 0; i < partiNum; i++)
    {
        if (compare < parti[i].returnPoints())
        {
            position = i;
            compare = parti[i].returnPoints();
        }
    }
    parti[position].displayData();
}

int main()
{
    cPersone parti[20];
    cPersone newParti[20];
    int partiNum = 0, nPartiNum = 0;
    bool check = true;
    string input;

    cout << "\nPress s to stop\n";

    while (check)
    {
        cout << "\n\n1.Add a student.";
        cout << "\n2.Add a undergraduate.";
        cout << "\n3.Display data.";
        cout << "\n4.Display participant with highest score.";
        cout << "\n5.Save female participants with score over 30.";
        cout << "\n6.Display saved female participants.";
        cout << "\n-->";
        getline(cin, input);

        switch (input[0])
        {
        case '1':
            parti[partiNum++].getData(1);
            break;
        case '2':
            parti[partiNum++].getData(2);
            break;
        case '3':
            for (int i = 0; i < partiNum; i++)
            {
                parti[i].displayData();
                cout << endl;
            }
            break;
        case '4':
            displayWinner(parti, partiNum);
            break;
        case '5':
            nPartiNum = 0;
            for (int i = 0; i < partiNum; i++)
            {

                if (parti[i].checkFemale() && parti[i].returnPoints() >= 30)
                {
                    newParti[nPartiNum++] = parti[i];
                }
            }
            cout << "\nDone!";
            break;
        case '6':
            for (int i = 0; i < nPartiNum; i++)
            {
                newParti[i].displayData();
                cout << endl;
            }
            break;
        case 's':
            check = false;
            break;

        default:
            cerr << "\nWrong input!\n";
            break;
        }
    }

    return 0;
}
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







int main(){
    string input;
    array<bool, 10> check;
    check.fill(true);

    cout<< "\nPress s to stop\n";

    while (check[0])
    {
        cout<<"\n<----MENU---->\n";
        cout<<"\nSmt";
        cout<<"\nSmt";
        cout<<"\nSmt";
        cout<<"\nSmt";
        cout<<"\n-->";
        getline(cin, input);

        switch(input[0]){
            case '1':

            break;
            case '2':
            
            break;
            case '3':
            
            break;
            case '4':
            
            break;
            case 's':
            check[0]=false;
            
            break;
            default:
            cerr<<"\nWrong input!";
        }

       
    }
    
 
   return 0;
}
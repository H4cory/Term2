/*

*/

#include <iostream>
#include <string>
#include <array>

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
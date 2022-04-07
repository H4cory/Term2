/*
Da se sastavi programa za nuzhdite na proizvodstvena organizatsiya, koyato
sahranyava v masiv slednite danni za rabotnitsite:
-       ime;
-       EGN;
-       razmer na dnevnoto zaplashtane;
-       broy na otraboteni dni prez mesetsa;
i izvarshva slednite operatsii, izbirani ot menyu:
-       dobavya kam masiva dannite na nov rabotnik;
-       izvezhda vsichki vavedeni danni;
-       izvezhda imenata na mazhete  zaplashtane ot otraboteni dni nad 400lv;
-       sazdava nov masiv s imenata i datite na razhdane na zhenite s dnevno
zaplashtane pod 20 lv.

*/
#include <iostream>
#include <string>
using namespace std;

class Workers{
    private:
    string name;
    string EGN;
    float salary;
    int wDays;


    public:

        Workers(){

        }

        void getData(){
            cout<<"\nName: ";getline(cin, name);
            cout<<"EGN: ";getline(cin, EGN);
            cout<<"Salary: ";cin>>salary;
            cout<<"Days worked: ";cin>>wDays;
            cin.ignore();
        }
        void displayData(){
            cout<<"\nName: "<<name<<endl;
            cout<<"\nEGN: "<<EGN<<endl;
            cout<<"\nSalary: "<<salary<<endl;
            cout<<"\nDays worked: "<<wDays<<endl;
        }
        void displayMaleSlary(){
             if( (stoi(EGN.substr(8,1)))%2 == 0&&salary*wDays >=400){
                 cout<<"\nName: "<<name;
             } 
        }



};

class nDate{
    private:
    string name;
    string date;

    public:

};


int main(){
    Workers persone[100];
    bool check = true;
    int input= 0 , numP =0;

    while(check){
        cout<<"\n<--MENU-->\n";
        cout<<"1.Add worker\n";
        cout<<"2.Display worker\n";
        cout<<"3.Display name of workers with salary over 400lv\n";
        cout<<"4.Display and save womens name + bDate with d salary under 20lv\n";
        cout<<"--> ";
        cin>>input; cin.ignore();

        switch(input){
            case 1:
                persone[numP++].getData();

            break;

            case 2:
            for(int i =0;i<numP;i++){
                cout<<"\nWorker "<<i+1<<" :\n";
                persone[i].displayData();
            }

            break;

            case 3:
            for(int i =0;i<numP;i++){
                persone[i].displayMaleSlary();
            }

            break;

             case 4:


            break;

            case 66:
            check = false;

            break;
            default:
            cerr<<"\nWrong Input!!!\n";

        }
    }
 
   return 0;
}
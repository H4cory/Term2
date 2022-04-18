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
-       izvezhda imenata na mazhete s zaplashtane ot otraboteni dni nad 400lv;
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
            name = '?';
            EGN = '?';
            salary = 0;
            wDays = 0;
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
                 if(wDays*salary>400){
                     cout<<"\nName: "<<name;
                 }
             } 
        }
        
        bool sortWomen(){
            if( (stoi(EGN.substr(8,1)))%2 != 0&&salary <=20){
                     return true;
             } 
             
             else 
             return false;
             
        }
        
        string returnName(){
            return name;
        }
        
        void getBDate(){
            int D, M, Y;
            if((stoi(EGN.substr(2,2)))> 12){
                M =(stoi(EGN.substr(2,2)))-40;
                Y = (stoi(EGN.substr(0,2))) +2000;
            }
            else {
            M =(stoi(EGN.substr(2,2)));
            Y = (stoi(EGN.substr(0,2))) +1900;
            }
            D = stoi(EGN.substr(4,2));
        
        }



};



class nDate{
    private:
    string name;
    int D,M,Y;

    public:
    nDate(){
        
    }
    void getName(string a){
        name = a;
    }
    
    friend class Workers;
    
    void displayData(){
        cout<<"\nName: "<<name;
        cout<<"\n"<<D<<'.'<<M<<'.'<<Y;
    }
};

int main(){
    Workers persone[100];
    nDate women[100];
    bool check = true;
    int numP =0,numW = 0;
    string input;
    
    cout<<"\nPress s to stop\n";

    while(check){
        cout<<"\n<--MENU-->\n";
        cout<<"1.Add worker\n";
        cout<<"2.Display worker\n";
        cout<<"3.Display name of workers with salary over 400lv\n";
        cout<<"4.Save womens name + bDate with d salary under 20lv\n";
        cout<<"5.Display saved womens name + bDate with d salary under 20lv\n";
        cout<<"--> ";
        getline(cin, input);

        switch(input[0]){
            case '1':
                persone[numP++].getData();

            break;

            case '2':
            for(int i =0;i<numP;i++){
                cout<<"\nWorker "<<i+1<<" :\n";
                persone[i].displayData();
            }

            break;

            case '3':
            for(int i =0;i<numP;i++){
                persone[i].displayMaleSlary();
            }

            break;

             case '4':
             for(int i =0;i<numP;i++){
                if(persone[i].sortWomen()){
                    women[numW++].getName(persone[i].returnName());
                    persone[i].getBDate();
                }
            }
            break;
            
            case '5':
            for(int i =0;i<numW;i++){
                women[i].displayData();
            }
            
            break;

            case 's':
            check = false;

            break;
            default:
            cerr<<"\nWrong Input!!!\n";

        }
    }
 
   return 0;
}

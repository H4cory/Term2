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

class CDate{
    private:
    int D, M,Y;

    public:
    CDate(){
        D = 0;
        M=0;
        Y=0;
    }

    void getDate(){
        cout<<"\nDay: ";
        cin>>D;
        cout<<"Month: ";
        cin>>M;
        cout<<"Year: ";
        cin>>Y;
        cin.ignore();
    }
    void displayDate(){
        cout<<D<<'.'<<M<<'.'<<Y<<" y.";
    }
};




class Delegate{
    private:
    string name;
    string EGN;
    string oPlace;
    float roadExp;



    public:
    Delegate(){
        roadExp = 0;
        name='?';
        EGN='?';
        oPlace='?';
    }
    void getData(){
        cout<<"\nName: ";getline(cin,name);
        cout<<"EGN:";getline(cin,EGN);
        cout<<"Place of origin: ";getline(cin,oPlace);
        cout<<"Road expenses: ";cin>>roadExp;cin.ignore();

    }

    void displayData(){
        cout<<"\nName: "<<name;
        cout<<"\nEGN: "<<EGN;
        cout<<"\nPlace of origin: "<<oPlace;
        cout<<"\nRoad expenses: "<<roadExp;
    }

};

class Hotel {
    private:
    string hName;
    string roomN;
    float overnightP;

    public:
    Hotel(){
        hName = '?';
        roomN= '?';
        overnightP = 0;
    }

    void getData(){
        cout<<"\nHotel name: ";getline(cin,hName);
        cout<<"Room number: ";getline(cin,roomN);
        cout<<"Price for a night: ";cin>>overnightP;cin.ignore();
    }
    void displayData(){
        cout<<"\nHotel name: "<<hName;
        cout<<"\nRoom number: "<<roomN;
        cout<<"\nPrice for a night: "<<overnightP;
    }

};

class DelegateCard: public Delegate, public Hotel{
    private:
    string delegateNum;
    CDate arrDate;
    CDate depDate;

    public:
    void getData(){
        cout<<"\nDelegate number: ";getline(cin,delegateNum);
        while(true){
            if(delegateNum.size()!=6){
                cout<<"Wrong input!";
                cout<<"\nDelegate number: ";getline(cin,delegateNum);
            }
            else
            break;
        }
       
        cout<<"Date of arrival";arrDate.getDate();
        cout<<"Date of departure";depDate.getDate();

        Delegate::getData();
        Hotel::getData();
    }
    void displayData(){
        cout<<"\nDelegate number: "<<delegateNum;
        cout<<"\nDate of arrival: ";arrDate.displayDate();
        cout<<"\nDate of departure: ";depDate.displayDate();
        Delegate::displayData();
        Hotel::displayData();
    }
};












int main(){
    string input;
    bool check=true;
    DelegateCard delegates[100];
    int delegateNum = 0;

    while(check){
        cout<<"\n\n1. Add a delegate";
        cout<<"\n2. Display all delegates";

        cout<<"\n->";
        getline(cin,input);

        switch (input[0])
        {
        case '1':
            delegates[delegateNum++].getData();
            
            break;
         case '2':
         for(int i =0;i<delegateNum;i++){
             delegates[i].displayData();
         }
            
            break;
         case '3':
            
            break;
         case '4':
            
            break;


        case 's':
            check = false;
            break;
        
        default:
            cerr<<"\nWrong input!";
            break;
        }
    }
 
   return 0;
}
/*
1.	Zadacha:
Da se sastavi programa, koyato sas sahranyavanite v masiv danni za grupa studenti:
-	ime
-	EGN
-	otsenki po 5 distsiplini – tseli chisla;
-	kurs  - tsyalo chislo,

Da se dobavyat: 
-	dve chlen funktsii getData i display -> saotvetno za vavezhdane i izvezhdane na danni.
-	dva konstruktora – bez parametri (podrazbirasht se konstruktor) i konstruktor s parametri za initsializirane na vsichki danni za studenta.

-	Statichna chlen-promenliva count – broy na sazdadenite obekti, koyato v konstruktorite se uvelichava s edinitsa, a v destrutora se namalyava.


2.	Zadacha – da se sastavyat:
-	chlen-funktsiya za namirane datata na razhdane na studenta;
-	chlen-funktsiya za namirane vazrastta na studenta;
-	chlen-funktsiya za namirane pola na studenta;
-	chlen-funktsiya za izchislyavane uspeha na studenta;
-	saotvetna testvashta programa.

*/
#include <iostream>
#include <string>

using namespace std;
class bDate{
    public:
    int D, M, Y;
    void setData(){
        cout<<"Day: ";cin>>D;
        cout<<"Month: ";cin>>M;
        cout<<"Year: ";cin>>Y;
    }
    void display(){cout<<endl<<D<<"/"<<M<<"/"<<Y<<endl;}
};
class Students{
    private:
    string name;
    string EGN;
    int marks[5];
    int term;
    int count =0;
    public:
    void getData();
    void displayData();
    bDate getBirthday();
    void getAge(bDate currentDate);
    void getGender();
    void getAvgMarks();


    Students(){
        count++;
    }
    ~Students(){
        count--;
    }

};


void Students::getData(){
    cout<<"Name: "; getline(cin, name);
    cout<<"EGN: "; getline(cin, EGN);
    cout<<"Term: "; cin>>term;
    for(int i = 0;i<5;i++){
        cout<<"Mark "<<i+1<<" : ";
        cin>>marks[i];
    }
}
void Students::displayData(){
    cout<<"Name: "<<name<<endl;
    cout<<"EGN: "<<EGN<<endl;
    cout<<"Term: "<<term<<endl;
     for(int i = 0;i<5;i++){
        cout<<"Mark "<<i+1<<" : "<< marks[i]<<endl;
    }

}
bDate Students::getBirthday(){
    bDate birth;
 if((stoi(EGN.substr(2,2)))> 12){
     birth.M =(stoi(EGN.substr(2,2)))-40;
     birth.Y = (stoi(EGN.substr(0,2))) +2000;
 }
 else {
     birth.M =(stoi(EGN.substr(2,2)));
     birth.Y = (stoi(EGN.substr(0,2))) +1900;
 }
 birth.D = stoi(EGN.substr(4,2));

 return birth;
 
} 


void Students::getAge(bDate currentDate){
 
 bDate birth;
 
 if((stoi(EGN.substr(2,2)))> 12){
     birth.M =(stoi(EGN.substr(2,2)))-40;
     birth.Y = (stoi(EGN.substr(0,2))) +2000;
 }
 else {
     birth.M =(stoi(EGN.substr(2,2)));
     birth.Y = (stoi(EGN.substr(0,2))) +1900;
 }
 birth.D = stoi(EGN.substr(4,2));
 
int ages;
 if(birth.M<currentDate.M) cout<<"Age: "<<currentDate.Y - birth.Y<<endl;
 else if(birth.M == currentDate.M &&birth.D < currentDate.D) cout<<"Age: "<<currentDate.Y - birth.Y<<endl;
 else cout<<"Age: "<<(currentDate.Y - birth.Y)-1<<endl;
}


void Students::getGender(){
    if( (stoi(EGN.substr(8,1)))%2 == 0){
        cout<<"Male"<<endl;
    }
    else cout<<"Female"<<endl;
}

void Students::getAvgMarks(){
    int sum =0;
    for(int i = 0;i<5;i++)
        sum+=marks[i];
    cout<<"Average mark: "<<sum/5;

}


int main(){
    Students persone[100];
    int input, studNum = 0;
    bool run = true;
    bDate currentDate;
    while(run){
    cout<<endl<<"1. GetData"<<endl;
    cout<<"2. DisplayData"<<endl;
    cout<<"3. DisplayBithday"<<endl;
    cout<<"4. DisplayAge"<<endl;
    cout<<"5. DisplayGender"<<endl;
    cout<<"6. DisplayAverageMarks"<<endl;

    cout<<"> ";
    cin>>input;cin.ignore();

    switch (input){
        case 1:
        persone[studNum++].getData();
        break;

        case 2:
        for(int i =0;i<studNum;i++){
            persone[i].displayData();
        }
        break;
        case 3:
            cout<<"Student: "; cin>>input;
            persone[input-1].getBirthday().display();
        
        break;

        case 4:
           cout<<"Student: "; cin>>input;
           currentDate.setData();
           persone[input-1].getAge(currentDate);
           
        break;

        case 5: 
           cout<<"Student: "; cin>>input;
           persone[input-1].getGender();
        break;

        case 6: 
           cout<<"Student: "; cin>>input;
           persone[input-1].getAvgMarks();
        break;


        case 666:
        run = false;
        break;

        default: cerr<<"Bad input"<<endl;

    }


}

    return 0;
}
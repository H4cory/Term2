/*
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

class CPersone{
    private:
    string name, EGN;
    public:
    CPersone(): name(""), EGN(""){    
    }
    CPersone(string name, string EGN): name(name), EGN(EGN){
    }
    void getData();
    void displayData();

};

class CStudent: public CPersone{
    private: 
    string FacN;
    float marks[50];
    float avg;
    int marksCounter;

    public:
    CStudent(): CPersone(), FacN(""), marks{0}, avg(0), marksCounter(0){
       
    }
    CStudent(string name, string EGN, string FacN, int marks, int sum){

    }
    void getData();
    void displayData();
    void avgMarks();
    int checkMarks();


};

void CPersone::getData(){
    cout<<"Name: ";getline(cin, name);
    cout<<"EGN: ";getline(cin, EGN);
}
void CPersone::displayData(){
    cout<<"Name: "<<name<<endl;
    cout<<"EGN: "<<EGN<<endl;
}

void CStudent::getData(){
    CPersone::getData();
    cout<<"FacN: ";getline(cin, FacN);
    cout<<"How much marks: ";cin>>marksCounter;
    for(int i=0;i<marksCounter;i++){
        cout<<"Mark "<<i+1<<':';
        cin>>marks[i];
        avg+=marks[i];
    }
    avg/=5;
    cin.ignore();
}

void CStudent::displayData(){
    CPersone::displayData();
    cout<<"FacN: "<<FacN<<endl;
    for(int i =0;i<marksCounter;i++){
        cout<<"Mark "<<i+1<<": "<<marks[i]<<endl;
    }
    cout<<"\n";
}

void CStudent::avgMarks(){
    cout<<"Average: "<<avg<<endl;
}

int CStudent::checkMarks(){
    for(int i =0;i<marksCounter;i++){
        if(marks[i]<=2){
            return true;
            break;
        }
        else
        return false;
    }
}




int main(){
    CStudent students[20];
    int input,studentNum = 0;
    bool check = true;


    while(check){
        cout<<"\n1. New Student\n";
        cout<<"2. Display all students\n";
        cout<<"3. Average mark\n";
        cout<<"4. Check for bad mark\n";
        cout<<"5. Display students with bad marks\n";
        cout<<"-> ";
        cin>>input; cin.ignore();
        switch(input){
            case 1:
            students[studentNum++].getData();
               
            break;
            case 2:
            for(int i =0;i<studentNum;i++){
                cout<<"\nStudent "<<i+1<<": \n";
                students[i].displayData();
            }

            break;
            case 3:
            cout<<"Student number: ";
            cin>>input;cin.ignore();
            students[input-1].avgMarks();

            break;
            case 4:
            cout<<"Student number: ";
            cin>>input;cin.ignore();
            if(students[input-1].checkMarks())
             cout<<"The student has a bad mark!\n";
            else
             cout<<"The student does not have a bad mark!\n";

            break;
            case 5:
            for(int i =0;studentNum>i;i++){
                if(students[i].checkMarks())
                 students[i].displayData();   
            }

            break;
            case 55:
            check = false;
            break;
            default:
            cerr<<"Wrong inmput"<<endl;
        }

    }


    return 0;
}
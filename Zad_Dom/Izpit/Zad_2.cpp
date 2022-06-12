/*
2. Universitet poddarzha informatsiya za publikatsiite na prepodavateli, studenti i doktoranti. 
Vsyaka publikatsiya ima zaglavie, avtor i godina na izdavane.
Publikatsiite mogat da sa:
statiya v spisanie - podarzha se informatsiya za ime na spisanieto,
poreden nomer (broy) i stranitsi; doklad v konferentsiya - poddarzha se informatsiya za ime na konferentsiyata,
myasto na izdavane, izdatel i stranitsi.
Da se sazdade informatsionna sistema, koyato:
- pozvolyava v obshta dannova struktura da se dobavyat publikatsii ot dvata opisani vida (polimorfizam); 
- izvezhda obsht spisak na vavedenite publikatsi;
- po zadaden spisak ot avtori da se opredelya broya na statiite i broyat na dokladite na tezi avtori (tarsi se
tochno savpadenie na vavedeniya string sas spisaka ot avtori na publikatsiyata).
*/

#include <iostream>
#include <string>

using namespace std;

//Abstract ---------------------------------------------------------------------------------------------- Abstract
class Abstract{
virtual void getData() = 0;
virtual void displayData() = 0;
virtual bool isMag() = 0;
virtual bool isRep() = 0;

};

//Publications ---------------------------------------------------------------------------------------------Publications
class Publications: public Abstract{
private:
string name;
string header;
string writer;
string year;
int pages;


public:
Publications():name("?"),header("?"),writer("?"),year("?"),pages(0){

}

void getData(){
cout<<"\nName :";
getline(cin, name );
cout<<"\nHeader :";
getline(cin, header);
cout<<"\nWriter :";
getline(cin, writer);
cout<<"\nYear :";
getline(cin, year);
cout<<"\nPages :";
cin>>pages;
cin.ignore();
}

void displayData(){
cout<<"\nName: "<< name <<endl;
cout<<"Header: "<< header<<endl;
cout<<"Writer: "<< writer<<endl;
cout<<"Year: "<< year <<endl;
cout<<"Pages: "<< pages <<endl;

}

bool checkAuthor(string input){
if(input == writer){
return true;
}
else{
return false;
}

}

bool isMag(){
return false;
}
bool isRep(){
return false;
}

};

//Mag --------------------------------------------------------------------------------------------- Mag
class Mag: public Publications{
private:
string num;

public:
Mag():num("?"){
}

void getData(){
Publications::getData();
cout<<"Mag num: ";
getline(cin,num);
}

void displayData(){
Publications::displayData();
cout<<"Mag num: "<<num<<endl;
}
bool isMag(){
return true;
}
bool isRep(){
return false;
}

};

//Rep --------------------------------------------------------------------------------------------- Rep
class Rep: public Publications{

private:
string publishPlace;
string publisher;
public:
Rep():publishPlace("?"),publisher("?"){
}

void getData(){
Publications::getData();
cout<<"Publish place: ";
getline(cin,publishPlace);
cout<<"Publisher: ";
getline(cin,publisher);
}

void displayData(){
Publications::displayData();
cout<<"Publish place: "<<publishPlace<<endl;
cout<<"Publisher: "<<publisher<<endl;
}
bool isMag(){
return false;
}
bool isRep(){
return true;
}
};

//main ------------------------------------------------------------------ main
int main(){
string input;
bool check = true;
Publications* pub[100];
int authorsC = 0, magC = 0, repC=0;

int pubC = 0;



cout<<"\nPress s to stop.\n";

while(check){

cout<<"\n1.Get data.";
cout<<"\n2.Display data.";
cout<<"\n3.Display number of mag. and pub.";
cout<<"\n->";
getline(cin,input);

switch(input[0]){


case '1':
cout<<"\n1.Mag\n1.Rep\n->";
getline(cin,input);
if(input[0]=='1'){
pub[pubC] = new Mag;
pub[pubC++]->getData();
}
else if(input[0]=='2'){
pub[pubC] = new Rep;
pub[pubC++]->getData();
}
else
cout<<"\nWrong input!";

break;



case '2':
for(int i =0;i<pubC;i++){
pub[i]->displayData();
}
break;

case '3':
cout<<"\nHow many authors: ";
cin>>authorsC;
cin.ignore();
for(int i =0;i<authorsC;i++){
getline(cin,input);
for(int j = 0;j<pubC;j++){
if(pub[j]->checkAuthor(input)&&pub[j]->isMag()){
magC++;
}
if(pub[j]->checkAuthor(input)&&pub[j]->isRep()){
repC++;
}
}

cout<<"\nAuthor: "<<input<<" has "<<magC<<" mag. and "<<repC<<" rep.";
magC=0;
repC=0;
}

break;

case 's':
check = false;
break;


default:
cout<<"\nWrong input!";
break;

}

}



system("pause");
return 0;
}

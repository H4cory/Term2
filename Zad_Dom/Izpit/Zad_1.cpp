/*
1. Da se sastavi klas, koyto opisva informatsiya za tableti:
Marka:
razmera na ekrana v inchove:
tsena:
Klasat tryabva da vklyuchva: konstruktor bez argumenti;
konstruktor, initsializirasht vsichki chlen-danni na klasa; chlen-funktsiite za vavezhdane i 
izvezhdane na dannite za edin tayablet.
chlen-funktsiya, koyato proveryava dali razmerat na ekrana e po-malak ot zadadena stoynost.
Da se napishe programa, koyato: - vavezhda v masiv danni za i tableta (ne poveche ot 50 elementa);
izvezhda spisak s tabletite, koyto sa s razmer na ekrana po-malka ot 8 incha.

*/


#include <iostream>
#include <string>

using namespace std;


class Tablets{
private:
string model;
float size;
float price;


public:

Tablets(){
}
Tablets(string a, float b, float c){
model =a;
size = b;
price = c;
}

void getData(){
cout<<"\nModel: ";
getline(cin,model);
cout<<"Size: ";
cin>>size;
cout<<"Price: ";
cin>>price;
cin.ignore();
}

void displayData(){
cout<<"\nModel: "<<model;
cout<<"\nSize: "<<size;
cout<<"\nPrice: "<<price;
}

bool checkSize(float input){
if(input > size ){
return true;
}
else{
return false;
}

}


};

//main ------------------------------------------------------------------
int main(){
string input;
bool check = true;
Tablets tablet[50];
int tabC = 0;
float size;

cout<<"\nPress s to stopn\n";
while(check){

cout<<"\n1.Get data";
cout<<"\n2.Display data";
cout<<"\n3.Compare inches";
cout<<"\n4.Display under 8 inches";
cout<<"\n->";
getline(cin,input);

switch(input[0]){
case '1':
tablet[tabC++].getData();
break;
case '2':
for(int i = 0 ;i<tabC;i++){
cout<<endl;
tablet[i].displayData();

}
break;

case '3':
cout<<"\nInches: ";
cin>>size;
cin.ignore();
for(int i = 0 ;i<tabC;i++){
if(tablet[i].checkSize(size)){
cout<<endl;
tablet[i].displayData();
}
}

break;

case '4':
for(int i = 0 ;i<tabC;i++){
if(tablet[i].checkSize(8.0)){
cout<<endl;
tablet[i].displayData();
}
}
break;

case 's':
check = false;
break;


default:
cout<<"wrong input!";
break;

}

}



system("pause");
return 0;
}

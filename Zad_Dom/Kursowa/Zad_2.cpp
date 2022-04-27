/*
V gradinski tsentar se prodavat rasteniya (naimenovanie, tsena, broy),
koito bivat darveta (visochina, vid(iglolistni/shirokolistni)) i tsvetya
(tsvyat). Dannite za vsyako rastenie se sahranyava v masiv.
Da se sastavi programa, koyato izpalnyava ot menyu slednite operatsii:
-       dobavya kam masiva dannite na novo rastenie;
-       izvezhda vsichki vavedeni danni;
-       izvezhda rastenieto s nay-visoka tsena;
-       sazdava masiv s naimenovaniyata na chervenite tsvetya.
*/
#include <iostream>
#include <string>
#include <array>

using namespace std;



class CTrees 
{
private:
   string height;
   string type;

   public:

   CTrees():height("?"),type("?"){

   }

   void getData(){
      cout<<"Height: ";
      getline(cin, height);
      cout<<"Type: ";
      getline(cin,type);
   }

   void displayData(){
      cout<<"\nHeight: "<<height;
      cout<<"\nType: "<<type;
   }
};

class CFlowers {
private:
string color;

public:

CFlowers():color("?"){

}

void getData(){
   cout<<"Color: ";
   getline(cin,color);
}

void displayData(){
   cout<<"\nColor: "<<color;
}
};


class CPlants: public CFlowers, public CTrees
{
private:
   string name;
   float price;
   string units;

public:
   CPlants() : name("?"), price(0), units("?")
   {
   }

   void getDataTrees()
   {
      cout << "\nName: ";
      getline(cin, name);
      cout << "Price: ";
      cin >> price;
      cin.ignore();
      cout << "Units: ";
      getline(cin, units);
      CTrees::getData();
   }
   void getDataFlowers()
   {
      cout << "\nName: ";
      getline(cin, name);
      cout << "Price: ";
      cin >> price;
      cin.ignore();
      cout << "Units: ";
      getline(cin, units);
      CFlowers::getData();
   }

   void displayDataTrees()
   {
      cout << "\nName: " << name;
      cout << "\nPrice: " << price;
      cout << "\nUnits: " << units;
      CTrees::displayData();
   }

   void displayDataFlowers()
   {
      cout << "\nName: " << name;
      cout << "\nPrice: " << price;
      cout << "\nUnits: " << units;
      CFlowers::displayData();
   }
};


int main()
{
   CPlants plants[100];
   int numPlants = 0;
   array<bool, 10> check;
   check.fill(true);
   string input;

   cout<<"\nType 's' to stop!\n";

   while(check[0]){
      cout<<"\n<------> MENU <------>\n";
      cout<<"\n1. Add a tree.";
      cout<<"\n2. Add a flower.";
      cout<<"\n3. Display all plants.";
      cout<<"--> ";
      getline(cin,input);

      switch(input[0]){
         case '1':
         plants[numPlants++].getDataTrees();
         break;

         case '2':
         plants[numPlants++].getDataFlowers();
         break;

         case '3':
            for(int i =0;i<numPlants;i++){
               
            }
         break;


         case 's':
            check[0] = false;
         break;
         default:
         cerr<<"\nWrong input!";
         break;
      }
   }

   

   return 0;
}
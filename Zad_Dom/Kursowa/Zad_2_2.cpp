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
#include <climits>

using namespace std;

class Abs{
    
public:
    virtual void getData() = 0;
    virtual void displayData() = 0;
    virtual string returnColor() = 0;
};

class Plants: public Abs{
    private:
    string name;
    float price;
    int units;
    
    public:
    Plants():name("?"),price(0),units(0){
        
    }
    void displayData(){
        cout<<"\nName: "<<name;
        cout<<"\nPrice: "<<price;
        cout<<"\nAvailable units: "<<units;
    }
    void getData(){
        cout<<"\nName: ";
        getline(cin,name);
        cout<<"Price: ";
        cin>>price;
        cout<<"Available units: ";
        cin>>units;
        cin.ignore();
    }
    
    float returnPrice(){
        return price;
    }
    string returnName(){
        return name;
    }
};

class Tree:public Plants{
    private:
    string height;
    string sort;
    
    
    public:
    Tree():height("?"),sort("?"){
        
    }
    void displayData(){
        Plants::displayData();
        cout<<"\nHeight: "<<height;
        cout<<"\nSort: "<<sort<<endl;
        
    }
    void getData(){
        Plants::getData();
        cout<<"Height: ";
        getline(cin,height);
        cout<<"Sort: ";
        getline(cin,sort);
    }
    string returnColor(){
        
    }
    
};

class Flower:public Plants{
    private:
    string color;
    
    public:
    Flower():color("?"){
        
    }
    void displayData(){
        Plants::displayData();
        cout<<"\nColor: "<<color<<endl;
        
        
    }
    void getData(){
        Plants::getData();
        cout<<"Color: ";
        getline(cin,color);
    }
    
     string returnColor(){
        return color;
    }
    
    
    
};

class newFlowers{
    private:
    string name;
    
    public:
    newFlowers():name("?"){
        
    }
    void displayData(){
        cout<<"\nName: "<<name<<endl;
    }
    
    void getName(string input){
        name = input;
    }
};






int main(){
    newFlowers flowers[10];
    Plants* plantT[10];
    Plants* plantF[10];
    int plantTnum = 0, plantFnum = 0, flowerNum=0;
    array<bool, 10> check;
    check.fill(true);
    string input;
    float compare= INT_MIN ;
    int position = 0;
   cout<<"\nType 's' to stop!\n";

   while(check[0]){
      cout<<"\n<------> MENU <------>\n";
      cout<<"\n1. Add a tree.";
      cout<<"\n2. Add a flower.";
      cout<<"\n3. Display all plants.";
      cout<<"\n4. Display most expensive plant.";
      cout<<"\n5. Save name of flowers with the color red.";
      cout<<"\n6. Display names of flowers with the color red.";
      cout<<"\n--> ";
      getline(cin,input);

      switch(input[0]){
         case '1':
         plantT[plantTnum] = new Tree;
         plantT[plantTnum++]->getData();
         break;

         case '2':
         plantF[plantFnum] = new Flower;
         plantF[plantFnum++]->getData();
         break;

         case '3':
         for(int i = 0;i<plantTnum;i++){
             plantT[i]->displayData();
         }
         for(int i = 0;i<plantFnum;i++){
             plantF[i]->displayData();
         }
            
         break;
         
         case '4':
         for(int i = 0 ;i<plantTnum;i++){
             if(compare < plantT[i]->returnPrice()){
             compare = plantT[i]->returnPrice();
             position= i;
             }
         }
         for(int i =0;i<plantFnum;i++){
             if(compare < plantF[i]->returnPrice()){
             compare= plantF[i]->returnPrice();
             position= i;
             check[1]= false;
             }
         }
         if(check[1]){
             plantT[position] -> displayData();
         }
         else{
            plantF[position] -> displayData();
         }
            compare = INT_MIN;
           position = 0;
         break;
         
         case '5':
         for(int i = 0; i < plantFnum;i++){
            if("red" == plantF[i] -> returnColor() ||"Red" == plantF[i] -> returnColor()){
                input = plantF[i] -> returnName();
                flowers[flowerNum++].getName(input);
                
            }
         }
         cout<<"\nDone !";
         break;
         
         case '6':
            for(int i = 0;i<flowerNum;i++){
                flowers[i].displayData();
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

/*
1. Da se sastavi klas CHouse, koyto sahranyava informatsiya za kashti:
-adres, tsena, broy stai;
Klasat tryabva da vklyuchva:
-konstruktor bez argumenti:
-konstruktor, initsializirasht vsichki chlen-danni na klasa;
-chlen-funktsiite za vavezhdane i izvezhdane na dannite za edna kashta. 
-chlen-funktsiya, koyato proveryava dali kashtata e s poveche stai ot zadadena STOYNOST.
Da se napishe programa, koyato:
-vavezhda v masiv danni za nepoveche ot 100 kashti;
-izvezhda spisak s kashtite, koyto sa po-poveche ot 10 stai.
*/

#include <iostream>
#include <string>

using namespace std;

class cHouse{
    private:
    string adress;
    float price;
    int rooms;
    
    
    public:
    cHouse():adress("?"),price(0.0),rooms(0){
        
    }
    cHouse(string adr, float pr, int ro){
        adress = adr;
        price = pr;
        rooms = ro;
    }
    
    void getData(){
        cout<<"\nAdress: ";
        getline(cin,adress);
        cout<<"Price: ";
        cin>>price;
        cout<<"Rooms: ";
        cin>>rooms;
        cin.ignore();
        
    }
    
    void displayData(){
        cout<<"\nAdress: "<<adress;
        cout<<"\nPrice: "<<price;
        cout<<"\nRooms: "<<rooms<<endl;
    }
    
    int returnRooms(){
        return rooms;
    }
    
};

int main(){
    cHouse houses[100];
    cHouse nHouses[100];
    int hCount = 0, nhCount = 0;
    string input;
    bool check = true;
    
    cout<<"\nPress s to stop.\n";
    
    while(check){
        
        cout<<"\n1.Get data.";
        cout<<"\n2.Display Data.";
        cout<<"\n3.Check rooms.";
        cout<<"\n4.Save houses with more than 10 rooms.";
        cout<<"\n5.Display houses with more than 10 rooms.";
        cout<<"\n-> ";
        getline(cin,input);
        
        switch(input[0]){
            case '1':
                houses[hCount++].getData();
            break;
            case '2':
            for(int i =0;i<hCount;i++){
                houses[i].displayData();
            }
            
            break;
            case '3':
                cout<<"\nCount of rooms: ";
                getline(cin,input);
                for(int i =0;i<hCount;i++){
                    if(stoi(input)<houses[i].returnRooms()){
                        houses[i].displayData();
                    }
                }
            break;
            case '4':
            for(int i =0;i<hCount;i++){
                    if(10<houses[i].returnRooms()){
                        nHouses[nhCount++] = houses[i];
                    }
                }
                cout<<"\nDone!";
            
            break;
            case '5':
            for(int i =0;i<nhCount;i++){
                nHouses[i].displayData();
            }
            
            break;
            case 's':
                check = false;
            break;
            default:
            cout<<"\nWrong Input!";
        }
    }
    
    
    
    return 0;
}

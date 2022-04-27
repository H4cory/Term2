/*
Da se definira bazov klas figura - vsyaka figura se harakterizira s tsvyat (string).
Da se definirat klasove – naslednitsi na klasa figura, koito opisvat:
-	triagalnik;
-	pravoagalnik.
Da se sastavi klas, koyto sahranyava v masiv dannite za nyakolko (maksimum 30) figuri
 i izvarshva slednite deystviya:

-	dobavya nova figura: triagalnik ili pravoagalnik;
-	izvezhda dannite za vsichki figuri (vid, tsvyat i razmeri);
-	izvezhda sumata ot perimetrite na vsichki figuri;
-	izvezhda spisak s tsvetovete na vsichki pravoagalnitsi.
Da se sastavi podhodyashta testvashta programa.
*/
#include <iostream>
#include <string>
#include <array>

using namespace std;

class Abstract{

public:
virtual void getData() = 0;
virtual void displayData() = 0;
virtual float returnP() = 0;
};

class Figure:public Abstract{

    private:
    string color;

    public:

    Figure():color{"?"}{

    }

    virtual void getData(){
        cout<<"\nColor: ";
        getline(cin, color);
    }

    virtual void displayData(){
        cout<<"\nColor: "<<color;
    }
    string returnColor(){
        return color;
    }
};

class Triangle:public Figure{
    private:
    float size[3];

    public:
      void getData(){
          Figure::getData();
          for(int i =0;i<3;i++){
              cout<<"Side "<<i+1<<" : ";
              cin>>size[i];
          }
          cin.ignore();
    }

    void displayData(){
        cout<<"\nTriangle: ";
        Figure::displayData();
        for(int i =0;i<3;i++){
        cout<<"\nSide "<<i+1<<" : "<<size[i];
        }
        cout<<endl;
    }
    float returnP(){
        return size[0]+size[1]+size[2];
    }

};


class Rectangle:public Figure{
    private:
    float size[2];

    public:

    void getData(){

        Figure::getData();
          for(int i =0;i<2;i++){
              cout<<"Side "<<i+1<<" : ";
              cin>>size[i];
          }
          cin.ignore();

    }

    void displayData(){
        cout<<"\nRectangle: ";
        Figure::displayData();
        for(int i =0;i<2;i++){
        cout<<"\nSide "<<i+1<<" : "<<size[i];
        }
        cout<<endl;
       

    }
    float returnP(){
        return size[0]*2 + size[1]*2;
    }

};





int main(){
    string input;
    array<bool, 10> check;
    check.fill(true);
    Figure* figureR[30];
    Figure* figureT[30];
    int figureNumR = 0, figureNumT = 0;
    Rectangle rec;
    Triangle tri;
    float sum = 0;
    
    cout<< "\nPress s to stop\n";

    while (check[0])
    {
        cout<<"\n<----MENU---->\n";
        cout<<"\n1.Get data";
        cout<<"\n2.Display data";
        cout<<"\n3.Get sum of all figures";
        cout<<"\n4.Get color of al rectangles";
        cout<<"\n-->";
        getline(cin, input);

        switch(input[0]){
            case '1':
                cout<<"\nChose a figure (t/r): ";
                getline(cin,input);
                if(input[0]=='t'||input[0]=='T'){
                    figureT[figureNumT] = new Triangle;
                    figureT[figureNumT++]->getData();
                }
                else if(input[0]=='r'||input[0]=='R'){
                    figureR[figureNumR] = new Rectangle;
                    figureR[figureNumR++]->getData();
                }
                else
                cerr<<"\nWrong input!";


            break;
            case '2':
            for(int i =0;i<figureNumR;i++){
                figureR[i]->displayData();
            }
            for(int i =0;i<figureNumT;i++){
                figureT[i]->displayData();
            }
            
            break;

            case '3':
            
            for(int i =0;i<figureNumR;i++){
                sum += figureR[i]->returnP();
            }
            for(int i =0;i<figureNumT;i++){
                sum += figureT[i]->returnP();
            }
            cout<<"\nSum = "<<sum;
            sum = 0;
            break;
            case '4':
            cout<<"\nColors: ";
            for(int i =0;i<figureNumR;i++){
                cout<<endl<<i+1<<". "<<figureR[i]->returnColor();
            }

            break;

            case 's':
            check[0]=false;
            
            break;
            default:
            cerr<<"\nWrong input!";
        }

       
    }
    
 
   return 0;
}
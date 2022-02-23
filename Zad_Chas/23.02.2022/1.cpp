/*
 Да се напишат две функции с едно и също име:
-    лице на триъгълник по зададени три страни;
-    лице на правоъгълен триъгълник по зададени двата катета.

Ред на работа:
-    декларират се две структури - Triangle и RectTriangle съответно за триъгълник 
(3 страни) и правоъгълен триъгълник (2 страни);
-    дефинират се два масива - от Triangle и масив от RectTriangle;
-    създава се програма, която чете данните за няколко произволни триъгълника 
(със зададени три страни)  и няколко правоъгълни триъгълника (със зададени два катета);
-    добавят се две функции с едно и също име, които пресмятат, съответно, лицето на триъгълник 
(в общ вид – по хероновата формула) и на правоъгълен триъгълник;
-    добавя се код във функция main или допълнителна 
функция, така че програмата да определя лицето на триъгълника с най-голямо лице.
*/
#include <iostream>
#include <math.h>

using namespace std;

struct Triangle{
float a ,b, c;
};

struct RectTriangle{
float a,b;
};

float S (Triangle x){
    float p = (x.a + x.b + x.c)/2;
    return sqrt(p*(p- x.a)*(p - x.b)*(p - x.c));
}
float S (RectTriangle y){
    return (y.a * y.b)/2;
}




int main(){
    float max = INT_MIN,holder;
    Triangle tr[10];
    RectTriangle rtr[10];
    int n;
    cout<<"Wywedete broi triygylnici: "; cin>> n;

    for(int i = 0;n>i;i++){
        cout<<"Wywedete stranite na triygylnik: ";
        cin>> tr[i].a>>tr[i].b>>tr[i].c;
    }
    for(int i = 0;n>i;i++){
        cout<<"Wywedete Katetite na prawoygylen triygylnik: ";
        cin>> rtr[i].a>>rtr[i].b;
    }
    for(int i = 0;n>i;i++){
        holder=S(tr[i]);
        cout<<"Liceteo na triygylnik "<<i+1<<" e: "<<holder<<endl;
        if(max<holder)
        max=holder;
    }
    for(int i = 0;n>i;i++){
        holder=S(rtr[i]);
        cout<<"Liceteo na Prawoygylen triygylnik "<<i+1<<" e: "<<holder<<endl;
        if(max<holder)
        max=holder;
    }
    cout<<"Nai golqmoto lice e: "<<max;



    return 0;
}
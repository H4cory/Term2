#include <iostream>
#include <string>

using namespace std;

class cUndergrad{
private:
string uniName;
string major;
string fakNum;

public:

cUndergrad():major("?"), fakNum("?"), uniName("?"){

}

void displayData(){
cout<<"\nMajor: "<<major;
cout<<"\nFakNum: "<<fakNum;
cout<<"\nUni name: "<<fakNum;
}

void getData(){
cout<<"Major: ";
getline(cin,major);
cout<<"FakNum: ";
getline(cin,fakNum);
cout<<"Uni name: ";
getline(cin, uniName);
}

};
#include <iostream>
#include <string>

using namespace std;

class cStudent{
private:
string school;
string grade;

public:

cStudent():school("?"), grade("?"){

}
void getData(){
    cout<<"School: ";
    getline(cin,school);
    cout<<"Grade: ";
    getline(cin,grade);
   
}

void displayData(){
    cout<<"\nSchool: "<<school;
    cout<<"\nGrade: "<<grade;
}

};
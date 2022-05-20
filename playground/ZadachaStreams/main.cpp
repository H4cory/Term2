#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
    ifstream textFile ;

    textFile.open("test.txt");
    if(!textFile){
        cerr<<"\nFile was not oppen!";
    }

    



    return 0;
}
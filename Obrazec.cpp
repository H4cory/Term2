/*

*/
#include <iostream>
#include <string>

using namespace std;


int main(){
   string a = "0148255287";
  // getline(cin,a);
  if(stoi(a.substr(2,2)) >  12){
   cout<<stoi(a.substr(2,2))-40;
   }
   else
   cout<<stoi(a.substr(2,2));

 
 
   return 0;
}
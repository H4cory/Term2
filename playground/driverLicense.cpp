/*
You have to get a new driver's license and you show up at the office at the same time as 4 other people.
 The office says that they will see everyone in alphabetical order and it takes 20 minutes for them to
  process each new license. All of the agents are available now, and they can each see one customer at
   a time. How long will it take for you to walk out of the office with your new license?

Task 
Given everyone's name that showed up at the same time, determine how long it will take to get your
 new license.

Input Format 
Your input will be a string of your name, then an integer of the number of available agents,
 and lastly a string of the other four names separated by spaces.

Output Format 
You will output an integer of the number of minutes that it will take to get your license.

Sample Input
'Eric'
2
'Adam Caroline Rebecca Frank'

Sample Output 
40

Explanation 
It will take 40 minutes to get your license because you are in the second group 
of two to be seen by one of the two available agents.

capital letters in ascii: 65-90
*/

#include <iostream>
#include <string>

using namespace std;

class driversAgency{
private:
string yourName;
string otherNames;
int agents=0;
int time=20;

public:
void getData();
void calculate();
void displayData();


};

void driversAgency::getData(){
    cin>>yourName;
    cin>>agents;cin.ignore();
    getline(cin,otherNames);

}

void driversAgency::calculate(){
    char holder = 0;
    int counter =0;


    holder = otherNames[0];
    if(holder<yourName[0]){
        counter++;
    }
   
    
    for(int i =0;otherNames.size()>i;i++){
        if(otherNames[i]==' '){
            holder = otherNames[i+1];
            if(holder<yourName[0]){
                counter++;
            }
        }
        
    }
    while(counter-agents>=0)
    {
        time+=20;
        counter-=agents;
    }
}

void driversAgency::displayData(){
    cout<<time;
}

int main(){
driversAgency quee;
quee.getData();
quee.calculate();
quee.displayData();

    return 0;
}
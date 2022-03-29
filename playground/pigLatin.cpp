/*
You have two friends who are speaking Pig Latin to each other! Pig Latin is the same words in the
same order except that you take the first letter of each word and put it on the end, then you add 
'ay' to the end of that. ("road" = "oadray")
Task :
Your task is to take a sentence in English and turn it into the same sentence in Pig Latin!

Input Format:
A string of the sentence in English that you need to translate into Pig Latin. (no punctuation
or capitalization)

Output Format:
A string of the same sentence in Pig Latin.

Sample Input:
"nevermind youve got them"

Sample Output:
"evermindnay ouveyay otgay hemtay"


Explanation:
The output should be the original sentence with each word changed so that they first letter
 is at the end and then -ay is added after that.

*/

#include <iostream>
#include <string>

using namespace std;

class pigLatin {
    private:
    string textInput;
    char textOutput[500];
     int letterCounter =0;

    public:
    void getData();
    void translator();
    void displayData();


};

void pigLatin::translator(){
    char holder;
    bool check = true;

    for(int i =0;textInput.size()>i;i++){

        if(textInput[i]==' '){
            check = true;
            textOutput[letterCounter++] = holder;
            textOutput[letterCounter++] = 'a';
            textOutput[letterCounter++] = 'y';
            textOutput[letterCounter++] = ' ';
        }
        else if(textInput[i]!=' '&& check){
            holder = textInput[i];
            check = false;
        }
        else {
            textOutput[letterCounter++] = textInput[i];
        }

    }
     textOutput[letterCounter++] = holder;
            textOutput[letterCounter++] = 'a';
            textOutput[letterCounter++] = 'y';
            textOutput[letterCounter++] = ' ';
}

void pigLatin::getData(){
    getline(cin,textInput);
}

void pigLatin::displayData(){
    for(int i =0;letterCounter > i;i++){
        cout<<textOutput[i];
    }
}


int main(){
    pigLatin translate;

    translate.getData();
    translate.translator();
    translate.displayData();

    return 0;
}
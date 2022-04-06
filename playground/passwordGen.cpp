/*
    password generator with diffrent options
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class passwords{
    private:
    string name = "?Empty?";
    char password[64]={'?'};
    int passwordLength;
    bool letters = false;
    bool upperCaseLetters = false;
    bool specialCharacters = false;

    public:
    void getName();
    void parameters();
    void generate();
    void displayData();
    
};

void passwords::getName(){
    cout<<"Please enter name: ";
    getline(cin,name);
}

void passwords::parameters(){
    int input=0;
    bool check=true;
    cout<<"\nHow long do you want your password to be? \n->";
    cin>>passwordLength;
    cout<<"\nDo you want letters?\n1.Yes\n2.No\n->";
    cin>>input;
    while(check){
        switch(input){
            case 1:
            letters = true;
            check = false;
            break;
            case 2:
            letters = false;
            check = false;
            break;
            default:
            cerr<<"Wrong Input";
        }
    }
    check = true;
    cout<<"\nDo you want upper case letters?\n1.Yes\n2.No\n->";
    cin>>input;
    while(check){
        switch(input){
            case 1:
            upperCaseLetters = true;
            check = false;
            break;
            case 2:
            upperCaseLetters = false;
            check = false;
            break;
            default:
            cerr<<"Wrong Input";
        }
    }
    check = true;
    cout<<"\nDo you want special characters?\n1.Yes\n2.No\n->";
    cin>>input;
    while(check){
        switch(input){
            case 1:
            specialCharacters = true;
            check = false;
            break;
            case 2:
            specialCharacters = false;
            check = false;
            break;
            default:
            cerr<<"Wrong Input";
        }
    }
}

void passwords::generate(){
    srand(time(0));

    for(int i=0;passwordLength>i;){
        if(0+(rand()%2)){
            password[i++]=(48+(rand()%58));
        }
        if(0+(rand()%2)&&upperCaseLetters){
            password[i++]=(65+(rand()%91));
        }
        if(0+(rand()%2)&&specialCharacters){
            password[i++]=(33+(rand()%48));
        }
        if(0+(rand()%2)&&letters){
            password[i++]=(97+(rand()%123));
        }
    }
    cout<<"\nYour password is: ";
    for(int i =0;passwordLength>i;i++)
    cout<<password[i];

}
void passwords::displayData(){
    cout<<"\nName    : "<<name;
    cout<<"\nPassword: ";
    for(int i =0;passwordLength>i;i++)
    cout<<password[i];

}




int main(){
    passwords accounts[30];
    bool check = true;
    int input = 0, accountsNum=0;

    do
    {
        cout<<"\n---Menu---\n";
        cout<<"1. Make account\n";
        cout<<"2. Display accounts\n";
        cout<<"3. Generate new password\n";
        cout<<"->";cin>>input;cin.ignore();


        switch (input)
        {
        case 1:
            accounts[accountsNum++].getName();
            accounts[accountsNum].parameters();
            accounts[accountsNum].generate();
            break;
        case 2:
        for(int i =0;accountsNum>i;i++){
            accounts[i].displayData();
        }
           
            break;
        case 3:
            /* code */
            break;
        case 4:
            /* code */
            break;
        case 5:
            /* code */
            break;
        case 55:
            check = false;
            break;
        default:
        cerr<<"\nWrong input!\n";
            break;
        }
        
    } while (check);
    


    return 0;
}
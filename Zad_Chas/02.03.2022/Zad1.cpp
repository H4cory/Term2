#include <iostream>
#include <string>

using namespace std;

class CBook {
private:
	int iNumber;
	string author, title;
	int pages;
	float price;
public:
	void getData();
	void display();
    int getPrice();
    string getAuthor();
    string getTitle();
    int getINumber();
};
void CBook::getData(){
    cout<<"Insert Inv. Num.: ";cin >> iNumber; cin.ignore();
    cout<<"Insert Author: "; getline(cin, author);
    cout<<"Insert Title: "; getline(cin, title);
    cout<<"Insert pages: "; cin >> pages;
    cout<<"Insert price: "; cin>> price;

}
void CBook::display(){
    cout<<"\nInv.Num. : "<<iNumber<<endl;
    cout<<"Authoir: "<<author<<endl;
    cout<<"Title: "<<title<<endl;
    cout<<"Pages: "<<pages<<endl;
    cout<<"Price: "<<price<<endl;
}

int CBook::getPrice(){
    return price;
}
string CBook::getAuthor(){
    return author;
}
string CBook::getTitle(){
    return title;
}
int CBook::getINumber(){
    return iNumber;
}


int main(){
    string AInput, CheapTitles[1000];
    bool check = true;
    CBook books[1000];
    char input;
    int numberB=0, sum = 0,numberT =0, InputINumber;


    do {
    cout<<"\n--MENU--\n";
    cout<<"1. Insert Book\n";
    cout<<"2. Get Book/s\n";
    cout<<"3. Get Sum of Price\n";
    cout<<"4. Get Book/s by Author\n";
    cout<<"5. Get Titles under 15\n";
    cout<<"6. Delete Book Entry\n";
    cout<<"0. Quit\n";
    cout<<"INPUT: ";
    cin>>input;cin.ignore();

        switch(input){
            case '0':check = false;break;
            case '1':books[numberB++].getData(); break;
            case '2':for(int i =0;i<numberB;i++)books[i].display(); break;
            case '3':for(int i =0;i<numberB;i++){
                     sum+= books[i].getPrice();
                     } 
                     cout<<"\nSum: "<<sum;
                     sum =0;
                     break;

            case '4':cout<<"Input Author: ";
                     getline(cin, AInput);
                     for(int i =0;i<numberB;i++){
                         if(AInput==books[i].getAuthor())
                         books[i].display();
                     }  
                     break;
            case '5':for(int i =0;i<numberB;i++){
                        if(books[i].getPrice()<=15){
                            CheapTitles[numberT++]=books[i].getTitle();
                        }
                     } 
                     for(int i=0;i<numberT;i++){
                         cout<<"Title "<<i+1<<": "<<CheapTitles[i]<<endl;
                     }
                     numberT = 0;
                     break;
            case '6':cout<<"Rem. Inv. Num. : ";cin>>InputINumber;
                    for(int i =0;i<numberB;i++)
                    if(books[i].getINumber()==InputINumber){
                     for(int j = i; j<numberB;j++)
                     books[j]=books[j+1];
                     numberB--;
                    }
                     break;
            default: cerr<<"Wrong INPUT!!!"; 
        }

    }
    while(check);


    return 0;
}
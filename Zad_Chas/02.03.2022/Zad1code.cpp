#include<string>
#include <iostream>
using namespace std;

class Book
{
private:
string uNumber = "";
string title = "";
string author = "";
int pages = 0;
float price = 0;
public:
string GetuNumber();
string GetTitle();
string GetAuthor();
int GetPages();
float GetPrice();

void DisplayData();
void setData();

};



string Book::GetuNumber() {
return this->uNumber;
}
string Book::GetTitle() {
return this->title;
}
string Book::GetAuthor() {
return this->author;
}
int Book::GetPages() {
return this->pages;
}
float Book::GetPrice() {
return this->price;
}

void Book::setData() {
string c_uNumber;
string c_title;
string c_author;
int c_pages;
float c_price;
cout << "Book #: "; cin >> c_uNumber; cin.ignore();
cout << "Title: "; getline(cin, c_title);
cout << "Author: "; getline(cin, c_author);
cout << "# of Pages: "; cin >> c_pages;
cout << "Price: "; cin >> c_price;

}
void Book::DisplayData() {
cout << "Book #: " << this->GetuNumber() << endl;
cout << "Title: " << this->GetTitle() << endl;
cout << "Author: " << this->GetAuthor() << endl;
cout << "# of Pages: " << this->GetPages() << endl;
cout << "Price: " << this->GetPrice() << endl;
}

//Book::~Book() {
// cout << "Book destroyed" << endl;
//}
//Funktsiya za namirane sumata ot tsenite na vsichki knigi
float SumPrices(Book arBooks[], int n) {
float sum = 0;

for (int i = 0; i < n; i++)
sum += arBooks[i].GetPrice();
return sum;
}
//Izvezhdane dannite na knigite ot zadaden avtor
void BooksAuthor(Book arBooks[], int n, string insAuthor) {
for (int i = 0; i < n; i++) {

if (arBooks[i].GetAuthor() == insAuthor)
arBooks[i].DisplayData();
}
}
//Funktsiya za iztrivane dannite na kniga sas zadaden inventaren nomer
void DeleteBook(Book arBooks[], int& n, string insNum) {
int i, j = 0;
for (i = 0; i < n; i++)
if (arBooks[i].GetuNumber() == insNum)
for (int j = i; j < n - 1; j++)
arBooks[j] = arBooks[j + 1];
i--;
n--;
}
//Създаване на нов клас, нужен за създаване на масив, съдържащ
//заглавията книгите с цена до 15 лв.
class Book1 {
private:
string title = "";
public:
void displayData() {
cout << "Title: " << this->GetTitle() << endl;
}
void SetTitle(string c_title);
string GetTitle();
};
void Book1::SetTitle(string c_title) {
this->title = c_title;
}


string Book1::GetTitle() {
return this->title;
}


void SzdNovMas(Book arBooks[], int count_b, Book1 arBooks15[], int& count_books15) {
int j = 0;
for (int i = 0; i < count_b; i++)
if (arBooks[i].GetPrice() < 15) {
arBooks15[j++].SetTitle(arBooks[i].GetTitle());
}
count_books15 = j;
}


//Главна функция main
void main() {
system("chcp 1251");
char KodOp;
int i, CountB = 0, //-брой книги в библиотеката
CountB15 = 0; //-брой книги в библиотеката с цена до 15 лв.

Book ArrBooks[10]; //-масив с данните на всички книги
Book1 ArrBooks15[10]; //-масив с данните на книгите с цена до 15 лв.

string InsAuthor; //-името на зададения автор
string InsNum;
do {
cout << "\nМЕНЮ НА ИЗПЪЛНЯВАНИТЕ ОПЕРАЦИИ:\n";
cout << " 1 - за дoбавяне данни за книгa\n";
cout << " 2 - за извеждане данните на всички книги.\n";
cout << " 3 - за намиране и извеждане сумата от цените на всички книги;\n";
cout << " 4 - за извеждане данните на всички книги от зададен автор;\n";
cout << " 5 - за изтриване данните на книга със зададен инв.номер;\n";
cout << " 6 - за създаване на масив със заглавията на книгите с цена до 15 лв.\n";
cout << "Посочете операция или 0 за край: "; cin >> KodOp;
switch (KodOp) {
case '0':break;
case '1':ArrBooks[CountB++].setData(); break;
case '2':cout << "\nСписък на всички книги:\n";
for (i = 0; i < CountB; i++) ArrBooks[i].DisplayData();
break;
case '3':cout << "Сумата от цените на всички книги е "
<< SumPrices(ArrBooks, CountB) << endl;
break;
case '4':cin.ignore();
cout << "Задайте автора: "; cin >> InsAuthor;
cout << "\n\tKниги от " << InsAuthor << ":\n";
BooksAuthor(ArrBooks, CountB, InsAuthor); break;
case '5': cout << "Задайте инвентарния номер: "; cin >> InsNum;
DeleteBook(ArrBooks, CountB, InsNum); break;
case '6':SzdNovMas(ArrBooks, CountB, ArrBooks15, CountB15);
for (i = 0; i < CountB15; i++) ArrBooks15[i].displayData();
break;

default: cout << "Грешен код на операция.\n";
}
} while (KodOp != '0');

}
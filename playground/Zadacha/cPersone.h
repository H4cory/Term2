#include <iostream>
#include <string>
#include "cStudent.h"
#include "cUndergrad.h"
using namespace std;
#pragma once

class cPersone: public cStudent, public cUndergrad
{
private:
    string name;
    string EGN;
    float points;
    int status;

public:
    cPersone() : name("?"), EGN("?"), points(0), status(0)
    {
    }
    void getData(int a)
    {
        status = a;
        cout << "\nName: ";
        getline(cin, name);
        cout << "EGN: ";
        getline(cin, EGN);
        cout<<"Points: ";
        cin>>points;
        cin.ignore();
        if(status == 1){
            cStudent::getData();
        }
        else if (status == 2){
            cUndergrad::getData();

        }
        else{
            cerr<<"\nSomething went wrong!\n";
        }
    }
    void displayData()
    {
        cout << "\nName: " << name;
        cout << "\nEGN: " << EGN;
        cout <<"\nPoints: "<<points;
        if(status == 1){
            cStudent::displayData();
        }
        else if (status == 2){
            cUndergrad::displayData();

        }
        else{
            cerr<<"\nSomething went wrong!\n";
        }
    }

    float returnPoints(){
        return points;
    }

    string returnEgn(){
        return EGN;
    }
    bool checkFemale(){
        if ((stoi(EGN.substr(8, 1))) % 2 == 1 ){
            return true;
        }
        else 
        return false;
    }

};


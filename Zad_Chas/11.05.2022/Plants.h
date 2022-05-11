#include <iostream>
#include <string>
#include "Abstr.h"
using namespace std;
#pragma once

class Plants : public AbstractPlants
{
private:
    string name;
    string units;
    string price;

public:
    Plants() : name("?"), units("?"), price("?")
    {
    }

    void getData()
    {
        cout << "\nName: ";
        getline(cin, name);
        cout << "Available units: ";
        getline(cin, units);
        cout << "Price per unit: ";
        getline(cin, price);
    }

    void displayData()
    {
        cout << "\nName: " << name;
        cout << "\nAvailable units: " << units;
        cout << "\nPrice per unit: " << price;
    }
};
#include <iostream>
#include <string>
#include "Plants.h"
using namespace std;
#pragma once

class Flowers : public Plants
{
private:
    string color;

public:
    Flowers() : color("?")
    {
    }

    void getData()
    {
        Plants::getData();
        cout << "Color: ";
        getline(cin, color);
    }

    void displayData()
    {
        Plants::displayData();
        cout << "\nColor: " << color;
    }

    bool tall()
    {
        return false;
    }
    bool flower()
    {
        return true;
    }
};
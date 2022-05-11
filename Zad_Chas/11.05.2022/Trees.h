#include <iostream>
#include <string>
#include "Plants.h"
using namespace std;
#pragma once

class Trees : public Plants
{
private:
    float height;
    string type;

public:
    Trees() : height(0.0), type("?")
    {
    }

    void getData()
    {
        Plants::getData();
        cout << "Height: ";
        cin >> height;
        cin.ignore();
        cout << "\n1.Coniferous\n2.Deciduous\n~Or just enter the species you want.\nType: ";
        getline(cin, type);
        if (type[0] == '1')
        {
            type = "Coniferous";
        }
        else if (type[0] == '2')
        {
            type = "Deciduous";
        }
    }

    void displayData()
    {
        Plants::displayData();
        cout << "\nHeight: " << height;
        cout << "\nType: " << type;
    }

    bool tall()
    {
        if (height > 2.0)
        {
            return true;
        }
        else
            return false;
    }
    bool flower()
    {
        return false;
    }
};
#include <iostream>
#include <string>
#include <fstream>
#include "Plants.h"

using namespace std;
#pragma once

class Flowers : public Plants
{
private:
    string color;

public:
    Flowers()
    {
    }

    // gets data from file
    Flowers(string input)
    {
        int i = 1;
        int count = 1;
        Plants::getData(input, i, count, color);
        Plants::getDataFromFile(input, i, count);
    }

    // gets data from user and saves it
    void getData()
    {
        fstream textFile;
        string name, price, units;
        bool WI = false;
        cout << "\nName:  ";
        getline(cin, name);
        cout << "Price: ";
        getline(cin, price);
        while (true)
        {
            WI = false;
            for (int i = 0; i < price.length(); i++)
            {
                if (isalpha(price[i]))
                {
                    WI = true;
                }
            }
            if (WI)
            {
                cout << "\nYou have entered letters!!!\nPlease enter a new price.\nPrice: ";
                getline(cin, price);
            }
            else
                break;
        }
        cout << "Units: ";
        getline(cin, units);
        cout << "Color: ";
        getline(cin, color);

        textFile.open("saveData.txt", ios::app);
        if (textFile.is_open())
        {
            textFile << "f" << color << "$" << name << "$" << price << "$" << units << "$\n";
            textFile.close();
        }
        else
            cout << "\nFile couldn't open!";

        Plants::getData(name, price, units);
    }

    // displays data from object
    void displayData()
    {
        {
            Plants::displayData();
            cout << "\nColor: " << color;
        }
    }

    // returns data for object
    string saveData()
    {
        return "f" + color + "$" + Plants::saveData();
    }

    // returns false for Coniferous trees
    bool isCon()
    {
        return false;
    }
};
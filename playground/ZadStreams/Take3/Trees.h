#include <iostream>
#include <string>
#include <fstream>
#include "Plants.h"

using namespace std;
#pragma once

class Trees : public Plants
{
private:
    string size;
    string type;

public:
    Trees()
    {
    }

    // gets data from file
    Trees(string input)
    {
        int i = 1;
        int count = 1;
        Plants::getData(input, i, count, size);
        Plants::getData(input, i, count, type);
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
        cout << "Size:  ";
        getline(cin, size);
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

        textFile.open("saveData.txt", ios::app);
        if (textFile.is_open())
        {
            textFile << "t" << size << "$" << type << "$" << name << "$" << price << "$" << units << "$\n";
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
            cout << "\nSize: " << size;
            cout << "\nType: " << type;
        }
    }

    // returns data for object
    string saveData()
    {
        return "t" + size + "$" + type + "$" + Plants::saveData();
    }

    // checks for Coniferous trees
    bool isCon()
    {
        if (type == "Coniferous" || type == "coniferous")
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
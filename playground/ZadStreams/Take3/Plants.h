#include <iostream>
#include <string>
#include <fstream>
#include "Abstr.h"

using namespace std;
#pragma once

// main class
class Plants : public Abstr
{
private:
    string name;
    string price;
    string units;
    fstream textFile;

public:
    Plants()
    {
    }

    // constructor for getting data from file
    Plants(string input)
    {

        int i = 0;
        int count = 0;
        getData(input, i, count, name);
        getData(input, i, count, price);
        getData(input, i, count, units);
    }

    // gets individual data
    void getData(string input, int &i, int &count, string &answer)
    {
        while (true)
        {
            if (input[i] == '$')
            {
                answer = input.substr(count, i - count);
                count = i + 1;
                i++;
                break;
            }
            else
                i++;
        }
    }
    // Gets Data
    void getData()
    {
        cout << "\nName: ";
        getline(cin, name);
        cout << "Price: ";
        getline(cin, price);
        cout << "Units: ";
        getline(cin, units);
        textFile.open("saveData.txt", ios::app);
        if (textFile.is_open())
        {
            textFile << name << "$" << price << "$" << units << "$\n";
            textFile.close();
        }
        else
            cout << "\nFile couldn't open!";
    }
    // Displays Data
    void displayData()
    {
        cout << "\nName: " << name;
        cout << "\nPrice: " << price;
        cout << "\nUnits: " << units;
    }

    // Looks form match in the names
    bool checkName(string input)
    {
        if (input == name)
        {
            return true;
        }
        else
            return false;
    }

    // Saves data for the object in a file
    string saveData()
    {
        return name + "$" + price + "$" + units + "$\n";
    }
};
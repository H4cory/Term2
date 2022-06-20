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

public:
    Plants()
    {
    }

    // getting data from file
    void getDataFromFile(string input, int &i, int &count)
    {
        getData(input, i, count, name);
        getData(input, i, count, price);
        getData(input, i, count, units);
    }

    // gets individual data
    void getData(string &input, int &i, int &count, string &answer)
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
    void getData(string nName, string nPrice, string nUnits)
    {
        name = nName;
        price = nPrice;
        units = nUnits;
    }

    void getData()
    {
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

    // cheks price
    bool checkPr()
    {
        if (stoi(price) < 10)
        {
            return true;
        }
        else
            return false;
    }
};
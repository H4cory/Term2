#include <iostream>
#include <string>
using namespace std;
#pragma once

// Abstract class
class Abstr
{
private:
public:
    virtual void getData() = 0;
    virtual void displayData() = 0;
    virtual bool checkName(string) = 0;
    virtual string saveData() = 0;
};
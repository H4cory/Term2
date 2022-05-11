#include <iostream>
#include <string>

using namespace std;
#pragma once

class AbstractPlants
{
public:
    virtual void getData() = 0;
    virtual void displayData() = 0;
    virtual bool tall() = 0;
    virtual bool flower() = 0;
};
#pragma once

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::ostream;
using std::ifstream;
using std::istream;

class Data
{
public: // Member functions

    Data(int newServiceTime = ((rand() % 8) + 1), int prevServiceTime = 0, int prevCustomerNumber = 0);

    Data(Data& copy);

    ~Data();
    
    int getCustomerNumber();
    int getServiceTime();
    int getTotalTime();

    void setCustomerNumber(int newCustomerNumber);
    void setServiceTime(int newServiceTime);
    void setTotalTime(int newTotalTime);

private:

    int customerNumber; // Unique identifier; starts at 1; after 24 hours should be reset to 1

    int serviceTime;   // Random time; varies between express and normal lanes; units in minutes

    int totalTime;     // totalTime = serviceTime + sum of serviceTimes of customers in line before this customer; units in minutes

};

ostream& operator<<(ostream& lhs, Data& rhs);


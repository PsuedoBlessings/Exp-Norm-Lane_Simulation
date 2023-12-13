#pragma once
#include"Data.hpp"

class QueueNode
{
public: // Member functions

    
    // the three constructors
    QueueNode(Data newpData);

    QueueNode(QueueNode& copy);
    
    ~QueueNode();

    // getters
    Data* getpData();
    QueueNode* getpNext();

    // setters
    void setpData(Data* newpData);
    void setpNext(QueueNode* newpNext);

    // other functions
private:

    Data* pData;    // The memory for Data will need to be allocated on the heap as well!

    QueueNode* pNext;

};


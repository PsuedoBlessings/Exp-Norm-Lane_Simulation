#pragma once
#include "QueueNode.hpp"

class Queue
{
public:

    // the three constructors
    Queue(QueueNode* pHead = nullptr, QueueNode* pTail = nullptr);

    Queue(Queue& copy);

    ~Queue();

    // the getters
    QueueNode* getpHead();
    QueueNode* getpTail();

    // the setters
    void setpHead(QueueNode* newpHead);
    void setpTail(QueueNode* newpTail);

    //the other functions
    bool enqueue(Data customerInfo);
    Data dequeue();
    void printQueue();
    bool isEmpty();

private:

    QueueNode* pHead;

    QueueNode* pTail;

};
#include "Queue.hpp"

Queue::Queue(QueueNode* pHead, QueueNode* pTail)
{
	this->pHead = pHead;
	this->pTail = pTail;
}

Queue::Queue(Queue& copy)
{
	this->pHead = copy.pHead;
	this->pTail = copy.pTail;
}

Queue::~Queue()
{}

QueueNode* Queue::getpHead()
{
	return this->pHead;
}

QueueNode* Queue::getpTail()
{
	return this->pTail;
}

void Queue::setpHead(QueueNode* newpHead)
{
	this->pHead = newpHead;
}

void Queue::setpTail(QueueNode* newpTail)
{
	this->pTail = newpTail;
}

bool Queue::enqueue(Data customerInfo)
{
	QueueNode* pMem = new QueueNode(customerInfo);
	bool success = false;

	if (pMem != nullptr)
	{
		success = true;

		if (isEmpty())
		{
			this->pHead = this->pTail = pMem;
		}
		else
		{
			this->pTail->setpNext(pMem);
			// adds the previous customer number to make it in order
			pMem->getpData()->setCustomerNumber(this->pTail->getpData()->getCustomerNumber() + 1);
			// adds both of the total time to get the true total time when added to the queue
			pMem->getpData()->setTotalTime(this->pTail->getpData()->getTotalTime() + pMem->getpData()->getTotalTime());
			this->pTail = pMem;
		}

	}
	return success;
}

Data Queue::dequeue()
{
	QueueNode* pTemp = this->pHead;

	if (this->pHead == this->pTail)
	{
		// one node in queue
		this->pHead = this->pTail = nullptr;
	}
	else
	{
		// more than one node
		this->pHead = this->pHead->getpNext();
	}

	Data data = *pTemp->getpData();
	delete pTemp; 
	return data;
}

void Queue::printQueue()
{
	if (isEmpty())
	{
		cout << "Lane is empty..." << endl;
	}

	else
	{
		QueueNode* pCur = this->pHead;
		while (pCur != nullptr)
		{
			cout << *pCur->getpData();
			pCur = pCur->getpNext();
		}
	}
}

bool Queue::isEmpty()
{
	return this->pHead == nullptr;
}
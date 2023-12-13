#include"QueueNode.hpp"

QueueNode::QueueNode(Data newpData)
{
	this->pData = new Data(newpData);
	this->pNext = nullptr;
}

QueueNode::QueueNode(QueueNode& copy)
{
	this->pData = copy.pData;
	this->pNext = copy.pNext;
}

QueueNode::~QueueNode()
{
	free(this->pData);
}

// getters
Data* QueueNode::getpData()
{
	return this->pData;
}

QueueNode* QueueNode::getpNext()
{
	return this->pNext;
}

// setters
void QueueNode::setpData(Data* newpData)
{
	this->pData = newpData;
}

void QueueNode::setpNext(QueueNode* newpNext)
{
	this->pNext = newpNext;
}

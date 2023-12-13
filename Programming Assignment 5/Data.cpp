#include "Data.hpp"

Data::Data(int newServiceTime, int prevServiceTime, int prevCustomerNumber)
{
	this->customerNumber = prevCustomerNumber + 1;
	this->serviceTime = newServiceTime;
	this->totalTime = this->serviceTime + prevServiceTime;

}

Data::Data(Data& copy)
{
	this->customerNumber = copy.customerNumber;
	this->serviceTime = copy.serviceTime;
	this->totalTime = copy.totalTime;
}

Data::~Data()
{}

int Data::getCustomerNumber()
{
	return this->customerNumber;
}

int Data::getServiceTime()
{
	return this->serviceTime;
}

int Data::getTotalTime()
{
	return this->totalTime;
}

void Data::setCustomerNumber(int newCustomerNumber)
{
	this->customerNumber = newCustomerNumber;
}

void Data::setServiceTime(int newServiceTime)
{
	this->serviceTime = newServiceTime;
}

void Data::setTotalTime(int newTotalTime)
{
	this->totalTime = newTotalTime;
}

ostream& operator<<(ostream& lhs, Data& rhs)
{
	cout << "			Customer " << rhs.getCustomerNumber() << endl << endl;
	cout << "Service Time: " << rhs.getServiceTime() << endl;
	cout << "Waiting Time: " << rhs.getTotalTime() - rhs.getServiceTime() << endl;
	cout << "Total Time: " << rhs.getTotalTime() << endl;

	return lhs;
}
#include"Simulation.hpp"

void Simulation::runSimulation()
{
	generateArrivalTimeExpress();
	generateArrivalTimeNormal();
	cout << "How long do you want the simulation to go: ";
	cin >> this->Time;

	for(int count = 0;this->Time != 0; this->Time--, updateArrivalTime(), updateServiceTime(), count++)
	{
		if (count == 9)
		{
			cout << "vvvvv Express Lane vvvvv" << endl << endl;
			this->ExpressLane.printQueue();
			cout << "************************" << endl << endl;

			cout << "vvvvv Normal Lane vvvvv" << endl << endl;
			this->NormalLane.printQueue();
			cout << "************************" << endl << endl;

			count = 0;
		}

		if(this->ExpressLane.isEmpty() && ArivalTimeExpress == 0)
		{
			generateCustomer_ExpressLane();
			generateArrivalTimeExpress();
			printCustomer_ExpressLane();
		}

		if (this->NormalLane.isEmpty() && ArivalTimeNormal == 0)
		{
			generateCustomer_NormalLane();
			generateArrivalTimeNormal();
			printCustomer_NormalLane();
		}
		

		if (this->ArivalTimeExpress == 0)
		{
			generateCustomer_ExpressLane();
			generateArrivalTimeExpress();
			printCustomer_ExpressLane();

		}

		if (this->ArivalTimeNormal == 0)
		{
			generateCustomer_NormalLane();
			generateArrivalTimeNormal();
			printCustomer_NormalLane();

		}

		if (!this->ExpressLane.isEmpty() && this->ExpressLane.getpHead()->getpData()->getServiceTime() == 0)
		{
			Data DeletedData = *this->ExpressLane.getpHead()->getpData();
			cout << DeletedData;
			Data LastinLine = *this->ExpressLane.getpTail()->getpData();
			cout << "Total Time Left: " << LastinLine.getTotalTime() << endl;
			cout << "Leaving from the Express Lane" << endl;
			this->ExpressLane.dequeue();
		}

		if (!this->NormalLane.isEmpty() && this->NormalLane.getpHead()->getpData()->getServiceTime() == 0)
		{
			Data DeletedData = *this->NormalLane.getpHead()->getpData();
			cout<< DeletedData;
			Data LastinLine = *this->NormalLane.getpTail()->getpData();
			cout << "Total Time Left: " << LastinLine.getTotalTime() << endl;
			cout << "Leaving from the Normal Lane" << endl;
			this->NormalLane.dequeue();
		}
	}
	
}

Simulation::Simulation(Queue NormalLane, Queue ExpressLane, int Time)
{
	this->Time = Time;
	this->ExpressLane = ExpressLane;
	this->NormalLane = NormalLane;
}

Simulation::Simulation(Simulation& copy)
{
	this->ExpressLane = copy.ExpressLane;
	this->NormalLane = copy.NormalLane;
	this->Time = copy.Time;
}

Simulation::~Simulation()
{}

Queue Simulation::getExperssLane()
{
	return this->ExpressLane;
}

Queue Simulation::getNormalLane()
{
	return this->NormalLane;
}

int Simulation::getTime()
{
	return this->Time;
}

int Simulation::getArrivalTimeExpress()
{
	return this->ArivalTimeExpress;
}

int Simulation::getArrivalTimeNormal()
{
	return this->ArivalTimeNormal;
}

void Simulation::setTime(int newTime)
{
	this->Time = newTime;
}

void Simulation::setArrivalTimeExpress(int newArrivalTimeExpress)
{
	this->ArivalTimeExpress = newArrivalTimeExpress;
}

void Simulation::setArrivalTimeNormal(int newArrivalTimeNormal)
{
	this->ArivalTimeNormal = newArrivalTimeNormal;
}

void Simulation::generateCustomer()
{
	generateCustomer_ExpressLane();
	generateCustomer_NormalLane();

}

void Simulation::generateCustomer_ExpressLane()
{
	int ServiceTime = ((rand() % 5) + 1);
	Data Data(ServiceTime);
	this->ExpressLane.enqueue(Data);
}

void Simulation::generateCustomer_NormalLane()
{
	int ServiceTime = ((rand() % 6) + 3);
	Data Data(ServiceTime);
	this->NormalLane.enqueue(Data);
}

void Simulation::generateArrivalTimeExpress()
{
	this->ArivalTimeExpress = ((rand() % 5) + 1);
}

void Simulation::generateArrivalTimeNormal()
{
	this->ArivalTimeNormal = ((rand() % 6) + 3);
}

void Simulation::updateServiceTime()
{
	if (!this->ExpressLane.isEmpty())
	{
		this->ExpressLane.getpHead()->getpData()->setServiceTime(this->ExpressLane.getpHead()->getpData()->getServiceTime() - 1);
	}

	if (!this->NormalLane.isEmpty())
	{
		this->NormalLane.getpHead()->getpData()->setServiceTime(this->NormalLane.getpHead()->getpData()->getServiceTime() - 1);
	}

}

void Simulation::updateArrivalTime()
{
	this->ArivalTimeExpress -= 1;
	this->ArivalTimeNormal -= 1;
}

void Simulation::printCustomer_ExpressLane()
{
	cout << *this->ExpressLane.getpTail()->getpData();
	cout << "Arrival Time: " << this->ArivalTimeExpress << endl;
	cout << "Entered through the Express Lane" << endl;
}

void Simulation::printCustomer_NormalLane()
{
	cout << *this->NormalLane.getpTail()->getpData();
	cout << "Arrival Time: " << this->ArivalTimeNormal << endl;
	cout << "Entered through the Normal Lane" << endl;
}

bool YN()
{
	enum YesorNo
	{
		No, Yes
	};

	int RNG = (rand() % 100) + 1;

	if (RNG <= 50)
	{
		return Yes;
	}

	else
	{
		return No;
	}
}
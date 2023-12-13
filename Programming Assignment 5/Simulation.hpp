#pragma once
#include"Queue.hpp"

class Simulation
{
public:
	
	// the three constructors
	Simulation(Queue NormalLane, Queue ExpressLane, int Time = 1440);

	Simulation(Simulation& copy);

	~Simulation();

	// the getters
	Queue getExperssLane();
	Queue getNormalLane();
	int getTime();
	int getArrivalTimeExpress();
	int getArrivalTimeNormal();

	// the setters
	void setTime(int newTime);
	void setArrivalTimeExpress(int newArrivalTimeExpress);
	void setArrivalTimeNormal(int newArrivalTimeNormal);

	// the other functions

	//this runs the simulation
	void runSimulation();

	// these are the generators
	void generateCustomer();
	void generateCustomer_ExpressLane();
	void generateCustomer_NormalLane();
	void generateArrivalTimeExpress();
	void generateArrivalTimeNormal();

	void updateServiceTime();
	void updateArrivalTime();

	void printCustomer_ExpressLane();
	void printCustomer_NormalLane();

private:
	Queue ExpressLane;
	Queue NormalLane;
	int Time;
	int ArivalTimeExpress;
	int ArivalTimeNormal;
};

bool YN();
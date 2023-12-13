#include"Simulation.hpp"
#include"TestFunc.hpp"

int main(void)
{
	srand(time(NULL));

	Queue ExpressLane;
	Queue NormalLane;
	
	Simulation Simulation(ExpressLane, NormalLane);

	Simulation.runSimulation();

	return 0;
}
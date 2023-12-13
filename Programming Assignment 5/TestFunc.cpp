#include "TestFunc.hpp"

void Test_Empty_Enqueue()
{
	Queue Empty_Queue;

	Data Test;

	Empty_Queue.enqueue(Test);

	Empty_Queue.printQueue();

	// Expected Results

	/*
	  ***********Terminal***********
	 
		Costumer 1


		Service Time: Random value...

		Waiting Time: 0

		Total Time: Random value...
	 */

}

void Test_One_Enqueue()
{
	Queue Empty_Queue;

	Data Test;

	Data Test2(Test.getCustomerNumber(), Test.getServiceTime());

	Empty_Queue.enqueue(Test);

	Empty_Queue.enqueue(Test2);

	Empty_Queue.printQueue();

	// Expected Results

	/*
	  ***********Terminal***********

				Costumer 1


		Service Time: Random value...

		Waiting Time: Random value...

		Total Time: Random value...

				Costumer 2


		Service Time: Random value...

		Waiting Time: Random value...

		Total Time: Random value...
	 */

}

void Test_One_Dequeue()
{
	Queue Empty_Queue;

	Data Test;

	Empty_Queue.enqueue(Test);

	Empty_Queue.dequeue();

	Empty_Queue.printQueue();

	// Expected Results

	/*
	  ***********Terminal***********

	Lane is empty...

	 */

}

void Test_Two_Dequeue()
{
	Queue Empty_Queue;

	Data Test;

	Data Test2(Test.getCustomerNumber(), Test.getServiceTime());

	Empty_Queue.enqueue(Test);

	Empty_Queue.enqueue(Test2);

	Empty_Queue.dequeue();

	Empty_Queue.dequeue();

	Empty_Queue.printQueue();

	// Expected Results

	/*
	  ***********Terminal***********

	Lane is empty...

	 */
}

void Test_Simulation()
{

}
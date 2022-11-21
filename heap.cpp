/***************************************************************
  Student Name: Thomas, Arthur
  File Name: heap.cpp
  Assignment number: Project 2
***************************************************************/

#include "heap.hpp"

Heap::Heap(float n, float lambda, float mu, float M)
{
	this->numArrivals = n;
	this->numCustomers = n;
	this->lambda = lambda;
	this->mu = mu;
	this->M = M;
	srand((float)time(0));
	serversAvailable = M;
	float time = 0;
	for (int i = 1; i < PQSize + 1; i++)
	{
		this->priorityQ[i] = new Customer(time, true);
		numArrivals--;
		PQCount++;
		time += GetNextRandomInterval(lambda);
	}
	EventLoop();
}

float Heap::GetNextRandomInterval(float avg)
{
	float num = 0, interval = 0;
	while (num == 0)
	{
		num = (float)rand() / RAND_MAX;
	}
	interval = -1.0 * (1.0 / avg) * log(num);
	return interval;
}

void Heap::EventLoop()
{
	while (PQCount > 0)
	{
		ProcessNextEvent();
		if (numArrivals > 0 && PQCount <= M + 1)
		{
			RefillPQ();
		}
	}
	ShowResults();
}

void Heap::ProcessNextEvent()
{
	float interval = 0;
	if (priorityQ[1]->GetIsArrival())
	{
		if (serversAvailable > 0)
		{
			serversAvailable--;
			priorityQ[1]->SetStartOfServiceTime(priorityQ[1]->GetArrivalTime());
			interval = GetNextRandomInterval(mu);
			priorityQ[1]->SetDepartureTime(priorityQ[1]->GetStartOfServiceTime() + interval);
			priorityQ[1]->SetIsArrival(false);
			PercolateDown(1);
		}
		else
		{
			FIFOQ.insert(priorityQ[1]);
			priorityQ[1] = priorityQ[PQCount];
			PQCount--;
			PercolateDown(1);
		}
	}
	else
	{
		serversAvailable++;
		priorityQ[0] = priorityQ[1];
		runTime = priorityQ[0]->GetDepartureTime();
		if (!FIFOQ.IsEmpty())
		{
			serversAvailable--;
			priorityQ[1] = FIFOQ.remove();
			priorityQ[1]->SetStartOfServiceTime(priorityQ[0]->GetDepartureTime());
			priorityQ[1]->SetWaitTime(priorityQ[1]->GetStartOfServiceTime() - priorityQ[1]->GetArrivalTime());
			interval = GetNextRandomInterval(mu);
			priorityQ[1]->SetDepartureTime(priorityQ[1]->GetStartOfServiceTime() + interval);
			priorityQ[1]->SetIsArrival(false);
			PercolateDown(1);
		}
		else
		{
			priorityQ[1] = priorityQ[PQCount];
			PQCount--;
			PercolateDown(1);
		}
		ProcessStatistics();
		Customer *garbage = this->priorityQ[0];
		delete garbage;
	}
}

void Heap::PercolateDown(int slot)
{
	int child;
	Customer *tmp = priorityQ[slot];
	while (slot * 2 <= PQCount)
	{
		child = slot * 2;
		if (child != PQCount && priorityQ[child + 1]->GetDepartureTime() < priorityQ[child]->GetDepartureTime())
			child++;
		if (priorityQ[child]->GetDepartureTime() < tmp->GetDepartureTime())
			priorityQ[slot] = priorityQ[child];
		else
			break;
		slot = child;
	}
	priorityQ[slot] = tmp;
}

void Heap::RefillPQ()
{
	float time = priorityQ[PQCount]->GetArrivalTime();
	for (int i = PQCount + 1; numArrivals > 0 && i < PQSize + 1; i++)
	{
		time += GetNextRandomInterval(lambda);
		this->priorityQ[i] = new Customer(time, true);
		numArrivals--;
		PQCount++;
	}
}

void Heap::ProcessStatistics()
{
	totalWaitTime += priorityQ[0]->GetWaitTime();
	totalServiceTime += (priorityQ[0]->GetDepartureTime() - priorityQ[0]->GetStartOfServiceTime());

	if (serversAvailable == M)
	{
		idleTime += (priorityQ[1]->GetArrivalTime() - priorityQ[0]->GetDepartureTime());
	}
}

void Heap::ShowResults()
{
	Analytics myStats(lambda, mu, M);
	float Po = myStats.GetPo();
	float L = myStats.GetL();
	float W = myStats.GetW();
	float Lq = myStats.GetLq();
	float Wq = myStats.GetWq();
	float Rho = myStats.GetRho();
	cout << endl
		 << "Given:" << endl
		 << "Lambda = " << lambda;
	cout << endl
		 << "mu = " << mu;
	cout << endl
		 << "M = " << M << endl;
	cout << endl
		 << "Simulation Results:" << endl;
	cout << "Po = " << idleTime / runTime << endl;
	cout << "W = " << (totalWaitTime + totalServiceTime) / numCustomers << endl;
	cout << "Wq = " << totalWaitTime / numCustomers << endl;
	cout << "Rho = " << totalServiceTime / (M * runTime) << endl;
	cout << endl
		 << "Analytical Results:" << endl;
	cout << "Po = " << Po << endl;
	cout << "L = " << L << endl;
	cout << "W = " << W << endl;
	cout << "Lq = " << Lq << endl;
	cout << "Wq = " << Wq << endl;
	cout << "Rho = " << Rho << endl;
}
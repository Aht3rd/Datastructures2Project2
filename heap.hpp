/***************************************************************
  Student Name: Thomas, Arthur
  File Name: heap.hpp
  Assignment number: Project 2

  Heap class for the priority queue of customer objects
***************************************************************/

#ifndef HEAP_HPP
#define HEAP_HPP
#include "customer.hpp"
#include "queue.hpp"
#include "analytics.hpp"
#include <iomanip>
#include <string>
#include <ctime>

class Heap
{
private:
	float lambda = 0;
	float mu = 0;
	float M = 0;
	float serversAvailable = 0;
	float numArrivals = 0;
	float numCustomers = 0;
	static const int PQSize = 200;
	Customer *priorityQ[PQSize + 1];
	Queue FIFOQ;
	int PQCount = 0;
	float totalWaitTime = 0;
	float totalServiceTime = 0;
	float idleTime = 0;
	float runTime = 0;
	float GetNextRandomInterval(float avg);
	void EventLoop();
	void ProcessNextEvent();
	void PercolateDown(int);
	void RefillPQ();
	void ProcessStatistics();
	void ShowResults();

public:
	Heap(float n, float lambda, float mu, float M);
};
#endif
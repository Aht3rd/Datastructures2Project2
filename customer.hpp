/***************************************************************
  Student Name: Thomas, Arthur
  File Name: customer.hpp
  Assignment number: Project 2

  Header file for customer class
***************************************************************/

#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP
#include <iostream>
using namespace std;

class Customer
{
private:
	float arrivalTime = 0.0;
	float startOfServiceTime = 0.0;
	float waitTime = 0.0;
	float departureTime = 0.0;
	Customer *nextCust = nullptr;
	bool isArrival = true;

public:
	Customer(float arrival, bool state);
	void SetArrivalTime(float time);
	float GetArrivalTime();
	void SetStartOfServiceTime(float time);
	float GetStartOfServiceTime();
	void SetWaitTime(float time);
	float GetWaitTime();
	void SetDepartureTime(float time);
	float GetDepartureTime();
	void SetNextCustomer(Customer *next);
	Customer *GetNextCustomer();
	void SetIsArrival(bool state);
	bool GetIsArrival();
};
#endif
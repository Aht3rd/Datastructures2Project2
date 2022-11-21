/***************************************************************
  Student Name: Thomas, Arthur
  File Name: customer.cpp
  Assignment number: Project 2
***************************************************************/

#include "customer.hpp"

Customer::Customer(float arrival, bool state)
    : arrivalTime(arrival), departureTime(arrival), isArrival(state)
{
    this->startOfServiceTime = 0.0;
    this->waitTime = 0.0;
    this->nextCust = nullptr;
}

void Customer::SetArrivalTime(float time)
{
    this->arrivalTime = time;
}

float Customer::GetArrivalTime()
{
    return this->arrivalTime;
}

void Customer::SetStartOfServiceTime(float time)
{
    this->startOfServiceTime = time;
}

float Customer::GetStartOfServiceTime()
{
    return this->startOfServiceTime;
}

void Customer::SetWaitTime(float time)
{
    this->waitTime = time;
}

float Customer::GetWaitTime()
{
    return this->waitTime;
}

void Customer::SetDepartureTime(float time)
{
    this->departureTime = time;
}

float Customer::GetDepartureTime()
{
    return this->departureTime;
}

void Customer::SetNextCustomer(Customer *next)
{
    this->nextCust = next;
}

Customer *Customer::GetNextCustomer()
{
    return this->nextCust;
}

void Customer::SetIsArrival(bool state)
{
    this->isArrival = state;
}

bool Customer::GetIsArrival()
{
    return this->isArrival;
}
/***************************************************************
  Student Name: Thomas, Arthur
  File Name: queue.cpp
  Assignment number: Project 2
***************************************************************/

#include "queue.hpp"

Queue::Queue()
{
    this->first = nullptr;
    this->last = nullptr;
}

void Queue::insert(Customer *add)
{
    if (IsEmpty())
    {
        this->first = add;
        this->last = add;
    }
    else
    {
        this->last->SetNextCustomer(add);
        this->last = add;
    }
}
Customer *Queue::remove()
{
    Customer *tmp = this->first;
    this->first = this->first->GetNextCustomer();
    return tmp;
}

bool Queue::IsEmpty()
{
    if (this->first == nullptr)
        return true;
    else
        return false;
}
/***************************************************************
  Student Name: Thomas, Arthur
  File Name: queue.hpp
  Assignment number: Project 2

  Queue class for the FIFO queue of customer objects
***************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "customer.hpp"

class Queue
{
private:
    Customer *first = nullptr;
    Customer *last = nullptr;

public:
    Queue();
    void insert(Customer *add);
    Customer *remove();
    bool IsEmpty();
};
#endif
/***************************************************************
  Student Name: Thomas, Arthur
  File Name: main.cpp
  Assignment number: Project 2

  Main.cpp to take parameters from the user and build the program
***************************************************************/

#include "heap.hpp"

int main()
{
  float n;
  float lambda;
  float mu;
  float M;
  cout << "Enter the number of arrivals to simulate" << endl;
  cin >> n;
  cout << endl << "Enter the average arrivals in a time period." << endl;
  cin >> lambda;
  cout << endl << "Enter the average number served in a time period." << endl;
  cin >> mu;
  cout << endl << "Enter the number of server channels (1 to 10)." << endl;
  cin >> M;
  while((M < 1) | (M > 10))
  {
    cout << "Invalid value entered for the number of service channels. Please enter a value between 1 and 10." << endl;
    cin >> M;
  }

  Heap(n, lambda, mu, M);

  return 0;
}
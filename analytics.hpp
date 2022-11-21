/***************************************************************
  Student Name: Thomas, Arthur
  File Name: analytics.hpp
  Assignment number: Project 2

  Analytics class for analytical results
***************************************************************/

#ifndef ANALYTICS_HPP
#define ANALYTICS_HPP
#include <cmath>

class Analytics
{
private:
    float lambda = 0;
    float mu = 0;
    float M = 0;
    float Po = 0;
    float L = 0;
    float W = 0;
    float Lq = 0;
    float Wq = 0;
    float Rho = 0;
    float Fact(float n);

public:
    Analytics(float lambda, float mu, float M);
    float GetPo(); 
    float GetL();
    float GetW();
    float GetLq();
    float GetWq();
    float GetRho();
    };
#endif
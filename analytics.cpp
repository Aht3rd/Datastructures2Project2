/***************************************************************
  Student Name: Thomas, Arthur
  File Name: analytics.cpp
  Assignment number: Project 2
***************************************************************/

#include "analytics.hpp"

Analytics::Analytics(float lambda, float mu, float M)
    : lambda(lambda), mu(mu), M(M)
{
    float den = 0;
    for (float i = 0; i < M; i++)
    {
        den += (1 / Fact(i)) * pow((lambda / mu), i);
    }
    den += (1 / Fact(M)) * pow(lambda / mu, M) * (M * mu) / (M * mu - lambda);
    Po = 1 / den;
    L = ((double)Po * lambda * mu * pow(lambda / mu, M)) / (Fact(M - 1) * pow(M * mu - lambda, 2)) + lambda / mu;
    W = L / lambda;
    Lq = L - (lambda / mu);
    Wq = Lq / lambda;
    Rho = lambda / (M * mu);
}

float Analytics::Fact(float n)
{
    float fact = 1;
    float j;
    for (j = 1; j <= n; j++)
        fact = fact * j;
    return fact;
}

float Analytics::GetPo()
{
    return Po;
}

float Analytics::GetL()
{
    return L;
}

float Analytics::GetW()
{
    return W;
}

float Analytics::GetLq()
{
    return Lq;
}

float Analytics::GetWq()
{
    return Wq;
}

float Analytics::GetRho()
{
    return Rho;
}
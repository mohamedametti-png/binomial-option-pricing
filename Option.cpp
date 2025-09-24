#include "Option.h"
#include<algorithm> 
EuropeanOption::EuropeanOption(double strike, bool call) :K(strike), isCall(call)
{
}

double EuropeanOption::payoff(double S) const
{
	if (isCall) return std::max(S - K, 0.0);
	else        return std::max(K - S, 0.0); 
}

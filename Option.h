#pragma once
class Option
{
public:
	virtual double payoff(double S) const = 0;//méthode virtuelle
	virtual ~Option()=default; //destructeur 
};
class EuropeanOption :public Option {
public:
    EuropeanOption(double strike, bool call);
	double payoff(double S) const;
private: 
	double K;
	bool isCall; //true=call false=put
};


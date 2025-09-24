#pragma once
#include "Option.h"
class BinomialModel {
    double S0, R, sigma, T;
    int n;
public:
    BinomialModel(double S0_, double R_, double sigma_, double T_, int n_)
        : S0(S0_), R(R_), sigma(sigma_), T(T_), n(n_) {
    }

    double price(const Option& opt) const;
};


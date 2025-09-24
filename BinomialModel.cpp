#include "BinomialModel.h"
#include <vector>

double BinomialModel::price(const Option& opt) const{

        double r = R * T / n;
        double u = (1 + r) * exp(sigma * sqrt(T / n));
        double d = (1 + r) * exp(-sigma * sqrt(T / n));
        double disc = 1.0 / (1 + r);
        double q = (1 + r - d) / (u - d);

        // terminal prices
        std::vector<double> ST(n + 1);
        ST[0] = S0 * pow(d, n);
        double ratio = u / d;
        for (int j = 1; j <= n; ++j) {
            ST[j] = ST[j - 1] * ratio;
        }

        // terminal payoff
        std::vector<double> value(n + 1);
        for (int j = 0; j <= n; ++j) {
            value[j] = opt.payoff(ST[j]);
        }

        // backward induction
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                value[j] = disc * (q * value[j + 1] + (1 - q) * value[j]);
            }
        }

        return value[0];
    
}

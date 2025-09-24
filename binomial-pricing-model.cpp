#include<iostream>
#include <vector>
#include<cmath>
#include "BinomialModel.h"
#include "Option.h"
using namespace std; 
double binomial_price_european(double S0, double K, double R, double sigma, double T, int n, bool isCall/*true=call, false=put*/) {
    vector<double> S(n+1);
    double r = R * T / n;
    double u = (1 + r) * exp(sigma * sqrt(T / n));
    double d = (1 + r) * exp(-sigma * sqrt(T / n));
    double disc = 1 / (1 + r);
    double q = (1+r-d)/(u-d);
    S[0] = S0 * pow(d, n);
    for (int j(1); j <= n; j++) {
        S[j] = S[j - 1] * (u / d);
    }
     vector<double> value(n + 1);
     if (isCall) {//Payoff terminal d'un call
         for (int j(0); j <= n; ++j) {
             value[j] = max(S[j] - K, 0.0);
         }  
         for (int i(n - 1);i >= 0;i--) {
             for (int j(0); j <= i; j++) {
                 value[j] = disc * (q * value[j + 1] + (1 - q) * value[j]);
             }
         }
         return value[0];
     }
     
     }
 
int main()
{//Initialisation des paramètres du marché 
    // Nombre de périodes (profondeur de l'arbre binomial)
    double S0(100.0);
    double K(120);
    int n(5);
    double sigma(0.03);
    // Maturité de l'option (en mois par exemple)
    double T(5);
    // Taux d'intérêt continu annualisé (ici 5%)
    double R(0.05);
    double disc = 1 / (1 + R * T / n);
    double C0(binomial_price_european(S0, K, R, sigma, T, n, true));
    cout << "Le prix du call selon le modèle binomial est " << C0;
    //Par parité call-put 
    double P0 = C0 - S0 + K * pow(disc, n);
    cout << "Le prix d'un put de même strike et même échéance EST " << P0; 
    return 0; 
}

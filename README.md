# Binomial Option Pricing

This repository implements an **n-period Binomial Tree model** for pricing **European** options, with both a C++ implementation (object-oriented) and a Python Jupyter notebook for numerical experiments and plots.

> **Note:** This project focuses on *European* call/put pricing and convergence to the Black–Scholes model. There is no implementation for American options in this repository.

---

## About / Context

This project was inspired by an exercise recently studied in class, where we provided the **mathematical proof of the convergence of the binomial model to the Black–Scholes formula**.  
Motivated by this, I decided to implement the model from scratch:  
- in **C++**, using object-oriented programming to structure the `Option` and `BinomialModel` classes,  
- and in **Python**, to run simulations and visualize convergence numerically.  

This reflects both the theoretical proof done in class and its computational realization.

## Repository contents

Files present in the repository:
- `Binomial-pricing-vanilla.ipynb` — Jupyter notebook with Python simulations and plots (distributional convergence of `log(S_T)`, visual checks).
- `binomial-pricing-model.cpp` — example driver / main program (reads parameters, runs pricing).
- `BinomialModel.cpp` / `BinomialModel.h` — implementation and header for the binomial model class.
- `Option.cpp` / `Option.h` — implementation and header for the option class (option payoff, helpers).
- `README.md` — this file.

(Checked against the repository file listing.) :contentReference[oaicite:1]{index=1}

---

## Requirements

- C++ compiler supporting C++17 (e.g. `g++`)  
- Python 3 (for the notebook), with `numpy` and `matplotlib` installed  
  ```bash
  pip install numpy matplotlib jupyter

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "term.cpp"
#include "shwe_lib.h"

using namespace std;

class Polynomial {
private:
    Term *power;
    int degree;
public:
    Polynomial();
    Polynomial(int deg);
    unsigned int get_degree() const;
    void read_data();
    int get_coefficient(unsigned int power);
    void set_coefficient(int coefficient, unsigned int power);
    Polynomial& multiply(int x);
    friend Polynomial operator+(const Polynomial &a, const Polynomial &b);
    friend Polynomial operator-(const Polynomial &p);
    void print() const;
    void re_alloc_term();
};

#endif

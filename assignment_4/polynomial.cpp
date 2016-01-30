#include <string>
#include <sstream>
#include <iostream>

#include "polynomial.h"

/*
 * Polynomial() - default constructor
 *
 * set degree to 0 and coefficient to 1;
 */
Polynomial::Polynomial()
{
    power = new Term[1];
    degree = 0;
    power[0].coefficient = 1;
}

/*
 * Polynomial(int deg) - constructor that take int argument
 * @deg: degree 
 * 
 * set degree to deg and set all coefficient to 1;
 */
Polynomial::Polynomial(int deg)
{
    power = new Term[deg + 1];
    degree = deg;
    for (int i = 0; i <= degree; i++) {
        power[i].coefficient = 1;
    }
}

/*
 * get_degree() - get the degree of the polynomial class
 * 
 * loop till the end of degree and return the actual degree, 0x^n won't be
 * the actual degree.
 */
unsigned int Polynomial::get_degree() const
{
    int actual_deg = 0;
    for (int i = 0; i <= degree; i++) {
        if (power[i].coefficient != 0) {
            actual_deg = i;
        }
    }
    return actual_deg;
}

/*
 * get_coefficient - get coefficient of the power
 * @n: number of power
 *
 * return coefficient of the power
 */
int Polynomial::get_coefficient(unsigned int n)
{
    return power[n].coefficient;
}

/*
 * set_coefficient - set the coefficient
 * @n: number of power
 *
 * set the coefficient of the that powered term
 */
void Polynomial::set_coefficient(int coefficient, unsigned int n)
{
    power[n].coefficient = coefficient;
}

/*
 * operator+ - overloaded operator+ 
 * @a: equation 1
 * @b: equation 2
 *
 * create a temp equation and add the two equation and put the result into temp
 * and copy the rest if one equation is longer
 * and return temp equation
 */
Polynomial operator+(const Polynomial &a, const Polynomial &b)
{
    int actual_deg = (a.degree > b.degree ? a.degree : b.degree);
    Polynomial tmp(actual_deg);
    int copy_deg = (a.degree > b.degree ? b.degree : a.degree);
    for (int i = 0; i <= copy_deg; i++) {
        tmp.power[i].coefficient = a.power[i].coefficient +
                                   b.power[i].coefficient;
    }
    
    for (int x = copy_deg + 1; x <= a.degree; x++)
        tmp.power[x].coefficient = a.power[x].coefficient;
    
    for (int y = copy_deg + 1; y <= b.degree; y++)
        tmp.power[y].coefficient = b.power[y].coefficient;
    return tmp;
}

/*
 * operator- negation operator
 * @p: equation
 *
 * multiply all the coefficient with -1 and put it to temp and return temp
 */
Polynomial operator-(const Polynomial &p)
{
    unsigned int deg = p.get_degree();
    Polynomial tmp(deg);
    for (unsigned int i = 0; i <= p.get_degree(); i++) {
        tmp.power[i].coefficient = p.power[i].coefficient * -1;
    }
    return tmp;
}

/*
 * print - print the polynomial
 *
 * if coefficient is 0, don't print it
 * if coefficient is positive, print +, otherwise, print -.
 * and print absoluto val of coefficient so that there won't be two negative
 * showing on console.
 */
void Polynomial::print() const
{    
    cout << "The degree of equation is " << degree << ".\n";
    for (int i = degree; i >= 0; i--) {
        if (power[i].coefficient == 0)
            continue;
        if (power[i].coefficient < 0)
            cout << " - ";
        else
            cout << " + ";
        cout << abs(power[i].coefficient) << "x^" << i;
    }
    cout << endl;
}

/*
 * re_alloc_term - reallocate the struct term
 *
 * create tmp term struct
 * make power struct point to it
 * detele what old power point to
 */
void Polynomial::re_alloc_term()
{
    Term *tmp = new Term[degree + 1];
    Term *to_del = power;
    power = tmp;
    delete[] to_del;    
}

/*
 * read_data - read data for equation
 *
 * get the degree of equation by using helper function
 * re-alloc power because it is too small for new degree
 * get each coefficient from user input
 */
void Polynomial::read_data()
{
    int deg = cin_degree();
    if (deg > degree) {
        degree = deg;
        this->re_alloc_term();
    }
    for (int i = 0; i <= degree; i++) {
        power[i].coefficient = cin_coefficient(i);
    }
}

/*
 * multiply - multiply equation by x
 * @x: integer
 *
 * multiply all terms by x
 */
Polynomial& Polynomial::multiply(int x)
{
    for (int i = 0; i <= degree; i++) {
        power[i].coefficient = x * power[i].coefficient;
    }
    return *this;
}

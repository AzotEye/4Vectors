#include <iostream>
#include <exception>
#include <fstream>
#include <sstream>
#include "HeaderVect.h"

Vect::Vect()
{
    this->n = 0;
    this->x = nullptr;
}
Vect::Vect(int n)
{
    this->n = n;
    this->x = new double[n];
}
Vect::Vect(const Vect& v)
{
    this->n = v.n;
    this->x = new double[this->n];
    for (int i = 0; i < this->n; i++)
    {
        this->x[i] = v.x[i];
    }
}
Vect::~Vect()
{
    delete [] this->x;
}

Vect Vect::operator+(const Vect& v)
{
    if (this->n != v.n)
    {
        throw std::exception("Dimentions are not the same");
    }
    Vect res(this->n);
    for (int i = 0; i < this->n; i++)
    {
        res.x[i] = this->x[i] + v.x[i];
    }
    return res;
}
Vect Vect::operator-(const Vect& v)
{
    if (this->n != v.n)
    {
        throw std::exception("Dimentions are not the same");
    }
    Vect res(this->n);
    for (int i = 0; i < this->n; i++)
    {
        res.x[i] = this->x[i] - v.x[i];
    }
    return res;
}
double Vect::operator*(const Vect& v)
{
    if (this->n != v.n)
    {
        throw std::exception("Dimentions are not the same");
    }
    double res = 0;
    for (int i = 0; i < this->n; i++)
    {
        res = res + (this->x[i] * v.x[i]);
    }
    return res;
}
const Vect& Vect::operator=(const Vect& v)
{
    this->n = v.n;
    this->x = new double[this->n];
    for (int i = 0; i < this->n; i++)
    {
        this->x[i] = v.x[i];
    }
    return *this;
}

std::istream& operator>>(std::istream& in, Vect& v)
{
    std::cout << "Input n: ";
    in >> v.n;
    std::cout << "Input x: ";
    if (v.x != nullptr)
    {
        delete [] v.x;
    }
    v.x = new double[v.n];
    for (int i = 0; i < v.n; i++)
    {
        in >> v.x[i];
    }
    return in;
}
std::ostream& operator<<(std::ostream& out, const Vect& v)
{
    out << "Vector: ";
    for (int i = 0; i < v.n; i++)
    {
        out << v.x[i] << " ";
    }
    return out;
}

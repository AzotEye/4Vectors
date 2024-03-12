#include <iostream>
#include <exception>
#include <fstream>
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

//Vect& Vect::operator=(const Vect& v)
//{
//    this->n = v.n;
//    this->x = new double[this->n];
//    for (int i = 0; i < this->n; i++)
//    {
//        this->x[i] = v.x[i];
//    }
//    return *this;
//}

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

void fill(const char* filename, Vect& v1, Vect& v2)
{
    std::ifstream in(filename);
    if (in.is_open())
    {
        in >> v1.n;
        v1.x = new double[v1.n];
        for (int i = 0; i < v1.n; i++)
        {
            in >> v1.x[i];
        }
        in >> v2.n;
        v2.x = new double[v2.n];
        for (int i = 0; i < v2.n; i++)
        {
            in >> v2.x[i];
        }
    }
    in.close();
}
void write(const char* filename, Vect& summ, Vect& subb, double& mult)
{
    std::ofstream out(filename);
    if (out.is_open())
    {
        out << "Summ: " << summ << std::endl;
        out << "Subb: " << subb << std::endl;
        out << "Mult: " << mult << std::endl;
    }
    out.close();
}
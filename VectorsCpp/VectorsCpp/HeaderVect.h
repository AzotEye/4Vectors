#pragma once

#include <iostream>
#include <fstream>

struct Vect
{
    int n;
    double* x;

    Vect();
    Vect(int n);
    Vect(const Vect& );
    ~Vect();

    Vect operator+(const Vect& );
    Vect operator-(const Vect& );
    const Vect& operator=(const Vect&);
    double operator*(const Vect& );

    friend std::ofstream& operator<<(std::ofstream& out, Vect& v)
    {
        out << "Vector: ";
        for (int i = 0; i < v.n; i++)
        {
            out << v.x[i] << " ";
        }
        out << std::endl;
        return out;
    }
    friend std::ifstream& operator>>(std::ifstream& in, Vect& v)
    {
        in >> v.n;
        if (v.x != nullptr)
        {
            delete[] v.x;
        }
        v.x = new double[v.n];
        for (int i = 0; i < v.n; i++)
        {
            in >> v.x[i];
        }
        return in;
    }
};

std::istream& operator>>(std::istream& in, Vect& v);
std::ostream& operator<<(std::ostream& out, const Vect& v);

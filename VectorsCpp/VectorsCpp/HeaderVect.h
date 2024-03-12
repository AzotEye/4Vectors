#pragma once

#include <iostream>

struct Vect
{
    int n;
    double* x;

    Vect();//конструктор по умолчанию
    Vect(int n);//конструктор с параметром
    Vect(const Vect& );//конструктор копирования!!!
    ~Vect();//деструктор!!!
    //перегрузка операций
    Vect operator+(const Vect& );
    Vect operator-(const Vect& );
    double operator*(const Vect& );
};


std::istream& operator>>(std::istream& in, Vect& v);
std::ostream& operator<<(std::ostream& out, const Vect& v);

void fill(const char* filename, Vect &v1, Vect &v2);
void write(const char* filename, Vect &summ, Vect &subb, double &mult);
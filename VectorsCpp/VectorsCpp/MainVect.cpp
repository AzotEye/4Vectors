#include <iostream>
#include "HeaderVect.h"

int main(int argc, char ** argv)
{
    char* infile, * outfile;
    if (argc < 4)
    {
        std::cout << "Wrong arguments";
        return 1;
    }
    infile = argv[2];
    outfile = argv[3];
    Vect v1, v2;
    fill(infile, v1, v2);
    std::cout << v1;
    std::cout << v2;
    Vect summ = v1 + v2, subb = v1 - v2;
    double mult = v1 * v2;
    write(outfile, summ, subb, mult);
    std::cout << summ;
    std::cout << subb;
    std::cout << mult;
    return 0;
}
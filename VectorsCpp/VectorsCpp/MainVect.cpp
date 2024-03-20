#include <iostream>
#include "HeaderVect.h"

int main(int argc, char ** argv)
{
    std::ofstream off;
    std::ifstream in;
    char* infile, * outfile;

    if (argc < 3)
    {
        std::cout << "Wrong arguments";
        return 1;
    }
    infile = argv[1];
    outfile = argv[2];

    Vect v1, v2;

    in.open(infile);
    in >> v1 >> v2;
    in.close();

    std::cout << v1;
    std::cout << v2;

    Vect summ = v1 + v2, subb = v1 - v2;
    double mult = v1 * v2;

    off.open(outfile);
    off << summ << subb << mult;
    off.close();

    return 0;
}
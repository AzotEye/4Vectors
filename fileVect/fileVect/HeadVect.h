#ifndef FUNC

#define FUNC

typedef struct {
    int n;
    double* x;
}Tvect;

void allo(Tvect* v, int n);
Tvect summ(Tvect* v1, Tvect* v2);
Tvect subb(Tvect* v1, Tvect* v2);
double mult(Tvect* v1, Tvect* v2);
void fill(const char* filename, Tvect* v1, Tvect* v2);
void print(Tvect* v);
void write(const char* filename, Tvect* sum, Tvect* sub, double* mult);

#endif
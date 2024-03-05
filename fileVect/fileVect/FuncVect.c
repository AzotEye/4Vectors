#include "HeadVect.h"
#include <stdlib.h>
#include <stdio.h>


void allo(Tvect* v, int n)
{
    v->n = n;
    v->x = (double*)malloc(sizeof(double) * n);
}
Tvect summ(Tvect* v1, Tvect* v2)
{
    Tvect sum;
    int i = 0;
    if (v1->n != v2->n)
    {
        printf("error");
        sum.x = NULL;
        sum.n = 0;
        return sum;
    }
    allo(&sum, v1->n);
    for (i = 0; i < sum.n; i++)
    {
        sum.x[i] = v1->x[i] + v2->x[i];
    }
    return sum;
}
void fill(const char* filename, Tvect* v1, Tvect* v2)
{
    int i = 0;
    FILE* f = fopen(filename, "r");
    if (f == NULL)
    {
        printf("File not found");
        abort();
    }
    fscanf(f, "%d", &(v1->n));
    v1->x = (double*)malloc(v1->n * sizeof(double));
    for (; i < (v1->n); i++)
    {
        fscanf(f, "%lf", &(v1->x[i]));
    }
    fscanf(f, "%d", &(v2->n));
    v2->x = (double*)malloc(v2->n * sizeof(double));
    for (i = 0; i < (v2->n); i++)
    {
        fscanf(f, "%lf", &(v2->x[i]));
    }
    fclose(f);
}
void write(const char* filename, Tvect* sum, Tvect * sub, double* mult)
{
    int i = 0;
    FILE* f = fopen(filename, "w+");
    if (f == NULL)
    {
        printf("File not found");
        abort();
    }
    fprintf(f, "Summ = ");
    for (; i < sum->n; i++)
    {
        fprintf(f, "%lf ", sum->x[i]);
    }
    fprintf(f, "\nSubb = ");
    for (i = 0; i < sub->n; i++)
    {
        fprintf(f, "%lf ", sub->x[i]);
    }
    fprintf(f, "\nMult = %lf\n", *mult);
    fclose(f);
}
void print(Tvect* v)
{
    int i = 0;
    for (i = 0; i < v->n; i++)
    {
        printf("%lf ", v->x[i]);
    }
    printf("\n");
}
Tvect subb(Tvect* v1, Tvect* v2)
{
    Tvect sub;
    int i = 0;
    if (v1->n != v2->n)
    {
        printf("error");
        sub.x = NULL;
        sub.n = 0;
        return sub;
    }
    allo(&sub, v1->n);
    for (i = 0; i < sub.n; i++)
    {
        sub.x[i] = v1->x[i] - v2->x[i];
    }
    return sub;
}
double mult(Tvect* v1, Tvect* v2)
{
    double mult = 0;
    int i = 0;
    if (v1->n != v2->n)
    {
        printf("error");
        mult = 0;
        return mult;
    }
    for (i = 0; i < v1->n; i++)
    {
        mult += v1->x[i] * v2->x[i];
    }
    return mult;
}
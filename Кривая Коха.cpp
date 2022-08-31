#include <iostream>
#include <cmath>
#include <stdlib.h>
#include "TXLib.h"
#define pi atan(1)*4

using namespace std;

void LineKoha(double x0, double y0, double a, double p, int m);

int main()
{


    int m = 5;
    int ugol = 3;
    double p = 0;
    static double x0 = 200;
    static double y0 = 400;
    double a = 300;

    txCreateWindow(1000, 1000);


    for (int i = 0; i < ugol; i++)
    {
        LineKoha(x0, y0, a, p, m);
        x0 = x0 + (cos(p) * (a));
        y0 = y0 - (sin(p) * (a));
        p -= (2 * pi) / ugol;

    }
}

void LineKoha(double x0, double y0, double a, double p, int m)
{

    if (m < 1)
    {
        double x1 = x0 + (cos(p) * (a));
        double y1 = y0 - (sin(p) * (a));

        txLine(x0, y0, x1, y1);


    }
    else
    {
        LineKoha(x0, y0, a/3, p, m - 1);
        double x1 = x0 + (cos(p) *(a/3));
        double y1 = y0 - (sin(p) *  (a/3));

        LineKoha(x1, y1, a / 3, p + pi/3, m - 1);
        double x2 = x1 + (cos(p+pi/3) *(a/3));
        double y2 = y1 - (sin(p+pi/3) *  (a/3));

        LineKoha(x2, y2, a/3, p - pi/3, m - 1);
        double x3 = x2 + (cos(p-pi/3) *(a/3));
        double y3 = y2 - (sin(p-pi/3) *  (a/3));

        LineKoha(x3, y3, a/3, p, m - 1);

    }


}

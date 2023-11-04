// The C++ standard version:
#include <cstdio>
#include <cmath>
#include <fstream>
#include <iostream>
using namespace std ;

int main(int argc, char** argv)
{
    // Declaring 2D array
    int arr[4][4];

    // Initialize 2D array using loop
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            arr[i][j] = i + j;
        }
    }
    return 0;
};

//example function in cpp
void pred_corr(double x[],double h,int i,double dxdt[])
{
    double
    gam=1.,
    beta=2.
    ;
    double n =7;
    //predictor step
    dxdt[i]=beta*x[i-tau]/(1+pow(x[i-tau],n))-gam*x[i];
    x[i+1]=x[i]+h/12.*(23.*dxdt[i]-16.*dxdt[i-1]+5.*dxdt[i-2]);
    //corrector step
    dxdt[i+1]=beta*x[i+1-tau]/(1+pow(x[i+1-tau],n))-gam*x[i+1];
    x[i+1]=x[i]+h/12.*(5.*dxdt[i+1]+8.*dxdt[i]-dxdt[i-1]);
}
;

// The C++ standard version:
#include <cstdio>
#include <cmath>
#include <fstream>
#include <iostream>
using namespace std ;

void output(int ti, int xi, double t[], double x[], double phi[]);
void init(double t[], double x[], double phi[], int xsteps, double L);
void output(int ti, int xi, double t[], double x[], double phi[]){
    // Declaring 2D array
    // t x phi
    cout << t[ti] << ' ' << x[xi] << ' ' <<  phi[xi] << endl;
}
void init(double t[], double x[], double phi[], int xsteps, double dx, double L){
    t[0]=0;
    //x[0]=0;
    for (int i = 0; i <= xsteps; i=i+1) {
        phi[i] = exp(pow(sin(M_PI/L*(i*dx)),2))-1;
        x[i]=i*dx;
        output(0,i,t,x,phi);
	}
}

const double CSpeed=1;
const double CMax = 1;
const double dx = 0.05;
const double L = 1; // gridSpace
const double timeLength = 1;
const double dt = CMax*dx/CSpeed;
const int xSteps = int( L / dx );
const int tSteps = int (timeLength / dt );

double // Kommentar
    x[xSteps],
    t[tSteps],
    phi[xSteps]
    ;

int main(int argc, char** argv)
{

    init(t, x, phi, xSteps, dx, L);


    // cases for solver
    //{{solving method second order}}
    //{{solving method forth order}}

	// Initialize 2D array using loop
	//for (int i = 0; i < 4; i++) {
	//	for (int j = 0; j < 4; j++) {
	//		arr[i][j] = i + j;
	//	}
	//}
	return 0;
};



//example function in cpp
//void pred_corr(double x[],double h,int i,double dxdt[])
//{
//	double
//	gam=1.,
//	beta=2.
//	;
//	double n =7;
//	//predictor step
//	dxdt[i]=beta*x[i-tau]/(1+pow(x[i-tau],n))-gam*x[i];
//	x[i+1]=x[i]+h/12.*(23.*dxdt[i]-16.*dxdt[i-1]+5.*dxdt[i-2]);
	//corrector step
//	dxdt[i+1]=beta*x[i+1-tau]/(1+pow(x[i+1-tau],n))-gam*x[i+1]; x[i+1]=x[i]+h/12.*(5.*dxdt[i+1]+8.*dxdt[i]-dxdt[i-1]);
//};

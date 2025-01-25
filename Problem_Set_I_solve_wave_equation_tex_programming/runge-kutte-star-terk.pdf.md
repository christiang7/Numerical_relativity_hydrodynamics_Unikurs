Content-Type: text/x-zim-wiki
Wiki-Format: zim 0.6
====== runge-kutte-star-terk.pdf ======
Text date: [[Zettelkasten:2025:01:25|2025-01-25]] Modi date: [[Zettelkasten:2023:11:27|2023-11-27]]
@ARTIKEL  
**[[./runge-kutte-star-terk.pdf]] **



{{./runge-kutte-star-terk.pdf.avif?width=500}}

Pages:           10


1 /****************** planet-system ******************/
2
3 using namespace std;
4 #include <stdlib.h>
5 #include <iostream>
6 #include <fstream>
7 #include <math.h>
8
9
10 /************* important parameters **************/
11 const int neqn = 4;
// number of equations
12 bool schalter = true;
13 bool abb=false;
14 bool abb4=false;
15 const double tstep=0.001;
16 const double gen=0.001; //Genauigkeit der
Lagrangepunkte
17 const double eps=0.00001;
18 const double mu=0.05;
19 const double mu2=1-mu;
20 const double r1=0.2;
21 const double r2=0.01;
22 double omeg1,omeg2,omeg3;
23 double z1[3], z2;
//fuer das Bisektionsverfahren
24 const double pi=4.*atan(1.);
25 //const double alpha=0.0995*pi;
26
27 /
******************************************************
/
28 int sgn(double h){
29
if (h==0)
return 0;
30
else
return (h>0) ? 1 : -1;
31 }
32 /******************** Runge-Kutta solver
**********************************/
33 void rk(double y[],int n,double x,double h,
34
void (derivs)(double, double[], double[]))
35 {
36
int j,i;
37
double h2,h6,xh, xhh,y1[n],k1[n],k2[n],k3[n];
38
h2=h*0.5;
h6=h/6.;

istian/Gedankenspeicher/Studium/Star-Trek-CP-MP-3/star_trek.cpp


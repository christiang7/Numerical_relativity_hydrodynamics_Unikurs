# Problem Set I solve wave equation
Created [2023-11-04]()

- [X] **Problem Set I solve wave equation**
	- [X] Doing
        - [ ] A.2. Programming
            - [X] all fields have to get two dimensions not just one, because, the time step needs two points
            - [ ] implement the midpoints for x positions
            - [ ] look at the correct array length
            - [ ] Runge Kutter method
	- [X] Backlog
        - [ ] A.1.
            - [X] writing in first order equation the wave equation
            - [ ] calculation of eigenvectors and eigenvalues of matrix A

## Features

## Informations

### Log

#### 2023-11-26 working simulation
gnuplot live plotting is working
- [X] Forward Euler method
- [X] boundaryCondition add ghost points
    - [X] add more points to the arrays (left two and right two), but plotting only the real points
    - [X] rewrite the for loops
    - [X] implement the switching between these points
    - [X] split the code for the points for not ghost points and the function for the ghost point calculation

#### 2023-11-16 working initial condition
- [X] calc initial condition
- [X] gnuplot
- [X] flexible for initial condition with start values
- [X] writing script for compilation


<object data="Problem_Set_I_solve_wave_equation_tex_programming/ps1_NRII.pdf" type="application/pdf" width="100%" height="700px">
	<p>Unable to display PDF file. <a href="Problem_Set_I_solve_wave_equation_tex_programming/ps1_NRII.pdf">Download</a> instead.</p>
</object>

<object data="Problem_Set_I_solve_wave_equation_tex_programming/Problem_Set_I_solve_wave_equation.pdf" type="application/pdf" width="100%" height="700px">
	<p>Unable to display PDF file. <a href="Problem_Set_I_solve_wave_equation_tex_programming/Problem_Set_I_solve_wave_equation.pdf">Download</a> instead.</p>
</object>

Euler method - Wikipedia
https://en.wikipedia.org/wiki/Euler_method
Runge–Kutta methods - Wikipedia
https://en.wikipedia.org/wiki/Runge%E2%80%93Kutta_methods
1.2: Forward Euler method - Mathematics LibreTexts
https://math.libretexts.org/Bookshelves/Differential_Equations/Numerically_Solving_Ordinary_Differential_Equations_(Brorson)/01%3A_Chapters/1.02%3A_Forward_Euler_method

Running Gnuplot as a live graph, with automatic updates | Horatio Caine's Blog
http://hxcaine.com/blog/2013/02/28/running-gnuplot-as-a-live-graph-with-automatic-updates/

Fourth order finite difference | AnonymousOverflow
https://overflow.hostux.net/exchange/math/questions/3964484/fourth-order-finite-difference

## Programming

```bash
noweb.py -Rlaunch.sh Problem_Set_I_solve_wave_equation.md > launch.sh && ./launch.sh
```

```bash
{{launch.sh}}=
#!/bin/bash
# compilation and execution of program
noweb.py -RProblem_Set_I_solve_wave_equation.cpp Problem_Set_I_solve_wave_equation.md > Problem_Set_I_solve_wave_equation.cpp && g++ -o Problem_Set_I_solve_wave_equation Problem_Set_I_solve_wave_equation.cpp

# live gnuplot plot
#./Problem_Set_I_solve_wave_equation 0.01 | gnuplot -p -e "plot '-' using 2:3"
./Problem_Set_I_solve_wave_equation 0.01 40000 | gnuplot -p
#./Problem_Set_I_solve_wave_equation 0.01 2


#data output and plot
#./Problem_Set_I_solve_wave_equation 0.01 4000 > 2023-11-26-data.dat
#cat 2023-11-26-data.dat | gnuplot -p


# create pdf latex file
noweb.py -RProblem_Set_I_solve_wave_equation.tex Problem_Set_I_solve_wave_equation.md > Problem_Set_I_solve_wave_equation.tex && pdflatex -shell-escape Problem_Set_I_solve_wave_equation.tex > /dev/null
@
```


```cpp
{{Problem_Set_I_solve_wave_equation.cpp}}=
#include <cstdio>
#include <cmath>
#include <fstream>
#include <iostream>
using namespace std ;

{{function declaration}}

{{output}}

{{init}}

{{boundaryCondition}}

{{second order spatial derivative}}

{{forwad Euler method}}

{{solving wave equation}}

{{update Functions in time}}

{{gnuplot}}

{{runge kutta solver}}

{{wave DGL}}

int main(int argc, char** argv)
{
    const double CSpeed = 1;
    const double CMax = 0.005;
    const double dx = stod(argv[1]); //
    const double L = 1; // gridSpace
    const double timeLength = 1;
    const double dt = CMax*dx/abs(CSpeed);
    const int nGhosts = 4;
    const int xSteps = int( L / dx ) + nGhosts;
    //const int tSteps = int (timeLength / dt );
    const int tSteps = int ( stod(argv[2]));

    double //
    x[xSteps],
    t=0,
    phi[xSteps][2],
    chi[xSteps][2],
    eta[xSteps][2]
    ;

    cout << "# parameters dx=" << dx << " dt=" << dt << " xSteps=" <<  xSteps << endl;

    init(t, x, phi, eta, chi, xSteps, dx, L);

    // cases for solver
    //{{solving wave equation}}
    solvingWaveEquation(phi, eta, chi, t, dt, x, dx, CSpeed, xSteps, tSteps);

    //{{forth order spatial derivative}}
    //{{Runge Kutter solver}}
	return 0;
};
@
```

```cpp
{{runge kutta solver}}=
void rungekuttaSolver(double y[],int n, double t, double dt, double dx, void (derivs)(double, double[], double[])){
    int j,i;
    double dt2,dt6,tdt, tdtdt,y1[n],k1[n],k2[n],k3[n];
    dt2 = dt * 0.5;
    dt6 = dt / 6.;
    //Simpsonregel
    tdt2=t+dt*0.5;
    tdt=t+dt;
    derivs(t, y, k1);
    for(i=0;i<n;i++){
        y1[i]=y[i]+dt*0.5*k1[i];
    }
    derivs(tdt2, y1, k2);
    for(i=0;i<n;i++){
        y1[i]=y[i]-dt*k1[i]+2*dt*k2[i];
    }
    derivs(tdt, y1, k3);
    x+=h;
    for(i=0;i<n;i++){
        y[i]+=dt6*(k1[i]+4.*k2[i]+k3[i]);
    }
}
@
```


```cpp
{{wave DGL}}=
void waveDGL(double t, double y[], double dydt[], double dx){
    //dydt[0] =y[1];
    //dydt[1] =pow(CSpeed, 2)*(-y[2][i+2]+8*y[2][i+1]-8*y[2][i-1]+y[2][i-2])/(12*dx) ;
    //dydt[2] =(-y[1][i+2]+8*y[1][i+1]-8*y[1][i-1]+y[1][i-2])/(12*dx) ;
}
@
```

```cpp
{{solving wave equation}}=
void solvingWaveEquation(double phi[][2], double eta[][2], double chi[][2], double t, double dt, double x[], double dx, double CSpeed, int xSteps, int tSteps){
    for (int j = 1; j <= tSteps; j=j+1) {
        t=j*dt;
        gnuplot();
        for (int i = 2; i < xSteps-2; i=i+1) {
            forwardEulerMethod(phi, eta, dt, i, dx, 1, 0);
            forwardEulerMethod(eta, chi, dt, i, dx, pow(CSpeed, 2), 1);
            forwardEulerMethod(chi, eta, dt, i, dx, 1, 1);
            output(1, i, t, x, phi);
        };
        boundaryCondition(1, xSteps, phi, eta, chi);
        output(1, (xSteps-2), t, x, phi);
        cout << "elapsed time" << endl;
        updateFunc(xSteps, phi, eta, chi);
    };
};
@
```

```cpp
{{forwad Euler method}}=
void forwardEulerMethod(double funct[][2], double funct2[][2], double dt, int xi, double dx, double factor, int deriv){
    if (deriv == 0) {
        funct[xi][1]=funct[xi][0]+factor*dt*funct2[xi][0];
    } else {
        funct[xi][1]=funct[xi][0]+factor*dt*secondOrderSpatial(funct2, xi, dx);
    }
};
@
```


```cpp
{{second order spatial derivative}}=
double secondOrderSpatial(double funct2[][2], int xi, double dx){
    return (funct2[xi+1][0]-funct2[xi-1][0])/(2*dx);
};
@
```



```cpp
{{output}}=
void output(int ti, int xi, double t, double x[], double phi[][2]){
    // x phi
    cout << x[xi] << ' ' <<  phi[xi][ti] << endl;
};
@
```


```cpp
{{gnuplot}}=
void gnuplot(){
    cout << "plot '-' w l" << endl;
};
@
```

```cpp
{{update Functions in time}}=
void updateFunc(int xSteps, double phi[][2], double eta[][2], double chi[][2]){
    for (int i = 0; i <= xSteps; i=i+1) {
        phi[i][0] = phi[i][1];
        chi[i][0] = chi[i][1];
        eta[i][0] = eta[i][1];
	}
};
@
```

```cpp
{{init}}=
void init(double t, double x[], double phi[][2], double eta[][2], double chi[][2], int xSteps, double dx, double L){
    cout << "reset" << endl;
    cout << "set xrange [0:1]" << endl;
    cout << "set yrange [-10:10]" << endl;
    gnuplot();
    for (int i = 2; i < xSteps-2; i=i+1) {
        phi[i][0] = exp(pow(sin(M_PI/L*((i-2)*dx)),2))-1;
        //chi[i][0] = phi[i][0];
        chi[i][0] = exp(pow(sin(M_PI/L*((i-2)*dx)),2))*2*sin(M_PI/L*((i-2)*dx))*cos(M_PI/L*((i-2)*dx))*M_PI/L;
        //chi[i][0] = (i-2)*dx;
        //chi[i][0] = sin(M_PI/L*((i-2)*dx));
        //chi[i][0] = 1;
        eta[i][0] = -chi[i][0];
        //eta[i][0] = 0;
        //eta[i][0] = 1;
        //eta[i][0] = pow(sin(M_PI/L*((i-2)*dx)),2);
        //eta[i][0] = exp(pow(sin(M_PI/L*((i-2)*dx)),2))*2*sin(M_PI/L*((i-2)*dx))*cos(M_PI/L*((i-2)*dx))*M_PI/L;
        x[i]=(i-2)*dx;
        output(0, i, t, x, phi);
	}
	x[xSteps-2]=(xSteps-4)*dx;
    boundaryCondition(0, xSteps, phi, eta, chi);
    output(0, (xSteps-2), t, x, phi);

};
@
```

```cpp
{{boundaryCondition}}=
void boundaryCondition(int ti, int xSteps, double phi[][2], double eta[][2], double chi[][2]){
    phi[0][ti] = phi[xSteps-5][ti];
    eta[0][ti] = eta[xSteps-5][ti];
    chi[0][ti] = chi[xSteps-5][ti];
    phi[1][ti] = phi[xSteps-4][ti];
    eta[1][ti] = eta[xSteps-4][ti];
    chi[1][ti] = chi[xSteps-4][ti];
    phi[xSteps-3][ti] = phi[2][ti];
    eta[xSteps-3][ti] = eta[2][ti];
    chi[xSteps-3][ti] = chi[2][ti];
    phi[xSteps-2][ti] = phi[3][ti];
    eta[xSteps-2][ti] = eta[3][ti];
    chi[xSteps-2][ti] = chi[3][ti];
    phi[xSteps-1][ti] = phi[4][ti];
    eta[xSteps-1][ti] = eta[4][ti];
    chi[xSteps-1][ti] = chi[4][ti];
};
@
```

```cpp
{{function declaration}}=
void output(int ti, int xi, double t, double x[], double phi[][2]);
void init(double t, double x[], double phi[][2], double eta[][2], double chi[][2], int xSteps, double dx, double L);
void boundaryCondition(int ti, int xSteps, double phi[][2], double eta[][2], double chi[][2]);
double secondOrderSpatial(double funct2[][2], int xi, double dx);
void forwardEulerMethod(double funct[][2], double funct2[][2], double dt, int xi, double dx, double factor, int deriv);
void solvingWaveEquation(double phi[][2], double eta[][2], double chi[][2], double t, double dt, double x[], double dx, double CSpeed, int xSteps, int tSteps);
void updateFunc(int xSteps, double phi[][2], double eta[][2], double chi[][2]);
void gnuplot();
void rungekuttaSolver(double y[],int n,double x,double h, void (derivs)(double, double[], double[]));
void waveDGL(double dt, double y[], double dydt[], double dx);
@
```




## Latex File


```bash
noweb.py -RProblem_Set_I_solve_wave_equation.tex Problem_Set_I_solve_wave_equation.md > Problem_Set_I_solve_wave_equation.tex && pdflatex  -shell-escape Problem_Set_I_solve_wave_equation.tex && xdg-open Problem_Set_I_solve_wave_equation.pdf 2>/dev/null &
```


```tex
{{Problem_Set_I_solve_wave_equation.tex}}=
\documentclass[10pt,fleqn,reqno,a4paper]{article}
\input{general-preamble.tex}
\input{color-symbols.tex}
\definecolor{lightgraycolor}{rgb}{0.95,0.95,0.95}
\begin{document}%\selectlanguage{english}
\section{Problem Set I solving wave equation}

\begin{align}
	\frac{\opartial^2\nphi}{\opartial^2\ct} = c^2\frac{\opartial^2\nphi}{\opartial^2\cx}
\end{align}

\subsection{fully first order formulation}

\begin{align}
	\neta = \nphi_{,\ct}, \quad \nchi = \nphi_{,\cx}
\end{align}



$ \neta(\ct,\cx) \nchi(\ct,\cx) \vfu(\nphi,\neta,\nchi) $


\begin{align}
	\vfu_{,\ct}+\MA\vfu_{,\cx}=\vfS 
\end{align}



\subsection{initial condition}

\begin{align}
	\nphi(0, \cx)=e^{\fsin^2\left(\frac{\pi \cx}{L}\right)} -1, \quad 0 \leq \cx \leq L
\end{align}
with periodic condition:
\begin{align}
	\nphi(\ct,\cx) = \nphi(\ct, \cx \pm L)
\end{align}


\section{Program}
\begin{minted}[linenos=true,bgcolor=lightgraycolor,numberblanklines=true,showspaces=false,breaklines=true]{cpp}
{{Problem_Set_I_solve_wave_equation.cpp}}
\end{minted}
\end{document}
@
```

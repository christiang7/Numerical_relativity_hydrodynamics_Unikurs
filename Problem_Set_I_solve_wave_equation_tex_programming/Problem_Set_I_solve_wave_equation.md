# Problem Set I solve wave equation
Created [2023-11-04]()

- [X] **Problem Set I solve wave equation**
	- [X] Doing
        - [ ] A.2. Programming
            - [ ] Forward Euler method
            - [ ] boundaryCondition add ghost points
                - [ ] add more points to the arrays (left two and right two), but plotting only the real points
                - [ ] rewrite the for loops
                - [ ] implement the switiching between these points
            - [ ] Runge Kutter method
	- [X] Backlog
        - [ ] A.1.
            - [X] writing in first order equation the wave equation
            - [ ] calculation of eigenvectors and eigenvalues of matrix A

## Features
        - [X] calc initial condition
        - [X] gnuplot
        - [X] flexibel for inital condition with start values
        - [X] writing script for compilation

## Informations

<object data="Problem_Set_I_solve_wave_equation_tex_programming/ps1_NRII.pdf" type="application/pdf" width="100%" height="700px">
	<p>Unable to display PDF file. <a href="Problem_Set_I_solve_wave_equation_tex_programming/ps1_NRII.pdf">Download</a> instead.</p>
</object>

<object data="Problem_Set_I_solve_wave_equation_tex_programming/Problem_Set_I_solve_wave_equation.pdf" type="application/pdf" width="100%" height="700px">
	<p>Unable to display PDF file. <a href="Problem_Set_I_solve_wave_equation_tex_programming/Problem_Set_I_solve_wave_equation.pdf">Download</a> instead.</p>
</object>

## Programming

```bash
noweb.py -RProblem_Set_I_solve_wave_equation.cpp Problem_Set_I_solve_wave_equation.md > Problem_Set_I_solve_wave_equation.cpp && noweb.py -RProblem_Set_I_solve_wave_equation.tex Problem_Set_I_solve_wave_equation.md > Problem_Set_I_solve_wave_equation.tex && pdflatex -shell-escape Problem_Set_I_solve_wave_equation.tex && echo 'fertig'
```

```bash
noweb.py -RProblem_Set_I_solve_wave_equation.cpp Problem_Set_I_solve_wave_equation.md > Problem_Set_I_solve_wave_equation.cpp && g++ -o Problem_Set_I_solve_wave_equation Problem_Set_I_solve_wave_equation.cpp && ./Problem_Set_I_solve_wave_equation > 2023-11-16-data.dat
```

```bash
noweb.py -RProblem_Set_I_solve_wave_equation.cpp Problem_Set_I_solve_wave_equation.md > Problem_Set_I_solve_wave_equation.cpp && g++ -o Problem_Set_I_solve_wave_equation Problem_Set_I_solve_wave_equation.cpp && ./Problem_Set_I_solve_wave_equation | gnuplot -p -e "plot '-' using 2:3"
```

```bash
noweb.py -Rlaunch.sh Problem_Set_I_solve_wave_equation.md > launch.sh && ./launch.sh
```

```bash
{{launch.sh}}=
#!/bin/bash
# create pdf latex file
noweb.py -RProblem_Set_I_solve_wave_equation.tex Problem_Set_I_solve_wave_equation.md > Problem_Set_I_solve_wave_equation.tex && pdflatex -shell-escape Problem_Set_I_solve_wave_equation.tex > /dev/null
# compilation and execution of program
noweb.py -RProblem_Set_I_solve_wave_equation.cpp Problem_Set_I_solve_wave_equation.md > Problem_Set_I_solve_wave_equation.cpp && g++ -o Problem_Set_I_solve_wave_equation Problem_Set_I_solve_wave_equation.cpp

# live gnuplot plot
./Problem_Set_I_solve_wave_equation 0.01 | gnuplot -p -e "plot '-' using 2:3"

#./Problem_Set_I_solve_wave_equation 0.01 > 2023-11-16-data.dat
#gnuplot -p -e "plot '2023-11-16-data.dat' using 2:3"
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

int main(int argc, char** argv)
{
    const double CSpeed = 1;
    const double CMax = 1;
    const double dx = stod(argv[1]); //
    const double L = 1; // gridSpace
    const double timeLength = 1;
    const double dt = CMax*dx/CSpeed;
    const int nGhosts = 4;
    const int xSteps = int( L / dx );
    const int tSteps = int (timeLength / dt );

    double //
    x[xSteps],
    t[tSteps],
    phi[xSteps],
    eta[xSteps],
    chi[xSteps]
    ;
    init(t, x, phi, eta, chi, xSteps, dx, L);

    // cases for solver
    solvingWaveEquation(phi, eta, chi, t, dt, x, dx, CSpeed, xSteps);
    //{{solving wave equation}}
    //{{second order spatial derivative}}
    //{{forwad Euler method}}
    //{{forth order spatial derivative}}
    //{{Runge Kutter solver}}
	return 0;
};
@
```

```cpp
{{solving wave equation}}=
void solvingWaveEquation(double phi[], double eta[], double chi[], double t[], double dt, double x[], double dx, const double CSpeed, const int xSteps){
    //for (int j = 0; j < tSteps; j=j+1) {
    for (int j = 0; j < 10; j=j+1) {
        for (int i = 0; i < xSteps; i=i+1) {
            forwardEulerMethod(phi, eta, j, dx, i, dt, 1);
            forwardEulerMethod(eta, chi, j, dx, i, dt, pow(CSpeed, 2));
            forwardEulerMethod(chi, eta, j, dx, i, dt, 1);
            output(j, i, t, x, phi);
        };
        t[j]=j*dt;
        boundaryCondition(phi, eta, chi, xSteps);
        output(j, xSteps, t, x, phi);
    };
};
@
```

```cpp
{{forwad Euler method}}=
void forwardEulerMethod(double funct[], double funct2[], int ti, double dt, int xi, double dx, double factor){
    funct[ti+1]=funct[ti]+factor*dt*secondOrderSpatial(funct2, xi, dx);
};
@
```


```cpp
{{second order spatial derivative}}=
double secondOrderSpatial(double funct[], int xi, double dx){
    return (funct[xi+1]-funct[xi-1])/(2*dx);
};
@
```



```cpp
{{output}}=
void output(int ti, int xi, double t[], double x[], double phi[]){
    // t x phi
    cout << t[ti] << ' ' << x[xi] << ' ' <<  phi[xi] << endl;
};
@
```


```cpp
{{init}}=
void init(double t[], double x[], double phi[], double eta[], double chi[], int xSteps, double dx, double L){
    t[0]=0;
    //x[0]=0;
    for (int i = 0; i < xSteps; i=i+1) {
        phi[i] = exp(pow(sin(M_PI/L*(i*dx)),2))-1;
        eta[i] = phi[i];
        chi[i] = phi[i];
        x[i]=i*dx;
        output(0,i,t,x,phi);
	}
	x[xSteps]=xSteps*dx;
    boundaryCondition(phi, eta, chi, xSteps);
    output(0,xSteps,t,x,phi);
};
@
```

```cpp
{{boundaryCondition}}=
void boundaryCondition(double phi[], double eta[], double chi[], int xSteps){
    phi[xSteps] = phi[0];
    eta[xSteps] = eta[0];
    chi[xSteps] = chi[0];
};
@
```

```cpp
{{function declaration}}=
void output(int ti, int xi, double t[], double x[], double phi[]);
void init(double t[], double x[], double phi[], double eta[], double chi[], int xSteps,  int dx, double L);
void boundaryCondition(double phi[], double eta[], double chi[], int xSteps);
double secondOrderSpatial(double funct[], int xi, double dx);
void forwardEulerMethod(double funct[], double funct2[], int ti, double dt, int xi, double dx, double factor);
void solvingWaveEquation(double phi[], double eta[], double chi[], double t[], double dt, double x[], double dx, const double CSpeed, const int xSteps);
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

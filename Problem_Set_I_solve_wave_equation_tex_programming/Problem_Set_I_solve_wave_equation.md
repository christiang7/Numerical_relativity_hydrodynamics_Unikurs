# Problem Set I solve wave equation
Created [2023-11-04]()

- [X] **Problem Set I solve wave equation**
	- [X] Doing
        - [ ] A.2. Programming
            - [X] all fields have to get two dimensions not just one, because, the time step needs two points
            - [ ] implement the midpoints for x positions
            - [ ] Forward Euler method
            - [ ] boundaryCondition add ghost points
                - [ ] add more points to the arrays (left two and right two), but plotting only the real points
                - [ ] rewrite the for loops
                - [ ] implement the switching between these points
                - [ ] split the code for the points for not ghost points and the function for the ghost point calculation
            - [ ] Runge Kutter method
	- [X] Backlog
        - [ ] A.1.
            - [X] writing in first order equation the wave equation
            - [ ] calculation of eigenvectors and eigenvalues of matrix A

## Features
        - [X] calc initial condition
        - [X] gnuplot
        - [X] flexible for initial condition with start values
        - [X] writing script for compilation

## Informations

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


## Programming

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
#./Problem_Set_I_solve_wave_equation 0.01 | gnuplot -p -e "plot '-' using 2:3"

./Problem_Set_I_solve_wave_equation 0.01 > 2023-11-16-data.dat
gnuplot -p -e "plot '2023-11-16-data.dat' using 2:3"
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
    const int xSteps = int( L / dx ) + nGhosts;
    const int tSteps = int (timeLength / dt );

    double //
    x[xSteps],
    t[tSteps],
    phi[xSteps][2],
    chi[xSteps][2],
    eta[xSteps][2]
    ;

    cout << "# parameters " << dx << ' ' << dt << ' ' <<  xSteps << endl;

    init(t, x, phi, eta, chi, xSteps, dx, L);

    // cases for solver
    //solvingWaveEquation(phi, eta, chi, t, dt, x, dx, CSpeed, xSteps);

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
void solvingWaveEquation(double phi[][2], double eta[][2], double chi[][2], double t[], double dt, double x[], double dx, const double CSpeed, int xSteps){
    //for (int j = 0; j < tSteps; j=j+1) {
    for (int j = 0; j < 10; j=j+1) {
        t[j]=j*dt;
        for (int i = 0; i < xSteps; i=i+1) {
            forwardEulerMethod(phi, eta, j, dt, i, dx, 1);
            forwardEulerMethod(eta, chi, j, dt, i, dx, pow(CSpeed, 2));
            forwardEulerMethod(chi, eta, j, dt, i, dx, 1);
            output(j, i, t, x, phi);
        };
        boundaryCondition(xSteps, phi, eta, chi);
        output(j, xSteps, t, x, phi);
    };
};
@
```

```cpp
{{forwad Euler method}}=
void forwardEulerMethod(double funct[][2], double funct2[][2], int ti, double dt, int xi, double dx, double factor){
    //funct[xi][1]=funct[xi][0]+factor*dt*secondOrderSpatial(funct2, xi, dx);
    funct[xi][1]=funct[xi][0]+factor*dt*(funct2[xi+1][0]-funct2[xi-1][0])/(2*dx);
};
@
```


```cpp
{{second order spatial derivative}}=
double secondOrderSpatial(int xSteps, double funct2[][2], int xi, double dx){
    return (funct2[xi+1][0]-funct2[xi-1][0])/(2*dx);
};
@
```



```cpp
{{output}}=
void output(int ti, int xi, double t[], double x[], double phi[][2]){
    // t x phi
    cout << t[ti] << ' ' << x[xi] << ' ' <<  phi[xi][ti] << endl;
};
@
```


```cpp
{{init}}=
void init(double t[], double x[], double phi[][2], double eta[][2], double chi[][2], int xSteps, double dx, double L){
    t[0]=0;
    //x[0]=0;
    for (int i = 0; i < xSteps-4; i=i+1) {
        phi[i+2][0] = exp(pow(sin(M_PI/L*((i)*dx)),2))-1;
        chi[i+2][0] = exp(pow(sin(M_PI/L*(i*dx)),2))*2*sin(M_PI/L*(i*dx))cos(M_PI/L*(i*dx))*M_PI/L;
        eta[i+2][0] = chi[i+2][0];
        x[i]=i*dx;
        output(0, i, t, x, phi);
	}
	x[xSteps]=xSteps*dx;
    boundaryCondition(xSteps, phi, eta, chi);
    output( 0, xSteps-4, t, x, phi);
};
@
```

```cpp
{{boundaryCondition}}=
void boundaryCondition(int xSteps, double phi[][2], double eta[][2], double chi[][2]){
    phi[xSteps][0] = phi[0][0];
    eta[xSteps][0] = eta[0][0];
    chi[xSteps][0] = chi[0][0];
    phi[xSteps-1][0] = phi[1][0];
    eta[xSteps-1][0] = eta[1][0];
    chi[xSteps-1][0] = chi[1][0];
    phi[xSteps-2][0] = phi[2][0];
    eta[xSteps-2][0] = eta[2][0];
    chi[xSteps-2][0] = chi[2][0];
};
@
```

```cpp
{{function declaration}}=
void output(int ti, int xi, double t[], double x[], double phi[][2]);
void init(double t[], double x[], double phi[][2], double eta[][2], double chi[][2], int xSteps, double dx, double L);
void boundaryCondition(int xSteps, double phi[][2], double eta[][2], double chi[][2]);
double secondOrderSpatial(double funct2[][2], int xi, double dx);
void forwardEulerMethod(double funct[][2], double funct2[][2], int ti, double dt, int xi, double dx, double factor);
void solvingWaveEquation(int xSteps, double phi[][2], double eta[][2], double chi[][2], double t[], double dt, double x[], double dx, const double CSpeed);
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

# Problem Set I solve wave equation
Created [2023-11-04]()

- [X] **Problem Set I solve wave equation**
	- [X] Doing
	- [X] Backlog
	   - [ ] A.1.
		  - [ ] writing in first order equation the wave equation
		  - [ ] calculation of eigenvectors and eigenvalues of matrix A

## Features

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
```cpp
{{Problem_Set_I_solve_wave_equation.cpp}}=
// The C++ standard version:
#include <cstdio>
#include <cmath>
#include <fstream>
#include <iostream>
using namespace std ;

{{function declaration}}
{{output}}
{{init}}

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
@
```

```cpp
{{function declaration}}=
void output(int ti, int xi, double t[], double x[], double phi[]);
void init(double t[], double x[], double phi[], int xsteps, double L);
@
```


```cpp
{{output}}=
void output(int ti, int xi, double t[], double x[], double phi[]){
    // Declaring 2D array
    // t x phi
    cout << t[ti] << ' ' << x[xi] << ' ' <<  phi[xi] << endl;
}
@
```


```cpp
{{init}}=
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

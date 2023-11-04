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

## Programming

```bash
noweb.py -RProblem_Set_I_solve_wave_equation.cpp Problem_Set_I_solve_wave_equation.md > Problem_Set_I_solve_wave_equation.cpp && echo 'fertig' 
```


```cpp
{{Problem_Set_I_solve_wave_equation.cpp}}=
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

//example for function in cpp
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
@
```

## Latex File


```bash
noweb.py -RProblem_Set_I_solve_wave_equation.tex Problem_Set_I_solve_wave_equation.md > Problem_Set_I_solve_wave_equation.tex && pdflatex .tex && xdg-open Problem_Set_I_solve_wave_equation.pdf 2>/dev/null & 
```


```tex
{{Problem_Set_I_solve_wave_equation.tex}}=
\documentclass[10pt,fleqn,reqno,a4paper]{article}
\input{general-preamble.tex}
\input{color-symbols.tex}
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
\begin{minted}{cpp}
{{Problem_Set_I_solve_wave_equation.cpp}}
\end{minted}
\end{document}
@
```

# Problem Set II Relativistic Shock Tube
Created [2023-12-14]()

- [X] **Problem Set II Relativistic Shock Tube** 
    - [X] Doing
    - [X] Backlog
       - [ ] 

## Features

## Informations

## Programming

```bash
noweb.py -Rlaunch.sh Problem_Set_II_Relativistic_Shock_Tube.md > launch.sh && chmod +x launch.sh && ./launch.sh
```


```bash
{{launch.sh}}=
#!/bin/bash
# compilation of program
noweb.py -RProblem_Set_II_Relativistic_Shock_Tube.cpp Problem_Set_II_Relativistic_Shock_Tube.md > Problem_Set_II_Relativistic_Shock_Tube.cpp && g++ -o Problem_Set_II_Relativistic_Shock_Tube Problem_Set_II_Relativistic_Shock_Tube.cpp

# execution of program
#  state vector (1,0,0)
#./Problem_Set_II_Relativistic_Shock_Tube 1. 0. 0.

#  state vector (1,40/3,0)
./Problem_Set_II_Relativistic_Shock_Tube 10. 13.3333 0.

#  state vector (0.1,1.,0.99)
#./Problem_Set_II_Relativistic_Shock_Tube 0.1 1. 0.99

#./Problem_Set_II_Relativistic_Shock_Tube 0.5 1.2 1.1


# live gnuplot plot
#./Problem_Set_II_Relativistic_Shock_Tube 1 0 0 | gnuplot -p -e "plot '-' using 2:3"
#./Problem_Set_II_Relativistic_Shock_Tube 1 0 0 | gnuplot -p


#data output and plot
#./Problem_Set_II_Relativistic_Shock_Tube 1 0 0 > 2023-11-26-data.dat
#cat 2023-11-26-data.dat | gnuplot -p


# create pdf latex file
noweb.py -RProblem_Set_II_Relativistic_Shock_Tube.tex Problem_Set_II_Relativistic_Shock_Tube.md > Problem_Set_II_Relativistic_Shock_Tube.tex && pdflatex -shell-escape Problem_Set_II_Relativistic_Shock_Tube.tex > /dev/null
@
```
```cpp
{{Problem_Set_II_Relativistic_Shock_Tube.cpp}}=
#include <cstdio>
#include <cmath>
#include <fstream>
#include <iostream>
using namespace std ;

double
D,
Sx,
tau,
h
;

{{function declaration}}

{{calc init}}

{{root solver}}

int main(int argc, char** argv)
{

    double //
    rho = stod(argv[1]),
    p = stod(argv[2]),
    vx = stod(argv[3]),
    W = 1./sqrt(1.-vx*vx)
    ;

    cout << "# parameters rho=" << rho << " p=" << p << " vx=" <<  vx << " W=" <<  W << endl;

    calc_init(rho, p, vx, W);

    root_solver(rho, p, vx, W);
	return 0;
};
@
```

```cpp
{{calc init}}=
void calc_init(double rho, double p, double vx, double W){
    h = 1.+(5./2.)*(p/rho);
    D = rho*W;
    Sx = rho*h*W*W*vx;
    tau = rho*h*W*W-p-D;
    cout << "# parameters D=" << D << " Sx=" << Sx << " tau=" <<  tau << " h=" <<  h << endl;
}
;
@
```

```cpp
{{root solver}}=
void root_solver(double rho, double p, double vx, double W){
    double func, f_p, p_delta, p_old, p_new;
    p_delta = 0.1;
    //cout << "# parameters D=" << D << " Sx=" << Sx << " tau=" <<  tau << " h=" <<  h << endl;
    while (abs(p_delta) > 0.000001)
    {
        p_old=p;
        vx = Sx / (tau + D + p);
        W = 1./sqrt(1. - vx*vx);
        cout << "# parameters rho=" << rho << " p=" << p << " vx=" <<  vx << " W=" <<  W << endl;
        func = p - 2./3./(W*W)*(tau + D + p - D*W - p*W*W);
        f_p = 1.- 2./3.*Sx*Sx/(pow(tau + D + p,3.))*(tau + D + p - D*W);
        p_new = p - func/f_p;
        p_delta=p_new - p_old;
        cout << "# p_delta=" << p_delta << " func=" << func << " f_p=" << f_p << " p=" << p_new << endl;
        p = p_new;
    }
    cout << "# new pressure p=" << p << endl;
};
@
```


```cpp
{{function declaration}}=
void calc_init(double rho, double p, double vx, double W);
void root_solver(double rho, double p, double vx, double W);
@
```



## Latex File


```bash
noweb.py -RProblem_Set_II_Relativistic_Shock_Tube.tex Problem_Set_II_Relativistic_Shock_Tube.md > Problem_Set_II_Relativistic_Shock_Tube.tex && pdflatex -shell-escape Problem_Set_II_Relativistic_Shock_Tube.tex && xdg-open Problem_Set_II_Relativistic_Shock_Tube.pdf 2>/dev/null & 
```


```tex
{{Problem_Set_II_Relativistic_Shock_Tube.tex}}=
\documentclass[10pt,fleqn,reqno,a4paper]{article}
\input{general-preamble.tex}
\input{color-symbols.tex}
\begin{document}%\selectlanguage{english}



\begin{minted}[linenos=true,bgcolor=lightgraycolor,numberblanklines=true,showspaces=false,breaklines=true]{cpp}
{{Problem_Set_II_Relativistic_Shock_Tube.cpp}}
\end{minted}
\end{document}
@
```

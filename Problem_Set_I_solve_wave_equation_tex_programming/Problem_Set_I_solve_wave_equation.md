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


```bash
chmod u+x Problem_Set_I_solve_wave_equation.cpp && ln -sf /home/christian/Gedankenspeicher/Gedankenspeicherwiki/Physik/Numerical_relativity_hydrodynamics_Unikurs/Problem_Set_I_solve_wave_equation.cpp ~/.local/bin/Problem_Set_I_solve_wave_equation.cpp && echo 'fertig'
 ```

```cpp
{{Problem_Set_I_solve_wave_equation.cpp}}=


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

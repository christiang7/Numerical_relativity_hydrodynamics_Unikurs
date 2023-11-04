# Problem_Set_I_solve_wave_equation.tex
Created [2023-11-04]()

- [X] **Problem_Set_I_solve_wave_equation.tex** 
    - [X] Doing
    - [X] Backlog
       - [ ] 

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



\begin{minted}{cpp}
{{Problem_Set_I_solve_wave_equation.cpp}}
\end{minted}{cpp}
\end{document}
@
```

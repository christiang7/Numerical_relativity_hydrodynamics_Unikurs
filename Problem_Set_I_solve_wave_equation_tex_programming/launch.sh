#!/bin/bash
# create pdf latex file
noweb.py -RProblem_Set_I_solve_wave_equation.tex Problem_Set_I_solve_wave_equation.md > Problem_Set_I_solve_wave_equation.tex && pdflatex -shell-escape Problem_Set_I_solve_wave_equation.tex > /dev/null
# compilation and execution of program
noweb.py -RProblem_Set_I_solve_wave_equation.cpp Problem_Set_I_solve_wave_equation.md > Problem_Set_I_solve_wave_equation.cpp && g++ -o Problem_Set_I_solve_wave_equation Problem_Set_I_solve_wave_equation.cpp

# live gnuplot plot
#./Problem_Set_I_solve_wave_equation 0.01 | gnuplot -p -e "plot '-' using 2:3"

./Problem_Set_I_solve_wave_equation 0.01 > 2023-11-16-data.dat
gnuplot -p -e "plot '2023-11-16-data.dat' using 2:3"

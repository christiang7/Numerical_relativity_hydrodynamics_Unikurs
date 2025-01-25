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

noweb.py -RProblem_Set_II_Relativistic_Shock_Tube.tex Problem_Set_II_Relativistic_Shock_Tube.md > Problem_Set_II_Relativistic_Shock_Tube.tex && pdflatex -shell-escape Problem_Set_II_Relativistic_Shock_Tube.tex 2> /dev/null
#noweb.py -RProblem_Set_II_Relativistic_Shock_Tube.tex Problem_Set_II_Relativistic_Shock_Tube.md > Problem_Set_II_Relativistic_Shock_Tube.tex && pdflatex -shell-escape Problem_Set_II_Relativistic_Shock_Tube.tex && xdg-open Problem_Set_II_Relativistic_Shock_Tube.pdf 2>/dev/null &


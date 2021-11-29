set term epscairo size 4.5, 3.62 color dashed font "Times,10" 
set output 'example1_rk4_gnu.pdf'

set title "Numerical solution of the Van der Pol oscillator equation with Runge-Kutta 4"

set xlabel "t (time)"
set ylabel "u(t)"

set key right top sample 1.5 spacing 1.0 width 1.5 height 1 box

#set label 1 at 10, 1.1
#set label 1 "Initial Position = 0 m"

#set label 2 at 10, 0.9
#set label 2 "Initial Velocity = 1 m/s"

#set label 3 at 1, 1.3
#set label 3 "{/Symbol w}_{0}^{2} = 1"

#set yrange[-2:2]

#plot 'ho_rk4_out_teste.txt' u 2:3 w points pt 7 lc 7 lw 1 t"RK-4"

#plot 'example2_rk4_out.txt' u 2:3 w points t"RK-4"

plot '../GNU_SL/example1_oscillator_out.txt' u 1:2 w lines lc 7 t"RK-4"

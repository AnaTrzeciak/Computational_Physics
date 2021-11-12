set term epscairo size 4.5, 3.62 color dashed font "Times,10" 
set output 'out_harmonic_oscillator-2.pdf'

set title "Harmonic Oscillator - Numerical Solution with Runge-Kutta 4"

set xlabel "t (time)"
set ylabel "v (velocity)"

set label 1 at 10, 1.1
set label 1 "Initial Position = 0 m"

set label 2 at 10, 0.9
set label 2 "Initial Velocity = 1 m/s"

set label 3 at 1, 1.3
set label 3 "{/Symbol w}_{0}^{2} = 1"


plot 'out_harmonic_oscillator-rk4.txt' u 3:2 with lines lc 8 t"RK-4"

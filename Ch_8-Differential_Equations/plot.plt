set term epscairo size 4.5, 3.62 color dashed font "Times,10" 
set output 'harmonic_osc.pdf"

#set yrange[*:*]

plot 'out_programm_1.txt' u 1  w lines lw 2 lc rgb "#FF0000" t"cos(t)",

#Read NeutrinoOscillation-OutFile.txt

set term pdfcairo size 4.5, 3.62 color dashed font "Times-New-Roman,12" 
set output 'example.pdf'

set key Left reverse left bottom sample 2.0 spacing 1.5 width 4 height 4

set termoption enhanced
set xlabel "x"
set ylabel "f(x)"


#set ytics 0.1
#set yrange[0:1.1]
#set format x "%2.0t{/Symbol \264}10^{%L}"
#set logscale x 10
#set xrange [0.1:300]


plot 'example4-simpsons_rule.txt' u 1:2 w points pt 7 lc rgb "#00FF00" t"example"
      
    




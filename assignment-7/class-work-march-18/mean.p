set terminal png
set output "mean.png"
set grid
set time
set xrange [0:510]
set xlabel "No of performed expt (M)" font ",14"
set title "Mean value of Pi with std deviation" font ",14"
plot "PI.txt" u 1:2:3 w yerrorbars lc 7 t "", pi t "line of π"
set terminal png size 1200,600
set output "5b1.png"
set key font ",14"
set multiplot layout 1,2 title "2-D Random walk (part b:dx dy vs N)"
set grid

set title "dx vs steps"
set xlabel "N"
set ylabel "dx"
plot "5ch1.txt" u 1:2 w l lc 7 t ""

set title "dy vs steps"
set xlabel "N"
set ylabel "dy"
plot "5ch1.txt" u 1:3 w l lc 7 t ""
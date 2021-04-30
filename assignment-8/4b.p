#make the necessary changes
set terminal png size 1200,600
set output "4ch50.png"
set key font ",14"
set multiplot layout 1,2 title "1-D Random walk (part c for h=50.0)"
set grid

set title "distance vs steps"
set xlabel "N"
set ylabel "d(N)"
plot "4ch50.txt" u 1:2 w l lc 7 t ""

set title "distance squared vs steps"
set xlabel "N"
set ylabel "d^2(N)"
plot "4ch50.txt" u 1:3 w l lc 7 t ""
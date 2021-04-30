set terminal png size 1500,1800
set output "5d1.png"
set multiplot layout 3,1
set grid

set title "<dx> vs steps" font ",18"
set xlabel "N" font ",18"
set ylabel "<dx>" font ",18"
plot "5d1.txt" u 1:2 w l lc 7 t ""

set title "<dx> vs steps" font ",18"
set xlabel "N" font ",18"
set ylabel "<dx>" font ",18"
plot "5d1.txt" u 1:3 w l lc 7 t ""

set title "<dx+dy> vs steps" font ",18"
set xlabel "N" font ",18"
set ylabel "<total>=<dx+dy>" font ",18"
plot "5d1.txt" u 1:4 w l lc 7 t ""
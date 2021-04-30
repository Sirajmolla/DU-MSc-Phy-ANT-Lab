set terminal png
set output "3a.png"
set grid
set xlabel "X_i" font ",14"
set ylabel "Y_i" font ",14"
set title "Random numbers using distribution" font ",14"
plot "3a.txt" u 1:2 w dots  lc 7 t ""

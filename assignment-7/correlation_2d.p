set terminal png
set output "filename.png"
set key off
set grid
set time
set xlabel "r_{i}" font ",14"
set ylabel "r_{i+1}" font ",14"
set title "correlation check in 2D space (RN:10000)" font ",14"
plot "data.txt" u 1:2 w dots
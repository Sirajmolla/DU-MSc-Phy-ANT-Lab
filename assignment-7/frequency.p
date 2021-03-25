set terminal png
set output "filename.png"
set key off
set grid
set time
set xlabel "random numbers (bin-width:0.1)" font ",14"
set ylabel "frequency of occurrence" font ",14"
set title "frequency distribution of random numbers" font ",14"
plot "filename.txt" u 1:2 w impulse
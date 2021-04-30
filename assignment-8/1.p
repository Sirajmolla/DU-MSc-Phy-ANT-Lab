set terminal png
set output "1b.png"
set grid
set time
set xlabel "random numbers (bin-width:0.1)" font ",14"
set ylabel "frequency of occurrence" font ",14"
set title "frequency distribution of random numbers" font ",14"
#plot "1a.txt" u 1:2 w impulse t "using default RN"
plot "1b.txt" u 1:2 w impulse t "using distribution"
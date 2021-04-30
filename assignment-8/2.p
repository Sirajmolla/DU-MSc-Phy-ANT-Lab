set terminal png
set output "2b.png"
set grid
set xlabel "random numbers (bin-width:0.01)" font ",14"
set ylabel "frequency of occurrence" font ",14"
set title "frequency distribution of random numbers" font ",14"
#plot "2a.txt" u 1:2 w impulse t "using default RN"
plot "2b.txt" u 1:2 w impulse t "using distribution"
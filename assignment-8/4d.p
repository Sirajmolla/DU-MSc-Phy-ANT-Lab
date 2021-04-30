set terminal png size 1000,600
set output "4d1.png"
#set multiplot layout 1,2 title "1-D Random walk (part b for h=1.0)"
set grid
#set yrange [-.5:12]
set title "1-D Random walk Simulation (part d) with N=1000 n=1000" font ",16"
set xlabel "N" font ",16"
set ylabel "<d(N)>" font ",16"
#set ylabel "<d(N)^2> and <d(N)>^2" font ",14"
plot "4d1.txt" u 1:2:3 w yerrorbars lc 7 t "sigma",'' u 1:2 w l lc 8 t "<d(N)>"
#plot "4d2.txt" u 1:2 w l lc 7 t "<d(N)^2>", '' u 1:3 w l lc 8 t "<d(N)>^2"

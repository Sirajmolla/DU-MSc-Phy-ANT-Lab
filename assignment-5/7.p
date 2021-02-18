# keep '7.txt' in same directory.
set grid
set time
#set yrange [-2:6]
set xlabel "value of x" font ",14"
set ylabel "interpolating functions" font ",14"

#set title "cubic spline with given data points" font ",14"
#set title "lagrange polynomial with given data points" font ",14"
set title "cubic spline and lagrange polynomial with data points" font ",14"

#plot "7.txt" u 1:2 w l t "cubic spline", "data2.txt" w points pt 4 lc rgb 0 t 'data points'
#plot "7.txt" u 1:3 w l t "lagrange", "data2.txt" w points pt 4 lc rgb 0 t 'data points'
plot "7.txt" u 1:2 w l t "cubic spline", '' u 1:3 w l t "lagrange", "data2.txt" w points pt 4 lc rgb 0 t 'data points'

pause -1 "Hit Enter key to continue"
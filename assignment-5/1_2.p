# keep 'csp.txt' in same directory.
set grid
set time
set xlabel "value of x" font ",14"
set ylabel "interpolating functions" font ",14"
set title "lagrange, cubic spline and exact functions" font ",14"
plot "csp.txt" u 1:2 w l t "lagrange",'' u 1:3 w l t "cubic spline", '' u 1:4 w l t "exact", "data1.txt" w points pt 4 lc rgb 0 t ''
pause -1 "Hit Enter key to continue"
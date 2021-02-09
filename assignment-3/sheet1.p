# keep 'sheet1.txt' in same directory.
set grid
set time
set title "Plot of lagrange interpolated function" font ",14"
plot "sheet1.txt" u 1:2 w l lw 1.5 t "P2(x)",'' u 1:3 w l lw 1.5 t "P6(x)","1a.txt" u 1:2 t "data I","1b.txt" u 1:2 t "data II","sheet1.txt" u 1:4 w l lc rgb "red" t "1/x"

pause -1 "Hit Enter key to continue"
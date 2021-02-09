# keep 'sheet3.txt' in same directory.
set grid
set time
#set title "Plot of lagrange interpolated function" font ",14"
set title "Plot of neville interpolated function" font ",14"
plot "sheet3nev.txt" u 1:2 w l lw 1.5 t "P1(x)",'' u 1:3 w l lw 1.5 t "P2(x)",'' u 1:4 w l lw 1.5 t "P3(x)",'' u 1:5 w l t "1/x"

pause -1 "Hit Enter key to continue"
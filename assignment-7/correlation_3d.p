set terminal png
set output "filename.png"
set key off
set grid
set time
set xlabel "r_{i}"
set ylabel "r_{i+1}"
set zlabel "r_{i+2}"
set title "correlation check in 3D space (RN:10000)" font ",14"
splot "data.txt" u 1:2:3 w dots
lab01.exe < 03-scaling.input.txt > 03-scaling.actual.txt 2>NUL
fc /N 03-scaling.actual.txt 03-scaling.expected.txt
pause
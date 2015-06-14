makemain: main.c 
	gcc -o main.exe main.c -ldl
	gcc -shared add.c -o add.so
	gcc -shared subtract.c -o subtract.so
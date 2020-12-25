default:
	echo "Shell"

Compile all:
	gcc ls.c -o ls
	gcc date.c -o date
	gcc mkdir.c -o mkdir
	gcc rm.c -o rm
	gcc cat.c -o cat

Execute shell:
	gcc A2main.c -o run
	./run

all:
	gcc proj2.c list.c -o proj2 
test: Identify
Identify:
	./proj2 sample.c output.txt

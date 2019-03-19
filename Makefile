SelfOrganizingList: list.c prj2.c
	clang list.c prj2.c -o Project2

# Tests 
test: test1

test1:
	./Project2 sample.c > listTest.txt


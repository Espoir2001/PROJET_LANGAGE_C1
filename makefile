treetest: treetest.o mylib/libmylib.a
	cc -o $@ treetest.o -Lmylib -lmylib
	
treetest.o: treetest.c mylib/libmylib.a
	cc -c -Wall treetest.c		
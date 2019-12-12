Park:CarStack.o main.o TmpStack.o CarQueue.o 
	cc -o Park CarStack.o main.o TmpStack.o CarQueue.o
CarStack.o:CarStack.c CarStack.h
	cc -c CarStack.c
TmpStack.o:TmpStack.c TmpStack.h
	cc -c TmpStack.c
CarQueue.o:CarQueue.c CarQueue.h
	cc -c CarQueue.c
main.o:main.c main.h CarStack.h CarQueue.h TmpStack.h
	cc -c main.c
clean:
	-rm -rf *.o

Sort_a: D_inSort.o Random_Numble.o testSort.o
	cc -o Sort_a D_inSort.o Random_Numble.o testSort.o
D_inSort.o: D_inSort.c Sort.h
	cc -c D_inSort.c
Random_Numble.o: Random_Numble.c Sort.h
	cc -c Random_Numble.c
testSort.o:testSort.c Sort.h
	cc -c testSort.c
clean:
	-rm -rf *.o

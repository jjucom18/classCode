D_inSort: D_inSort.o Random_Numble.o
	cc -o D_inSort D_inSort.o Random_Numble.o
D_inSort.o: D_inSort.c Sort.h
	cc -c D_inSort.c
Random_Numble.o: Random_Numble.c Sort.h
	cc -c Random_Numble.c
clean:
	-rm -rf *.o

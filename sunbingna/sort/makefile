Sort_a: D_inSort.o Random_Numble.o testSort.o Bubble_Sort.o ShellSort.o Select_Sort.o
	cc -o Sort_a D_inSort.o Random_Numble.o testSort.o Bubble_Sort.o ShellSort.o Select_Sort.o
D_inSort.o: D_inSort.c Sort.h
	cc -c D_inSort.c
Random_Numble.o: Random_Numble.c Sort.h
	cc -c Random_Numble.c
testSort.o:testSort.c Sort.h
	cc -c testSort.c
Bubble_Sort.o:Bubble_Sort.c Sort.h
	cc -c Bubble_Sort.c
ShellSort.o:ShellSort.c Sort.h
	cc -c ShellSort.c
Select_Sort.0:Select_Sort.c Sort.h
	cc -c Select_Sort.c
clean:
	-rm -rf *.o

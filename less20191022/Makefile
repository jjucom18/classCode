#testc:testc.c bubbleSort.c
	#gcc -g testc.c bubbleSort.c -o testc
testc:testc.c bubbleSort.c outArr.c binarySearch.c
	gcc -g testc.c bubbleSort.c binarySearch.c  outArr.c -o testc

clean:
	rm testc

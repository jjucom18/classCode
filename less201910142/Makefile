testc:testc.c linkg.c
	gcc -g testc.c linkg.c -o testc
	gcc -S testc.c -o testc.s
	tcc -S linkg.c -o linkg.s

clean:
	rm testc

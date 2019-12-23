objects = student.o display.o queue.o stack.o 
orange: $(objects)
	gcc -o orange $(objects)
%.o:%c
	gcc -c $<
clean:
	rm -r *.o;

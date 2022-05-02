CC = gcc

manager.o: drink.c drink.h
	$(CC) -c drink.c -o drink.o
vm_exe: main.c drink.o
	$(CC) -o $@ $^
clean:
	rm *.o vm_exe

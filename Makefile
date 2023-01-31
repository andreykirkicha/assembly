TARGET = assembly
CC = gcc

$(TARGET) : main.o asm.o errors.o
	$(CC) main.o asm.o errors.o -o $(TARGET)

main.o : main.cpp
	$(CC) -c main.cpp -o main.o

asm.o : asm.cpp
	$(CC) -c asm.cpp -o asm.o

errors.o : errors.cpp
	$(CC) -c errors.cpp -o errors.o

clean:
	rm *.o
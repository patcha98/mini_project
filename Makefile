CC = gcc
CFLAGS = -W -Wall
TARGET = product
OBJECTS = main.c manager.o
$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@



clean:
	rm *.o

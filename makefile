CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = studentApp

OBJS = main.o \
       grade.o \
       fileio.o \
       validation.o \
       stats.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

main.o: main.c studentstructure.h grade.h fileio.h validation.h stats.h
	$(CC) $(CFLAGS) -c main.c

grade.o: grade.c grade.h
	$(CC) $(CFLAGS) -c grade.c

fileio.o: fileio.c fileio.h studentstructure.h
	$(CC) $(CFLAGS) -c fileio.c

validation.o: validation.c validation.h studentstructure.h
	$(CC) $(CFLAGS) -c validation.c

stats.o: stats.c stats.h studentstructure.h
	$(CC) $(CFLAGS) -c stats.c

clean:
	rm -f $(OBJS) $(TARGET)

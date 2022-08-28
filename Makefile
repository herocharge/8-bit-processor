CC = g++
CFLAGS = -g -Wall


all:  memory.o opcode_handler.o procedures.o program_counter.o stack.o cpu.o main.o 
	$(CC) $(CFLAGS) -o a.out memory.o opcode_handler.o procedures.o program_counter.o stack.o cpu.o main.o
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp
cpu.o:  cpu.cpp
	$(CC) $(CFLAGS) -c cpu.cpp
memory.o:  memory.cpp
	$(CC) $(CFLAGS) -c memory.cpp
opcode_handler.o: opcode_handler.cpp
	$(CC) $(CFLAGS) -c opcode_handler.cpp
procedures.o: procedures.cpp
	$(CC) $(CFLAGS) -c procedures.cpp
program_counter.o: program_counter.cpp
	$(CC) $(CFLAGS) -c program_counter.cpp
stack.o: stack.cpp
	$(CC) $(CFLAGS) -c stack.cpp

# all:
# 	$(CC) $(CFLAGS) -o a.out  memory.cpp opcode_handler.cpp procedures.cpp program_counter.cpp stack.cpp main.cpp cpu.cpp

clean:
	rm *.o
	rm *.out

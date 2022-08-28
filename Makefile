CC = g++
CFLAGS = -g -Wall


all:  memory.o opcode_handler.o procedures.o program_counter.o stack.o cpu.o main.o 
	$(CC) $(CFLAGS) -o a.out memory.o opcode_handler.o procedures.o program_counter.o stack.o cpu.o main.o
main.o:
	$(CC) $(CFLAGS) -c main.cpp
cpu.o:
	$(CC) $(CFLAGS) -c cpu.cpp
memory.o:
	$(CC) $(CFLAGS) -c memory.cpp
opcode_handler.o:
	$(CC) $(CFLAGS) -c opcode_handler.cpp
procedures.o:
	$(CC) $(CFLAGS) -c procedures.cpp
program_counter.o:
	$(CC) $(CFLAGS) -c program_counter.cpp
stack.o:
	$(CC) $(CFLAGS) -c stack.cpp

# all:
# 	$(CC) $(CFLAGS) -o a.out  memory.cpp opcode_handler.cpp procedures.cpp program_counter.cpp stack.cpp main.cpp cpu.cpp

clean:
	rm *.o
	rm *.out

CFLAGS = -g -Wall

all:
	g++ main.cpp genProblem.cpp hardware.cpp $(CFLAGS) -o main

clean:
	$(RM) main
	$(RM) genProblem
	$(RM) hardware
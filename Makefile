CFLAGS = -g -Wall
TARGET = main.cpp genProblem.cpp hardware.cpp

all:
	g++ $(TARGET) $(CFLAGS) -o main

clean:
	$(RM) main
	$(RM) genProblem
	$(RM) hardware
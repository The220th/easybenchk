CC=g++
FLAGS=-Wall -fopenmp
I=-I./include/
SOURCES=main.cpp ./func/cpu.cpp ./func/calcPI.cpp ./func/calcE.cpp ./func/calcI.cpp ./func/calcSeries.cpp ./func/mem.cpp
EXECUTABLE=easybenchk

all:
	$(CC) $(I) $(FLAGS) $(SOURCES) -o $(EXECUTABLE)
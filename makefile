# Compiler
CC = g++


CLIBS = -lsfml-graphics -lsfml-window -lsfml-system


all : main.cpp
	$(CC) $(CLIBS) main.cpp

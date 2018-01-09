PROG = test
CC = g++
CPPFLAGS = -std=c++11 -I include
LDFLAGS = -L lib -lsfml-system-d-2 -lsfml-window-d-2 -lsfml-graphics-d-2
OBJS = main.o game.o utils.o

$(PROG): $(OBJS)
	$(CC) $(LDFLAGS) -o $(PROG) $(OBJS)

main.o: main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

game.o: game.cpp game.h
	$(CC) $(CPPFLAGS) -c game.cpp

utils.o: utils.cpp utils.h
	$(CC) $(CPPFLAGS) -c utils.cpp
all: main.cpp
	g++ main.cpp -std=c++11 -L ./lib -lsfml-window-d-2 -lsfml-system-d-2 -lsfml-graphics-d-2 -I include
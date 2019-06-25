main: Matriz.o main.o
	g++ main.cpp Matriz.cpp -o run

main.o: main.cpp	
	g++ -c main.cpp

Matriz.o: Matriz.cpp
	g++ -c Matriz.cpp
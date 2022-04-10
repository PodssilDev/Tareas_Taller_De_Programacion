all: test_Container_1 test_Node_1 test_Heap_1 test_Maze_1 main

main: main.cpp Maze.o Heap.o Container.o Node.o
	g++ Maze.o Node.o Heap.o Container.o main.cpp -o main

test_Maze_1: test_Maze_1.cpp Maze.o Node.o Heap.o Container.o 
	g++ Maze.o Node.o Heap.o Container.o test_Maze_1.cpp -o test_Maze_1

test_Heap_1: test_Heap_1.cpp Node.o Heap.o
	g++ Node.o Heap.o test_Heap_1.cpp -o test_Heap_1

test_Node_1: test_Node_1.cpp Node.o
	g++ Node.o test_Node_1.cpp -o test_Node_1

test_Container_1: test_Container_1.cpp 	Container.o
	g++ Container.o test_Container_1.cpp -o test_Container_1

Container.o: Container.cpp Container.h
	g++ -c Container.cpp

Maze.o: Maze.cpp Maze.h
	g++ -c Maze.cpp

Heap.o: Heap.cpp Heap.h
	g++ -c Heap.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

Main.o: Main.cpp
	g++ -c Main.cpp
FLAGS = -O2

all: test_Container test_Node test_Heap test_Maze main

run: main
	./main

runMaze: test_Maze
	./test_Maze
	
runContainer: test_Container
	./test_Container

runHeap: test_Heap
	./test_Heap

runNode: test_Node
	./test_Node

main: Main.cpp Maze.o Heap.o Container.o Node.o
	g++ $(FLAGS) Maze.o Node.o Heap.o Container.o Main.cpp -o main

test_Maze: test_Maze.cpp Maze.o Node.o Heap.o Container.o 
	g++ $(FLAGS) Maze.o Node.o Heap.o Container.o test_Maze.cpp -o test_Maze

test_Heap: test_Heap.cpp Node.o Heap.o
	g++ $(FLAGS) Node.o Heap.o test_Heap.cpp -o test_Heap

test_Node: test_Node.cpp Node.o
	g++ $(FLAGS) Node.o test_Node.cpp -o test_Node

test_Container: test_Container.cpp 	Container.o
	g++ $(FLAGS) Container.o test_Container.cpp -o test_Container

Container.o: Container.cpp Container.h
	g++ $(FLAGS) -c Container.cpp

Maze.o: Maze.cpp Maze.h
	g++ $(FLAGS) -c Maze.cpp

Heap.o: Heap.cpp Heap.h
	g++ $(FLAGS) -c Heap.cpp

Node.o: Node.cpp Node.h
	g++ $(FLAGS) -c Node.cpp

Main.o: Main.cpp
	g++ $(FLAGS) -c Main.cpp

clean:
	rm -f *.o test_Node test_Container test_Heap test_Maze main 
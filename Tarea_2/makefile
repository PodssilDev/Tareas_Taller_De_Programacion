FLAGS = -O2

all: test_Container test_Node test_Heap test_Cost test_Assignment main

run: main
	./main

runAssignment: test_Assignment
	./test_Assignment

runMaze: test_Cost
	./test_Cost
	
runContainer: test_Container
	./test_Container

runHeap: test_Heap
	./test_Heap

runNode: test_Node
	./test_Node

main: Main.cpp Cost.o Node.o Heap.o Container.o Assignment.o
	g++ $(FLAGS) Cost.o Node.o Heap.o Container.o Assignment.o Main.cpp -o main

test_Assignment: test_Assignment.cpp Assignment.o Cost.o Node.o Heap.o Container.o 
	g++ $(FLAGS) Cost.o Node.o Heap.o Container.o Assignment.o test_Assignment.cpp -o test_Assignment

test_Cost: test_Cost.cpp Cost.o
	g++ $(FLAGS) Cost.o test_Cost.cpp -o test_Cost

test_Heap: test_Heap.cpp Node.o Heap.o
	g++ $(FLAGS) Node.o Heap.o test_Heap.cpp -o test_Heap

test_Node: test_Node.cpp Node.o
	g++ $(FLAGS) Node.o test_Node.cpp -o test_Node

test_Container: test_Container.cpp 	Container.o
	g++ $(FLAGS) Container.o test_Container.cpp -o test_Container

Container.o: Container.cpp Container.h
	g++ $(FLAGS) -c Container.cpp

Assignment.o: Assignment.cpp Assignment.h
	g++ $(FLAGS) -c Assignment.cpp

Cost.o: Cost.cpp Cost.h
	g++ $(FLAGS) -c Cost.cpp

Heap.o: Heap.cpp Heap.h
	g++ $(FLAGS) -c Heap.cpp

Node.o: Node.cpp Node.h
	g++ $(FLAGS) -c Node.cpp

Main.o: Main.cpp
	g++ $(FLAGS) -c Main.cpp

clean:
	rm -f *.o test_Node test_Container test_Heap test_Cost test_Assignment main
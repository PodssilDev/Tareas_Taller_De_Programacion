FLAGS = -O2

all: test_Container_1 test_Node_1 test_Heap_1 test_Cost_1 test_Assignment_1 main

run: main
	./main
	./test_Assignment_1
	./test_Container_1
	./test_Cost_1
	./test_Heap_1
	./test_Node_1

main: Main.cpp Cost.o Node.o Heap.o Container.o Assignment.o
	g++ $(FLAGS) Cost.o Node.o Heap.o Container.o Assignment.o Main.cpp -o main

test_Assignment_1: test_Assignment_1.cpp Assignment.o Cost.o Node.o Heap.o Container.o 
	g++ $(FLAGS) Cost.o Node.o Heap.o Container.o Assignment.o test_Assignment_1.cpp -o test_Assignment_1

test_Cost_1: test_Cost_1.cpp Cost.o
	g++ $(FLAGS) Cost.o test_Cost_1.cpp -o test_Cost_1

test_Heap_1: test_Heap_1.cpp Node.o Heap.o
	g++ $(FLAGS) Node.o Heap.o test_Heap_1.cpp -o test_Heap_1

test_Node_1: test_Node_1.cpp Node.o
	g++ $(FLAGS) Node.o test_Node_1.cpp -o test_Node_1

test_Container_1: test_Container_1.cpp 	Container.o
	g++ $(FLAGS) Container.o test_Container_1.cpp -o test_Container_1

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
	rm -f *.o
FLAGS = -O2

all: test_Node test_Heap test_Hamiltonian test_Eficiencia main 

run: main
	./main

runEficiencia: test_Eficiencia
	./test_Eficiencia
	
runHamiltonian: test_Hamiltonian
	./test_Hamiltonian

runHeap: test_Heap
	./test_Heap

runNode: test_Node
	./test_Node

main: Main.cpp Hamiltonian.o Node.o Heap.o
	g++ $(FLAGS)  Hamiltonian.o Node.o Heap.o Main.cpp -o main

test_Eficiencia: test_Eficiencia.cpp Node.o Heap.o Hamiltonian.o 
	g++ $(FLAGS)  test_Eficiencia.cpp Node.o Heap.o Hamiltonian.o -o test_Eficiencia

test_Hamiltonian: test_Hamiltonian.cpp Node.o Heap.o Hamiltonian.o
	g++ $(FLAGS)  test_Hamiltonian.cpp Node.o Heap.o Hamiltonian.o -o test_Hamiltonian

test_Heap: test_Heap.cpp Node.o Heap.o
	g++ $(FLAGS) test_Heap.cpp Node.o Heap.o -o test_Heap

test_Node: test_Node.cpp Node.o
	g++ $(FLAGS) test_Node.cpp Node.o -o test_Node

Hamiltonian.o: Hamiltonian.cpp Hamiltonian.h
	g++ $(FLAGS) -c Hamiltonian.cpp

Node.o: Node.cpp Node.h
	g++ $(FLAGS) -c Node.cpp

Heap.o: Heap.cpp Heap.h
	g++ $(FLAGS) -c Heap.cpp

Main.o: Main.cpp
	g++ $(FLAGS) -c Main.cpp

clean:
	rm -f *.o test_Node test_Heap test_Hamiltonian test_Eficiencia main
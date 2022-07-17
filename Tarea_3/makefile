FLAGS = -O2

all: main test_corrupt test_Optimizer test_Image Objective.o Optimizer.o Image.o ImageProcessor.o

run: crearTxt.py test_corrupt main cargaTxt.py
	python3 crearTxt.py
	./test_corrupt
	./main
	python3 cargaTxt.py

runOptimizer: test_Optimizer
	./test_Optimizer

runImage: test_Image
	./test_Image

main: Objective.o Optimizer.o Image.o ImageProcessor.o Main.cpp
	g++ $(FLAGS) -o main Main.cpp Objective.o Optimizer.o Image.o ImageProcessor.o

test_Optimizer: Objective.o Optimizer.o test_Optimizer.cpp Image.o ImageProcessor.o
	g++ $(FLAGS) -o test_Optimizer test_Optimizer.cpp Objective.o Optimizer.o Image.o ImageProcessor.o

test_corrupt: test_corrupt.cpp Image.o ImageProcessor.o 
	g++ $(FLAGS) -o test_corrupt test_corrupt.cpp Image.o ImageProcessor.o

test_Image: test_Image.cpp Image.o
	g++ $(FLAGS) -o test_Image test_Image.cpp Image.o

Objective.o: Objective.cpp Objective.h
	g++ $(FLAGS) -c Objective.cpp

Optimizer.o: Optimizer.cpp Optimizer.h
	g++ $(FLAGS) -c Optimizer.cpp

Image.o: Image.cpp Image.h 
	g++ $(FLAGS) -c Image.cpp 

ImageProcessor.o: ImageProcessor.cpp ImageProcessor.h
	g++ $(FLAGS) -c ImageProcessor.cpp 

clean:
	rm -f *.o test_corrupt test_Optimizer test_Image main *.txt

run_generate_image:
	ipython crearTxt.py

run_load_image:
	./test_corrupt
	ipython cargaTxt.py	
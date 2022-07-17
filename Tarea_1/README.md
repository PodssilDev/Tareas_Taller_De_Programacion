# Tarea 1: Algoritmo A* (A Star Algorithm)
## Descripción
Esta tarea trata sobre el Algoritmo A* (Algoritmo A estrella) el cual realiza una busqueda en un laberinto generado aleatoriamente.
El algoritmo esta creado en C++ a traves de la programación orientada a objetos. Ya que se utiliza Makefile para facilitar
la compilación, además de algunas bibliotecas exclusivas de Linux, es necesario que todo se pruebe en un Sistema Operativo Linux.<br/>

Se tienen las siguientes clases:

* [Clase Node](https://github.com/PodssilDev/Tareas_Taller_De_Programacion/blob/main/Tarea_1/Node.cpp): La clase "Node" representa a un estado del laberinto, en otras palabras, un nodo es una posicion del laberinto que tiene unas coordenadas i,j, 
un valor y una referencia al padre de donde se pudo acceder a esa posicion.
* [Clase Heap](https://github.com/PodssilDev/Tareas_Taller_De_Programacion/blob/main/Tarea_1/Heap.cpp): La clase "Heap" corresponde a la clase de la Cola de prioridad, la cual se utiliza como "Open list" para 
asi poder saber que nodos son por visitar. Heap recibe un  tamaño para poder funcionar.
* [Clase Container](https://github.com/PodssilDev/Tareas_Taller_De_Programacion/blob/main/Tarea_1/Container.cpp): La clase "Container" representa a la clase correspondiente a la "CloseList", donde se coloca
una identificacion para los ya visitados. Por terminos de eficiencia, se utiliza una matriz de la misma dimension del laberinto.
* [Clase Maze](https://github.com/PodssilDev/Tareas_Taller_De_Programacion/blob/main/Tarea_1/Maze.cpp): La clase "Maze" consiste en la clase del laberinto. Aqui es donde se genera y se tiene el  algoritmo A* para 
encontrar el camino mas eficiente desde la entrada hacia la salida.

## Como ejecutar
Se tienen 5 ejecutables:
* [test_Node](https://github.com/PodssilDev/Tareas_Taller_De_Programacion/blob/main/Tarea_1/test_Node.cpp): Test para la clase Node
* [test_Heap](https://github.com/PodssilDev/Tareas_Taller_De_Programacion/blob/main/Tarea_1/test_Heap.cpp): Test para la clase Heap
* [test_Container](https://github.com/PodssilDev/Tareas_Taller_De_Programacion/blob/main/Tarea_1/test_Container.cpp): Test para la clase Container
* [test_Maze](https://github.com/PodssilDev/Tareas_Taller_De_Programacion/blob/main/Tarea_1/test_Maze.cpp): Test para la clase Maze
* [main](https://github.com/PodssilDev/Tareas_Taller_De_Programacion/blob/main/Tarea_1/Main.cpp): Main del programa, donde se pueden probar 100 iteraciones de laberintos de dimension 1000 <br/>

Para hacer el proceso de prueba mas rapido, se dispone de:
* make runNode: Ejecuta ./test_Node
* make runHeap: Ejecuta ./test_Heap
* make runContainer: Ejecuta ./test_Container
* make runMaze: Ejecuta ./test_Maze
* make run: Ejecuta ./main

## Mas información
Para mas información sobre el desarrollo del programa, o los resultados obtenidos, revisar el [informe](https://github.com/PodssilDev/Tareas_Taller_De_Programacion/blob/main/Tarea_1/SerranoJohn.pdf) disponible en el repositorio.
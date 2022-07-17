# Tarea 4: Ciclos Hamiltonianos
## Descripción
El problema consiste en realizar un algoritmo en C++ utilizando la Programación Orientada a Objetos, para encontrar un 
Ciclo Hamiltoniano en un grafo génerado aleatoriamente con una cantidad de nodos especifica. Ya que se utiliza Makefile para facilitar
la compilación, además de algunas bibliotecas exclusivas de Linux, es necesario que todo se pruebe en un Sistema Operativo Linux.<br/>

Se tienen las siguientes clases:
* [Clase Node](https://github.com/PodssilDev/Tareas_Taller_De_Programacion/blob/main/Tarea_4/Node.cpp): La clase “Node” representa a un nodo del grafo. Cada nodo tiene un numero asignado y un “valor” que corresponde
a la cantidad de conexiones que tiene.
* [Clase Heap](https://github.com/PodssilDev/Tareas_Taller_De_Programacion/blob/main/Tarea_4/Heap.cpp): La clase “Heap” corresponde a la clase de la Cola de prioridad, la cual se utiliza como “Open list” para 
así guardar los nodos del grafo. Heap recibe un tamaño para poder funcionar.
* [Clase Hamiltonian](https://github.com/PodssilDev/Tareas_Taller_De_Programacion/blob/main/Tarea_4/Hamiltonian.cpp): “Hamiltonian” es la clase mas importante en esta tarea. En ella se crea el grafo a buscar y se tienen
los métodos de solve para así buscar si el grafo generado tiene o no un Ciclo Hamiltoniano.

## Como ejecutar
Se tienen 5 ejecutables:
* [test_Node](https://github.com/PodssilDev/Tareas_Taller_De_Programacion/blob/main/Tarea_4/test_Node.cpp): Test para la clase Node.
* [test_Heap](https://github.com/PodssilDev/Tareas_Taller_De_Programacion/blob/main/Tarea_4/test_Heap.cpp): Test para la clase Heap.
* [test_Hamiltonian](https://github.com/PodssilDev/Tareas_Taller_De_Programacion/blob/main/Tarea_4/test_Hamiltonian.cpp): Test para la clase Hamiltonian (1 iteracion de un grafo de 15 nodos)
* [test_Eficiencia](https://github.com/PodssilDev/Tareas_Taller_De_Programacion/blob/main/Tarea_4/test_Eficiencia.cpp): Test para probar la eficiencia (50 iteraciones de varios grafos de 300 nodos).
* [main](https://github.com/PodssilDev/Tareas_Taller_De_Programacion/blob/main/Tarea_4/Main.cpp): Programa principal, donde se puede probar con distintas cantidad de nodos e iteraciones.

Para hacer el proceso de prueba rapido, se dispone de:
* make runNode: Ejecuta ./test_Node
* make runHeap: Ejecuta ./test_Heap
* make runHamiltonian: Ejecuta ./test_Hamiltonian
* make runEficiencia: Ejecuta ./test_Eficiencia
* make run: Ejecuta ./main

## Mas información
Para mas información sobre el desarrollo del programa, o los resultados obtenidos, revisar el [informe](https://github.com/PodssilDev/Tareas_Taller_De_Programacion/blob/main/Tarea_4/SerranoJohn.pdf) disponible en el repositorio.

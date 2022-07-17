# Tarea 2: Branch and Bound y Jobs Assignment
## Descripción
Esta tarea esta basada en el algoritmo Branch and Bound y resuelve el problema de Jobs Assignment (Asignación de trabajos). 
El programa esta realizado en C++ utilizando la programación orientada a objetos. Ya que se utiliza Makefile para facilitar
la compilación, además de algunas bibliotecas exclusivas de Linux, es necesario que todo se pruebe en un Sistema Operativo Linux.<br/>

Se tienen las siguientes clases:

* [Clase Node](https://github.com/PodssilDev/Tareas_Taller_De_Programacion/blob/main/Tarea_2/Node.cpp): La clase "Node" representa a un estado de la matriz, en otras palabras, un nodo es una posicion de la matriz que tiene unas coordenadas i,j, un valor, un valor total,
un arreglo de booleanos y una referencia al padre de donde se pudo acceder a esa posicion.
* [Clase Heap](https://github.com/PodssilDev/Tareas_Taller_De_Programacion/blob/main/Tarea_2/Heap.cpp): La clase "Heap" corresponde a la clase de la Cola de prioridad, la cual se utiliza para obtener el nodo de menor costo y asi saber cual es la asignacion optima. Heap recibe un tamaño para poder funcionar.
* [Clase Container](https://github.com/PodssilDev/Tareas_Taller_De_Programacion/blob/main/Tarea_2/Container.cpp): La clase "Container" representa a la clase correspondiente a la Matriz Binaria, donde se coloca una identificacion para las asignaciones definidas. Por terminos de eficiencia, se utiliza
una matriz de la misma dimension del laberinto. Un 1 representa una asignacion y un 0 significa no asignado.
* [Clase Cost](https://github.com/PodssilDev/Tareas_Taller_De_Programacion/blob/main/Tarea_2/Cost.cpp): La clase "Cost" representa a la matriz de Costo, donde cada posicion tiene un numero aleatorio representando el 
costo de la asignacion de esa columna y procesador en  especifico. La matriz tiene un tamano determinado por el parametro N.
* [Clase Assignment](https://github.com/PodssilDev/Tareas_Taller_De_Programacion/blob/main/Tarea_2/Assignment.cpp): La clase Assignment representa a un objeto el cual contiene la matriz de costo y el tamano N, 
el cual corresponde al tamano de la matriz de costo. En esta clase se encuentra el metodo para encontrar el menor costo asociado a la asignacion de CPUs y procesos.

## Como ejecutar
Se tienen 6 ejecutables:
* [test_Node](https://github.com/PodssilDev/Tareas_Taller_De_Programacion/blob/main/Tarea_2/test_Node.cpp): Test para la clase Node
* [test_Heap](https://github.com/PodssilDev/Tareas_Taller_De_Programacion/blob/main/Tarea_2/test_Heap.cpp): Test para la clase Heap
* [test_Container](https://github.com/PodssilDev/Tareas_Taller_De_Programacion/blob/main/Tarea_2/test_Container.cpp): Test para la clase Container
* [test_Cost](https://github.com/PodssilDev/Tareas_Taller_De_Programacion/blob/main/Tarea_2/test_Cost.cpp): Test para la clase Cost
* [test_Assignment](https://github.com/PodssilDev/Tareas_Taller_De_Programacion/blob/main/Tarea_2/test_Assignment.cpp): Test para la clase test_Assignment
* [main](https://github.com/PodssilDev/Tareas_Taller_De_Programacion/blob/main/Tarea_2/Main.cpp): Main del programa, donde se pueden probar las 25 iteraciones de una matriz de 500 x 500<br/>

Para hacer el proceso de prueba mas rapido, se dispone de:
* make runNode: Ejecuta ./test_Node
* make runHeap: Ejecuta ./test_Heap
* make runContainer: Ejecuta ./test_Container
* make runCost: Ejecuta ./test_Cost
* make runAssignment: Ejecuta ./test_Assignment
* make run: Ejecuta ./main

## Mas información
Para mas información sobre el desarrollo del programa, o los resultados obtenidos, revisar el [informe](https://github.com/PodssilDev/Tareas_Taller_De_Programacion/blob/main/Tarea_2/SerranoJohn.pdf) disponible en el repositorio.
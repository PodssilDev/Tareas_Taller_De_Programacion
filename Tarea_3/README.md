# Tarea 3: Restauración de Imágenes (Image Restoration)
## Descripción
El objetivo es crear un algoritmo el cual corrompa una imagen y luego se realice el proceso de restauración. Esta tarea utiliza Python 3 y C++ junto con la Programación Orientada a Objetos. Ya que se utiliza Makefile para facilitar
la compilación, además de algunas bibliotecas exclusivas de Linux, es necesario que todo se pruebe en un Sistema Operativo Linux.<br/>

Se tienen los archivos de Python: 
* [crearTxt.py](https://github.com/PodssilDev/Tareas_Taller_De_Programacion/blob/main/Tarea_3/crearTxt.py): El archivo "crearTxt.py" permite crear el archivo .txt necesario para iniciar el proceso de corrupcion de la imagen.
* [cargaTxt.py](https://github.com/PodssilDev/Tareas_Taller_De_Programacion/blob/main/Tarea_3/cargaTxt.py): El archivo "cargaTxt.py" permite cargar el archivo .txt creado a traves de la  restauracion para asi mostrar la imagen restaurada. Ademas, se muestra la imagen original para su comparacion.<br/>

Se tienen las siguientes clases:
* [Clase Image](https://github.com/PodssilDev/Tareas_Taller_De_Programacion/blob/main/Tarea_3/Image.cpp): La clase "Image" representa a la clase de la Imagen, donde esta Imagen se puede  transformar a un archivo de texto .txt para asi poder realizar el proceso de corrucion.
* [Clase ImageProcessor](https://github.com/PodssilDev/Tareas_Taller_De_Programacion/blob/main/Tarea_3/ImageProcessor.cpp): La clase "ImageProcessor" representa a la clase que realiza el procesamiento de la imagen y las distintas operaciones con estas, como lo es agregar ruido o corromper la imagen.
* [Clase Optimizer](https://github.com/PodssilDev/Tareas_Taller_De_Programacion/blob/main/Tarea_3/Optimizer.cpp): La clase "Optimizer" representa un optimizador de funciones, la cual resulta util para hacer el proceso de la corrupcion algo rapido y eficiente. Requiere un  Objective, unos parametros iniciales y una tolerancia.
* [Clase Objective](https://github.com/PodssilDev/Tareas_Taller_De_Programacion/blob/main/Tarea_3/Objective.cpp): La clase "Objective" representa la clase que contiene la funcion objetivo. Es una clase que es utilzada por Optimizer.

## Como ejecutar
Se tienen 4 ejecutables:
* [test_Image](https://github.com/PodssilDev/Tareas_Taller_De_Programacion/blob/main/Tarea_3/test_Image.cpp): Test para la clase Image.
* [test_Optimizer](https://github.com/PodssilDev/Tareas_Taller_De_Programacion/blob/main/Tarea_3/test_Optimizer.cpp): Test para la clase Optimizer y la clase Objective.
* [test_corrupt](https://github.com/PodssilDev/Tareas_Taller_De_Programacion/blob/main/Tarea_3/test_corrupt.cpp): Test para la clase ImageProcessor. Necesita de crearTxt.py para que funcione correctamente.
* [main](https://github.com/PodssilDev/Tareas_Taller_De_Programacion/blob/main/Tarea_3/Main.cpp): Archivo principal del programa, el cual realiza el proceso de restauración. Necesita de crearTxt.py y test_corrupt para que funcione correctamente. <br/>

Para hacer el proceso de prueba mas rapido, se dispone de:
* make runImage: Ejecuta ./test_Image
* make runOptimizer: Ejecuta ./test_Image
* make run: Se recomienda fuertemente utilizar make run, ya que ejecutara todo en orden incluyendo los archivos .py. El orden de ejecución es el siguiente:
1. python3 crearTxt.py
2. ./test_corrupt
3. ./main
4. python3 cargaTxt.py<br/>
Si se hizo todo correctamente, se deberia mostrar la imagen restaurada. Notar que la imagen nunca podra
ser restaurada al 100%.
## Mas información
Para mas información sobre el desarrollo del programa, o los resultados obtenidos, revisar el [informe](https://github.com/PodssilDev/Tareas_Taller_De_Programacion/blob/main/Tarea_3/SerranoJohn.pdf) disponible en el repositorio.
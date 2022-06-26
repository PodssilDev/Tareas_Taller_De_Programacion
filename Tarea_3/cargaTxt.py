# DESCRIPCION: Este archivo permite cargar el archivo .txt creado a traves de la 
# restauracion para asi mostrar la imagen restaurada. Ademas, se muestra la imagen
# original para su comparacion

# BLOQUE DE DEFINICIONES
# IMPORTACION DE FUNCIONES
import numpy as np # Se importa Numpy
from matplotlib import pyplot as plt # Se importa Matplotlib

# BLOQUE PRINCIPAL
y = np.loadtxt("image_corrupted.txt",dtype=np.float64) # Se carga el .txt de la imagen restaurada
y=y.reshape((256,256)) # Pasa de ser 1d a 2d
x = np.loadtxt("restored.txt", dtype = np.float64) # Se carga el .txt de la imagen original
x = x.reshape((256,256)) # Pasa de ser 1d a 2d
f = plt.figure() # Se crean figuras para poder mostrar ambas imagenes lado a lado
f.add_subplot(1,2,1) # Se crea un subplot 
plt.imshow(x) # Se muestra la imagen original
plt.axis("off") # Se quitan los ejes
plt.gray() # Para que se vea en escala de grises
plt.title("Imagen Restaurada") # Se agrega un titulo a la imagen
f.add_subplot(1,2,2) # Se crea otro subplot
plt.imshow(y) # Se muestra la imagen restaurada
plt.axis("off") # Se eliminan los ejes
plt.gray() # Para que se vea en escala de grises
plt.title("Imagen Corrompida") # Se agrega un titulo a la imagen
plt.show() # Se muestra la ventana con ambas imagenes

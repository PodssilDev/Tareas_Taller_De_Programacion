# DESCRIPCION: Este archivo permite crear el archivo .txt necesario para iniciar el 
# proceso de corrupcion de la imagen.

# BLOQUE DE DEFINICIONES
# MPORTACION DE FUNCIONES
import scipy # Se importa Scipy
import numpy as np # Se importa Numpy
from matplotlib import pyplot as plt # Se importa Matplotlib
from skimage.transform import resize # Se implota resize de skimage.transform
from PIL import Image # Se importa Image de Pillow

# BLOQUE PRINCIPAL
x = Image.open("Sonic1.png") # Se abre la imagen a utilizar
x=np.array(x,dtype=np.float64) # Asegurandose que son float para trabajar correctamente
x=x[:,:,0] # La tercera dimension da cuenta de los tres colores rgb, dejamos solo el rojo 
x=x/np.max(x) # Para que los numero queden entre 0 y 1 el algoritmo funciona mejor asi
x=x[:,:256] # Recortando
y=x # Copiamos lo anterior en la variable y
np.savetxt("image.txt", x, fmt="%1.12lf") # Generamos un archivo con los valores de la imagen 
plt.title("Imagen Original") # Agregamos titulo al plot
plt.gray() # Se muestra la imagen en escala de grises
plt.imshow(y) # Se muestra la imagen
plt.axis("off") # Se eliminan los ejes de la imagen
plt.show() # Se muestra correctamente la ventana de la imagen

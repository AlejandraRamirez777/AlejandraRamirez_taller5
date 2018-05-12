import numpy as np
import matplotlib.pyplot as plt
from matplotlib import animation

#Importar datos
x = np.genfromtxt("datos_cuerda.txt", usecols = 0)
y = np.genfromtxt("datos_cuerda.txt", usecols = 1)

#Set up figure, axis and plot element to animate
fig, ax = plt.subplots()

#Info en grafica
ax.set_xlim(( 0, 100))
ax.set_ylim((-1, 1))
plt.title("Progreso de la cuerda en el tiempo")
plt.xlabel("Posicion")
plt.ylabel("Funcion de onda")

#Line graficadora
line, = ax.plot([], [], lw=2)

# Se grafica el background para cada frame
def init():
    line.set_data([], [])
    return (line,)

# Funcion de animacion. Se llama secuencialmente
def animate(i):

    #Largo de la linea
    n = 101

    #Se divide linea por tiempos (200)
    co = i*n
    cof = (i+1)*n

    xx = x[co:cof]
    yy = y[co:cof]

    line.set_data(xx, yy)

    return (line,)

#Numero de frames del gif
n = 101
T = 20201
ff = int(T/n)

# LLamada al animador
anim = animation.FuncAnimation(fig, animate, init_func=init, frames=ff, interval=20, blit=False)

#Save animation
anim.save('cuerda.gif', writer='imagemagick', fps=40)

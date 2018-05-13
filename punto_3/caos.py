import numpy as np
import matplotlib.pyplot as plt


x = np.genfromtxt("datos_caos.txt", usecols = 1)
y = np.genfromtxt("datos_caos.txt", usecols = 0)


xx = np.linspace(-3000,0,6000)
#plt.plot(xx,y)

plt.title("q2 vs. p2")
plt.ylabel("q2")
plt.xlabel("p2")

plt.plot(x,y)

#Cambiar a PDF!!
plt.savefig("caos.png")

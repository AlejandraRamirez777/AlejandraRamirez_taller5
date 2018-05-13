import numpy as np
import matplotlib.pyplot as plt


x = np.genfromtxt("datos_caos.txt", usecols = 1)
y = np.genfromtxt("datos_caos.txt", usecols = 0)

plt.title("q2 vs. p2")
plt.ylabel("q2")
plt.xlabel("p2")

plt.plot(x,y)

#Cambiar a PDF!!
plt.savefig("caos.png")

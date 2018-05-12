import numpy as np
import matplotlib.pyplot as plt

x = np.genfromtxt("datos_cuerda.txt", usecols = 0)
y = np.genfromtxt("datos_cuerda.txt", usecols = 1)

n = 102
T = 20201
c = 0

while(c < T):

    xx = x[c:n]
    yy = y[c:n]

    plt.plot(xx,yy)

    c = c + n
    n = n + n


plt.savefig("s_graph.png")

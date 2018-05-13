import numpy as np
import matplotlib.pyplot as plt
import matplotlib.gridspec as gridspec

#Get data
data = np.genfromtxt("datos_placas.txt")

#Corte de datos
w =  np.shape(data)[0]/512

#Reajust para graficar
go = data.reshape((w,w,3))

#Potencial
plt.imshow(go[:,:,2],cmap = "bwr")
plt.colorbar()

#Create Mesh
Y, X = np.mgrid[:w:512j, :w:512j]

#Vectores de campo electrico
plt.streamplot(X,Y,go[:,:,0],go[:,:,1], color = "k")


plt.title("Potencial y Campo Electrico")

#CAMBIAR A PDF ! ! !

plt.savefig("Placas.png")

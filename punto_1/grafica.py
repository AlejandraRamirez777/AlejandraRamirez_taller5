import numpy as np
import matplotlib.pyplot as plt
import matplotlib.gridspec as gridspec

data = np.genfromtxt("datos_placas.txt")

print np.shape(data)

#Potencial
plt.imshow(data,cmap = "bwr")
plt.colorbar()

plt.title("Potencial y Campo Electrico")

print np.shape(data)

'''
#Create Mesh
w = 512
Y, X = np.mgrid[:w:512j, :w:512j]
#Magnitude
U = 2*X
#Direction
V = Y*Y

print np.shape(V)

fig = plt.figure(figsize=(7, 9))
gs = gridspec.GridSpec(nrows=2, ncols=1, height_ratios=[1, 1])

# Varying color along a streamline
ax1 = fig.add_subplot(gs[0, 0])
strm = ax1.streamplot(X, Y, U, V, color=U, linewidth=2, cmap='cool')
fig.colorbar(strm.lines)
ax1.set_title('Potencial Electrico')

# Varying color along a streamline
ax2 = fig.add_subplot(gs[1, 0])
strm = ax2.streamplot(X, Y, U, V, color=U, linewidth=2, cmap='summer')
fig.colorbar(strm.lines)
ax2.set_title('Campo Electrico')

#plt.tight_layout()

#CAMBIAR A PDF ! ! !
'''
plt.savefig("Placas.png")

import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("erreur.txt")

plt.figure(figsize=[12,9])
plt.loglog(data[:,0], data[:,1], label="Erreur rec_gauche")
plt.loglog(data[:,0], data[:,2], label="Erreur rec_droite")
plt.loglog(data[:,0], data[:,3], label="Erreur rec_milieu")
plt.loglog(data[:,0], data[:,4], label="Erreur trapeze")
plt.loglog(data[:,0], data[:,5], label="Erreur Simpson")
plt.title("Erreur")
plt.xlabel("x")
plt.ylabel("y")
plt.grid(True)
plt.legend()
plt.show()

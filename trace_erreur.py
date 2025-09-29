import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("erreur.txt")

simp_x = data[:,0]
simp_y = data[:,5]

mask = np.isfinite(simp_y)
liste_x = simp_x[mask]
liste_y = simp_y[mask]

plt.figure(figsize=[12,9])
plt.loglog(data[:,0], data[:,1], label="Erreur rec_gauche")
plt.loglog(data[:,0], data[:,2], label="Erreur rec_droite")
plt.loglog(data[:,0], data[:,3], label="Erreur rec_milieu")
plt.loglog(data[:,0], data[:,4], label="Erreur trapeze")
plt.loglog(liste_x, liste_y, label="Erreur Simpson")
plt.title("Erreur")
plt.xlabel("x")
plt.ylabel("y")
plt.grid(True)
plt.legend()
plt.show()


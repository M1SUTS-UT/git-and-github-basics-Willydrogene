import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("Mira.txt")

plt.figure(figsize=[12,12])
plt.plot(data[:,0], data[:,1], "*")
plt.title("Fractales de Mira")
plt.xlabel("x")
plt.ylabel("y")
plt.grid(True)
plt.show()

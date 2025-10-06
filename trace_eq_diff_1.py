import matplotlib.pyplot as plt
import numpy as np


data = np.loadtxt("eq_diff_1.txt", skiprows=1)

plt.figure(figsize=[10,10])
plt.plot(data[1:,0], data[1:,1], label="Euler")
plt.plot(data[1:,0], data[1:,2], label="Heun")
plt.title("Equation diff ordre 1, Euleur/Heun")
plt.xlabel("x")
plt.ylabel("y")
plt.grid(True)
plt.legend()
plt.show()

import matplotlib.pyplot as plt
import numpy as np


data = np.loadtxt("oscillateur.txt", skiprows=1)

plt.figure(figsize=[10,10])
plt.subplot(2, 2, 1)
plt.plot(data[1:,0], data[1:,1], label="y")
plt.title("Oscillateur RK4")
plt.xlabel("t")
plt.ylabel("y")
plt.grid(True)
plt.legend()

plt.subplot(2, 2, 2)
plt.plot(data[1:,0], data[1:,2], label="y_point")
plt.title("Vitesse")
plt.xlabel("t")
plt.ylabel("y_point")
plt.grid(True)
plt.legend()

plt.subplot(2, 2, 3)
plt.plot(data[1:,1], data[1:,2], label="portrait de phase")
plt.title("Portrait de phase")
plt.xlabel("y")
plt.ylabel("y_point")
plt.grid(True)
plt.legend()

plt.show()

import matplotlib.pyplot as plt
import numpy as np


data = np.loadtxt("eq_diff_1.txt", skiprows=1)
data_err = np.loadtxt("eq_diff_1_erreur.txt", skiprows=1)

plt.figure(figsize=[10,10])
plt.subplot(2, 1, 1)
plt.plot(data[1:,0], data[1:,1], label="Euler")
plt.plot(data[1:,0], data[1:,2], label="Heun")
plt.plot(data[1:,0], data[1:,3], label="RK4")
plt.title("Equation diff ordre 1, Euleur/Heun/RK4")
plt.xlabel("x")
plt.ylabel("y")
plt.grid(True)
plt.legend()

plt.subplot(2, 1, 2)
plt.loglog(data_err[1:,0], data_err[1:,1], label="Err_Euler")
plt.loglog(data_err[1:,0], data_err[1:,2], label="Err_Heun")
plt.loglog(data_err[1:,0], data_err[1:,3], label="Err_RK4")
plt.title("Erreur Euleur/Heun/RK4")
plt.xlabel("x")
plt.ylabel("y")
plt.grid(True)
plt.legend()

plt.show()

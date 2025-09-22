#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Sep 22 15:25:35 2025

@author: grw4219a
"""

import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("/home/grw4219a/Bureau/C_ASEP/fonction.txt")

plt.figure(figsize=[14,9])
plt.plot(data[:,0], data[:,1])
plt.plot(data[:,0], data[:,2])
plt.title("fonction sin(x)")
plt.xlabel("x")
plt.ylabel("sin(x)")
plt.grid(True)
plt.show()
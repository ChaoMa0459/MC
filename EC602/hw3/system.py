# Copyright 2017 Chao Ma mc163@bu.edu

import numpy as np
# import sys

# get input to list
h = input().split()
x = input().split()
# change into float
for i in range(len(h)):
	h[i]=float(h[i])
for j in range(len(x)):
	x[j]=float(x[j])
# convolve
result = np.convolve(h, x)
# change into string and join " "
print(" ".join(map(str, result)))

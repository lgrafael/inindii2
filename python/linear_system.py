import numpy as np
from numpy.linalg import solve as ls

#declarar as matrizes
a = np.array([[1,1],[-3,1]])
b = np.array([[6],[2]])

x = ls(a,b)
print(x)


V2 = 2.763
I2 = 0.02237
T2 = 60.6
V1 = 3.117
I1 = 0.01883
T1 = 171.47


R1 = V1/I1
R2 = V2/I2


alpha1 = (R1-100)/(100*T1)
alpha2 = (R2-100)/(100*T2)

print("Valor de alpha 1\n", alpha1)
print("Valor de alpha 2\n", alpha2)


"""


Equação 1:
𝑅1 = 100 + 100*alpha*T 

Equação 2:
𝑅 = 100 + 100*alpha*T 

alpha = (R-100)/(T*100)
"""
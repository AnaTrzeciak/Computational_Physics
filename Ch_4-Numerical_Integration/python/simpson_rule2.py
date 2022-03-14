import numpy as np
import math
import matplotlib.pyplot as plt
import scipy.integrate as spi

def f(x):
  return np.exp(0.904 - 0.184*x -0.0878*x**2)*np.sqrt((x - 1.3)**2 - (0.511)**2)*(x - 1.3)*x**(-0.07056 + 0.02018*np.log(x) - 0.001953*np.log(x)**3)


N = 100; a = 1.9; b = 10.0;
x = np.linspace(a,b,N + 1)   #Return evenly spaced numbers over a specified interval.
y = f(x)

approximation = spi.simps(y,x)
print(x)
print(y)
print(approximation)

plt.plot(x, y)
plt.show()

import numpy as np
import math
import matplotlib.pyplot as plt
import scipy.integrate as spi

s2_13 = 0.02219         #sin^2(theta_13)
s2_23 = 0.573           #sin^2(theta_23)
s2_12 = 0.304           #sin^2(theta_12)
mass_21 = 7.42e-5       #mass_21 eV^2
mass_31 = 2.517e-3      #mass_31 eV^2
mass_32 = mass_31 
c_12 = np.sqrt(1 - s2_12)  #cos(\theta12)
c_13 = np.sqrt(1 - s2_13)  #cos(\theta13)
c_23 = np.sqrt(1 - s2_23)  #cos(\theta23)
L = 52500.0 		 #distance in m

A = ((2*c_12*np.sqrt(s2_12))**2)*(c_13)**4
B = ((2*c_13*np.sqrt(s2_13))**2)*s2_12
C = ((2*c_13*np.sqrt(s2_13))**2)*(c_12)**2

def f(x):
  flux = np.exp(0.904 - 0.184*x -0.0878*x**2)*np.sqrt((x - 1.3)**2 - (0.511)**2)
  cross_section = (x - 1.3)*x**(-0.07056 + 0.02018*np.log(x) - 0.001953*np.log(x)**3)
  prob = (1 - A*(np.sin(1.27*mass_21*L/x))**2 - B*(np.sin(1.27*mass_32*L/x))**2 - C*(np.sin(1.27*mass_31*L/x)**2))

  return flux*cross_section*prob


N = 200; a = 1.9; b = 10.0;
x = np.linspace(a,b,N + 1)   #Return evenly spaced numbers over a specified interval.
y = f(x)

approximation = spi.simps(y,x)
#print(x)
#print(y)
print(approximation)
print(approximation/6.439649026563678)

#plt.plot(x, y)
#plt.show()



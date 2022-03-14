import numpy as np

def simps(f, a, b, n = 50):
 if n%2 == 1:
  raise ValueError("n must be even interger")
 dx = (b - a)/n
 x = np.linspace(a, b, n + 1)
 y = f(x)
 S = dx/3*np.sum(y[0:-1:2] + 4*y[1::2] + y[2::2])
 return S

#appro = simps(lambda x: 3*x**2,0,1,10)
appro = simps(np.sin, 0, np.pi/2, 100)

print(appro)


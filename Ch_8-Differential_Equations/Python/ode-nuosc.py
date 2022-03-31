'''
Code to solve a ordinary differential equation of Neutrino Oscillation using scipy (matter/vacuum)

 idy/dx = Hy  (complex equations)

4 real equations

 y'1(x) = h11 y2 + h12 y4;
 y'2(x) = -h11 y1 - h12 y3;
 y'3(x) = h21 y2 + h22 y4;
 y'4(x) = -h21 y1 - h22 y3;

  h11 = -0.006086
  h12 = 0.014456
  h21 = 0.014456
  h22 = 0.006086
 
initial condition:
  y1(0) = 1, y2(0) = 0, y3(0) = 0, y4(0) = 0

     * y[0] = Re(psi_ee)
     * y[1] = Im(psi_ee)
     * y[2] = Re(psi_emu)
     * y[3] = Im(psi_emu)

'''

from scipy.integrate import solve_ivp
import numpy as np
import math
import matplotlib.pyplot as plt

#outfile = open("ode.txt", "w")

mass_21 = 7.42e-5;               
s2_12 = 0.304;                  
c_12 = np.sqrt(1 - s2_12);         
c_2_12 = 1 - 2*s2_12;           
s_2_12 = 2*c_12*np.sqrt(s2_12);    
neutrino_energy = 0.021;         

fermi = 1.16637e-5;   
electron_density = (0.896e24)*((197.3e-13)**3); 
A_cc = 2*np.sqrt(2)*fermi*electron_density*neutrino_energy;

h11 = -1.27*(mass_21*c_2_12)/(neutrino_energy) + A_cc/4*neutrino_energy;
h12 = 1.27*(mass_21*s_2_12)/(neutrino_energy);  
h21 = h12;
h22 = -h11;

y0 = [1.0, 0.0, 0.0, 0.0]
def func(t, y):
 return[ h11*y[1] + h12*y[3], -h11*y[0] - h12*y[2], h21*y[1] + h22*y[3], -h21*y[0] - h22*y[2]]
  
t_span = [0.0, 1300.0]

rtol, atol = (1e-8, 1e-8)

sol1 = solve_ivp(func, t_span, y0, rtol = rtol, atol = atol)

#print("sol1.t: {}".format(sol1.t))
#print("sol1.y: {}".format(sol1.y))
plt.plot(sol1.t, (sol1.y[0])**2 + (sol1.y[1])**2)
plt.plot(sol1.t, (sol1.y[2])**2 + (sol1.y[3])**2)
plt.show()

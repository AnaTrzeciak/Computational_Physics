from scipy.interpolate import interp1d
from scipy.interpolate import CubicSpline
from numpy import *
from numpy.linalg import *

import pandas as pd
import numpy as np
import math
import matplotlib.pyplot as plt

df = pd.read_csv("data1.txt", sep = ' ', header=None);

xaxis = df[df.columns[0]].to_numpy()
yaxis = df[df.columns[1]].to_numpy()

f = interp1d(xaxis, yaxis, kind='cubic')
#spl = CubicSpline(xaxis, yaxis)

xnew = np.linspace(xaxis[0], xaxis[11], num = 130, endpoint=True);
ynew = f(xnew);

outfile = open("data2-interpol-py.txt", "w");
for i in range(130):
 print(xnew[i], ynew[i], file = outfile);


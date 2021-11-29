/* Programa que utiliza o método de Runge-Kutta de segunda ordem para calcular a EDO:

 dy/dx = x - y +2
 
*/

#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <complex>
using namespace std;

int main(){

 double h;
 int number_of_steps = 10;
 
 h = 1/((double) number_of_steps);

 double x_0 = 0.0;
 double xmax = h*number_of_steps;

 double k1, k2, *y, *x;
 
 x = new double[11];
 y = new double[11];
 y[0] = 2;
 x[0] = 0;
 
  for(int i = 0; i <= number_of_steps; i++){
  
  k1 = x[i] - y[i] + 2;
  
  k2 = (x[i] + h) - (y[i] + h*k1) + 2;
 
  y[i + 1] = y[i] + h*(k1 + k2)*0.5;
  
  cout << i << " " << x[i] << " " << y[i] << endl; 
  
  x[i + 1] = x[i] + h;
     
  }
   
 
return 0;
}

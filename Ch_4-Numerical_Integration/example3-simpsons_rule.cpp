/* A simple function which implements Simpson's rule

example: int e^{0.9x}(x - b) e^{-1/2(x - 4/2){^2}} dx, 0.0 to 10
*/

#include <iostream>
#include <math.h>
#include <fstream>
#include <iomanip>
using namespace std;

int main(){

 ofstream outfile;
 outfile.open("example3-simpsons_rule.txt"); 

//intervals
 double a = 0.0; 
 double b = 10.0;

 double simpson_sum = 0.0;
 double fa, fb, x, step;
 int j;

 int n = 12;  //number of points

 step = (b - a)/((double) n);
 fa = exp(0.9*a)*(a - 0.01)*exp(-0.5*pow((a - 4)/2,2));
 fb = exp(0.9*b)*(b - 0.01)*exp(-0.5*pow((b - 4)/2,2)); 
 
 simpson_sum = fa + fb; 
 
 for (j = 1; j <= n-1; j++){
      x = j*step + a;	
   
       if(j%2 == 0){
	simpson_sum = simpson_sum + 2*(exp(0.9*x)*(x - 0.01)*exp(-0.5*pow((x - 4)/2,2))); 
	}
	else{
	simpson_sum = simpson_sum + 4*(exp(0.9*x)*(x - 0.01)*exp(-0.5*pow((x - 4)/2,2)));	
	}
  
   simpson_sum = (simpson_sum)*(step/3);
   outfile << x << " " << simpson_sum << endl; 

  }
simpson_sum = simpson_sum*step/3;
cout << setprecision(6) << "I = " << simpson_sum << endl;
outfile.close();
return 0;
}

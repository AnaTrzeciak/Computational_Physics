/* A simple function which implements the simpson's rule

example: int x^2
*/

#include <iostream>
#include <math.h>
#include <fstream>
#include <iomanip>
using namespace std;

//Defining function
#define f(x) 4/(1 + x*x)
//#define f(x) exp(0.904 - 0.184*x -0.0878*pow(x,2))*sqrt(pow(x - 1.3,2) - pow(0.511,2))*(x - 1.3)*pow(x, -0.07056 + 0.02018*log(x) - 0.001953*pow(log(x),3))
 

int factorial(int n){
  if(n == 0 || n ==1){return 1;}
  else {return n*factorial(n -1);};
} 

int main(){

 double comb, result, globalerror;
 double a = 0.0;
 double b = 1.0;
 
 double step = (b - a)/100.0;

 for(int i = 0; i <=4; i++){
//combination (n x)
 comb = factorial(4)/(factorial(i)*factorial(4-i));
  
 double j = a + i*step;
 
 result += comb*f(j)*pow(-1, i +4);
}
 
 result = result/pow(step,4);

 globalerror = ((b - a)*pow(step,4)*result)/180;
 cout << "global error = " << globalerror << endl; 

return 0;

}

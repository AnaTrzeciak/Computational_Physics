/* A simple function which implements the global error for trapeizodal rule

example: int x^2
*/

#include <iostream>
#include <math.h>
#include <fstream>
#include <iomanip>
using namespace std;

//Defining function
#define f(x) 1/(x)
//#define f(x) exp(0.904 - 0.184*x -0.0878*pow(x,2))*sqrt(pow(x - 1.3,2) - pow(0.511,2))*(x - 1.3)*pow(x, -0.07056 + 0.02018*log(x) - 0.001953*pow(log(x),3))
 

int factorial(int n){
  if(n == 0 || n ==1){return 1;}
  else {return n*factorial(n -1);};
} 

int main(){

 double comb, result, globalerror;
 double a = 3.0;
 double b = 3.6;  
 int n;    //number of steps

 cout << "Number of steps: " << endl;
 cin >> n;

 double step = (b - a)/((double) n);

 for(int i = 0; i <= 2; i++){
//combination (n x)
 comb = factorial(4)/(factorial(i)*factorial(4-i));
  
 double j = a + i*step;
 
 result += comb*f(j)*pow(-1, i + 2);
}
 
 result = result/pow(step,2);

 globalerror = ((b - a)*pow(step,2)*result)/12;
 cout << "global error = " << globalerror << endl; 

/* second way */
  


return 0;

}

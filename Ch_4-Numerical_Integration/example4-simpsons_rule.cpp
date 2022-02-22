/* A simple function which implements Simpson's rule

example: int e^{0.9x}(x - b) e^{-1/2((x - 4)/2){^2}} dx, 0.0 to 10
*/


#include<iostream>
#include<math.h>
#include <fstream>
#include <iomanip>
/* Define function here */
//#define f(x) exp(0.9*x)*(x - 0.01)*exp(-0.5*pow((x - 4)/2,2))
#define f(x) sin(2*x)*exp(x)*(x - 0.01)


using namespace std;
int main()
{

 ofstream outfile;
 outfile.open("example4-simpsons_rule.txt");

 float lower, upper, integration=0.0, stepSize, k;
 int i, subInterval;

 /* Input */
 //cout<<"Enter lower limit of integration: ";
 //cin>>lower;
 //cout<<"Enter upper limit of integration: ";
 //cin>>upper;
 lower = 0.0;
 upper = 10.0; 
 cout<<"Enter number of sub intervals: ";
 cin>>subInterval;

 /* Calculation */

 /* Finding step size */
 stepSize = (upper - lower)/subInterval;

 cout << stepSize << endl;

 /* Finding Integration Value */
 integration = f(lower) + f(upper);

 for(i=1; i<= subInterval-1; i++)
 {
  k = lower + i*stepSize;

  if(i%2==0)
  {
    integration = integration + 2 * (f(k));
  }
  else
  {
    integration = integration + 4 * (f(k));
  }

 outfile << k << " " << integration*stepSize/3 << endl;

 }

 integration = integration * stepSize/3;

 cout << setprecision(15) << "I = "<< integration << endl;

 outfile.close();
 return 0;
}

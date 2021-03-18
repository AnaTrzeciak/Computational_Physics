/*Exercise 2.1: Converting from decimal to binary representation
Set up an algorithm which converts a floating number given in the decimal representation to the binary
representation. You may or may not use a scientific representation. Write thereafter a program which
implements this algorithm.*/

#include<iostream>
#include<math.h>

using namespace std;

int main(){

int number, b[7];

cout << "Enter with a number: ";
cin >> number;

 for(int i = 7; i >= 0; i--){
   if(number % 2  == 0){
      b[i] = 0;	
      number /= 2;
   }
   else{
      b[i] = 1;
      number /= 2;
  }
}

 for(int i =0; i <= 7; i++){
    cout << b[i] << endl;
 }
}

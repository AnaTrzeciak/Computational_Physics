#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char* argv[]){

 if(argc <=1){
   cout << "Bad usage: " << argv[0] << " read also a number on the same line, e.g., prog.exe 0.2" << endl;
 }


//convert the text argv[1] to doube using atof:
double r = atof(argv[1]);
double s = sin(r);

cout << "Hello, World!! sin(" << r << ")=" << s << endl;
return 0;
}


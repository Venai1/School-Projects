#include <iostream>
using namespace std;

//passing through a pointer to a function, taking in a double parameter
typedef double (*FUNC)(double);



//integrate function takes the function value at delta and adds it to the sum.
double integrate(FUNC f, double a, double b) {
   double sum = 0, delta = .0001;
   for (double x = a + delta/2; x < b; x += delta) 
      sum += f(x) * delta;                             
   return sum;
}

//declaring functions that we can pass into the integration function
double line(double x){
   return x;
}

double square(double x){
   return x*x;
}

double cube(double x){
   return x*x*x;
}

int main() {
   cout<< "The integral of f(x)=x between 1 and 5 is: "<<integrate(line, 1, 5)<<endl;
   cout<< "The integral of f(x)=x^2 between 1 and 5 is: "<<integrate(square, 1, 5)<<endl;
   cout<< "The integral of f(x)=x^3 between 1 and 5 is: "<<integrate(square, 1, 9)<<endl;
   return 0;
}
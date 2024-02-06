#include <iostream>
#include <cmath>
#include <iomanip>  // For setw function
using namespace std;

// #define f(x) sin(x) + pow(x, 2) + 5 * x - 9
// #define df(x) cos(x) + 2 * x + 5
// #define f(x) (pow(x,2)-5*x+6)
// #define df(x) (2*x-5)
// #define f(x) (pow(x,3)-6*pow(x,2)+11*x -6)
// #define df(x) (3*pow(x,2)-6*2*x+ 11)
// #define f(x) (pow(x,5) - 3*(pow(x,2)) - 100)
// #define df(x) (5*pow(x,4)-3*2*x)
#define f(x) (pow(x,4)-21*pow(x,3)+149*pow(x,2)-399*x+270)
#define df(x) (4*pow(x,3)-21*3*pow(x,2)+149*2*x-399)
#define e 0.05

int main() {
    int i = 0;
    double xold, xnew, fxold, dfxold, result,error;

    cout << "Enter the value of x:" << endl;
    cin >> xold;

cout << setw(20) << "No. of Iteration:" << setw(20) << "Xold" << setw(25) << "f(Xold)" << setw(23)<<"f'(Xold)"<<setw(18)<<"Xnew"<<setw(20)<<"Error:"<<endl;
    
    do {
        fxold = f(xold);
        dfxold = df(xold);
        xnew = xold - (fxold / dfxold);

     if (xnew != 0) {
            error = fabs((xnew - xold) / xnew);
        } else {
            error = 0;
        }

        result = fxold;
        
       i++;
       
        cout << setw(10) << i << setw(30) << xold << setw(25) << fxold <<setw(20) << dfxold <<setw(20)<<xnew<<setw(20)<<error<<endl;
        xold = xnew;
         
    } while (fabs(result) >= e);

    return 0;
}

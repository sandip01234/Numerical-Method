/*Write a program to implement least square approximation for linear data:*/

#include <iostream>
using namespace std;

float Calculate(float a, float b, int x) {
    return (a + b * x);
}

int main() {
    int size;
    cout << "Enter size of data: ";
    cin >> size;
    
    float* x = new float[size]; // Dynamic allocation
    float* y = new float[size]; // Dynamic allocation
    float x2 = 0, xy = 0, xtotal = 0, ytotal = 0; // Correctly initialized
    float b, a;
   
    for (int i = 0; i < size; i++) {
        cout << "Enter value for x" << i << ": ";
        cin >> x[i];
        xtotal += x[i];
        x2 += x[i] * x[i];
        
        cout << "Enter value for y" << i << ": ";
        cin >> y[i];
        ytotal += y[i];
        xy += (x[i] * y[i]);
    }
   
    b = (float)(size * xy - xtotal * ytotal) / (size * x2 - (xtotal) * (xtotal));
    a = (float)(ytotal / size) - b * (xtotal / size);
   
    cout << "y = " << a << " + " << b << " * x" << endl;
    
    // Testing the calculated coefficients with a new x value
    int val;
    cout << "Enter x to predict y: ";
    cin >> val;
    cout << "Predicted y = " << Calculate(a, b, val) << endl;

    // Cleaning up dynamically allocated memory
    delete[] x;
    delete[] y;

    return 0;
}

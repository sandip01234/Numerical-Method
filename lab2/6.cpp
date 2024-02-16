/*Write a program to implement least square approximation for Non-linear data:*/

#include <iostream>
#include<cmath>
using namespace std;
float Calculate(float a, float b, int x){
    return (a*exp(b*x));
}
int main()
{
    int size;
    cout<<"Enter size of data: ";
    cin>>size;
    float x[size],y[size],x2,xy,xtotal,ytotal;
    float b,a;
    float result;
   
    for(int i=0;i<size;i++){
        cout<<"Enter value for x"<<i<<":";
        cin>>x[i];
        // x[i]=log(x[i]);
        xtotal=xtotal+x[i];
        x2=x2+x[i]*x[i];
        cout<<"Enter value for y"<<i<<":";
        cin>>y[i];
        y[i]=log(y[i]);
        ytotal=ytotal+y[i];
        xy=xy+(x[i]*y[i]);
    }
   
    b=(float)(size*xy-xtotal*ytotal)/(size*x2-(xtotal)*(xtotal));
    a=(float)(ytotal/size)-b*(xtotal/size);
    a=exp(a);
    cout<<"y="<<a<<" * "<<"e"<<"^"<<"("<<b<<"x)"<<endl;
    int val;
    cout<<"Enter x:";
    cin>>val;
    cout<<"y= "<<Calculate(a,b,val);

    return 0;
}
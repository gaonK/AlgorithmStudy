#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double x,y,c;
    cin>>x>>y>>c;
    double left, right, mid;
    left =0, right = min(x,y);
    while(abs(right-left)>=1e-6){
        mid = (left+right)/2;
        double d = mid ;
        double h1 = sqrt(x*x - d*d);
        double h2 = sqrt(y*y - d*d);
        double h = h1*h2/(h1+h2);
        if(h>c){
            left = mid;
        }
        else{
            right = mid;
        }
    }
    printf("%.3lf\n",mid);
}
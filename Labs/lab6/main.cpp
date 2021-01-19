#include <iostream>
using namespace std;

float Power(float X, int p)
{
   // Terminating conditions
   // if p is 0 then
   //    X^p is 1
    if (p == 0)
        return 1;
   // if p is 1 then
   //    X^p is X
    if (p == 1)
        return X;
    
    float temp = 0;
        
   // if p is negative
    if (p < 0)
    {
        p *= -1;
        temp = Power(X, p);
        return (1.0 / temp);
    }
    
   // Recursive cases
   // if p is an even number then
   //    X^p = X^(p/2) * X^(p/2)
    if ((p % 2 == 0))
    {
        temp = (Power(X, p/2));
        return temp * temp;
    }
       
   // if p is an odd number then
   //    X^p = X^(p/2) * X^(p/2) * X
    if ((p % 2 == 1))
    {
        temp = (Power(X, p/2));
        return temp * temp * X;
    }
}

int main()
{
    float x = 0;
    int p = 0;
    float power = 0;
    
    cout << "enter x: ";
    cin >> x;
    cout << "enter p: ";
    cin >> p;
    
    power =  Power(x,p);
    cout << x<< "^" << p << " = " << power;
    
 
    
    return 0;
}
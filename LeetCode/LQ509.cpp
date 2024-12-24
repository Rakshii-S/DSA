//nth Fibonacci term
#include <iostream>
using namespace std;

int Fibonacci(int n)
{
    //initially 0 and 1 are the starting numbers which is needed to be added
    //also a base cae
    if(n == 0 || n == 1)
        return n;
    return Fibonacci(n-1) + Fibonacci(n-2);
}
int main()
{
    int n;
    cout<<"Enter the range: ";
    cin>>n;
    cout<<"Fibonacci number at the "<<n<<"th term is "<<Fibonacci(n);
    return 0;
}
//0,1,1,2,3,5,8
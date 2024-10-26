#include <iostream>
using namespace std;

int Fibonacci(int n)
{
    int a=0,b=1,c;
    cout<<a<<" "<<b<<" ";
    for(int i=0;i<n-2;i++)
    {
        c= a + b;
        cout<<c<<" ";
        a = b;
        b = c;
    }
    return 0;
}
int main()
{
    int n;
    cout<<"Enter the range: ";
    cin>>n;
    cout<<n<<" Fibonacci series: ";
    Fibonacci(n);
}
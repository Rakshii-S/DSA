#include <iostream>
using namespace std;

int NFactorial(int n)
{
    int fact =1;
    for(int i=1;i<=n;i++)
    {
        fact *= i;
    }
    return fact;
}
int main()
{
    int n;
    cout<<"Enter the range: ";
    cin>>n;
    cout<<"Factorial of "<<n<<" number is: "<<NFactorial(n);
}
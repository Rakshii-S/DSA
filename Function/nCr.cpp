#include <iostream>
using namespace std;

int Factorial(int val)
{
   int fact =1;
   for(int i=1;i<=val;i++)
   {
        fact *= i;
   }
   return fact;
}
int main()
{
    int n,r,ans;
    cout<<"Reminder: r value should be always less than n.\n";
    cout<<"Enter the n value: ";
    cin>>n;
    cout<<"Enter the r value: ";
    cin>>r;
    ans = Factorial(n)/(Factorial(r)*(Factorial(n-r)));
    cout<<"Binomial Coefficient of "<<n<<" and "<<r<<" is: "<<ans;
}
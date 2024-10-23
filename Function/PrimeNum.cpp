#include <iostream>
using namespace std;

int IsPrime(int n)
{
    int flag=1;
    for(int i=2;i<n;i++)
    {
        if(n%i == 0)
        {
            flag = 0;
        }
    }
    if(flag == 1)
    {
        return true;
    }
}
int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<"Prime numbers from 2 to "<<n<<" are: ";
    for(int i=2;i<=n;i++)
    {
        if(IsPrime(i) ==  true)
        {
            cout<<i<<" ";
        }
    }
}
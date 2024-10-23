#include <iostream>
using namespace std;

int SumOfDigits(int n)
{
    int sum = 0, lastDigit;
    while(n>0)
    {
        lastDigit = n%10;
        sum += lastDigit;
        n = n/10;
    }
    return sum;
}
int main()
{
    int n;
    cout<<"Enter the range: ";
    cin>>n;
    cout<<"Sum of digits of "<<n<<" number is: "<<SumOfDigits(n);
}
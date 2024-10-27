#include <iostream>
using namespace std;

int Pow(int x, int n)
{
    long binaryForm = n;
    double ans =1;
    //corner cases
    if(n == 0) return 1;
    if(x == 0) return 1;
    if(x == 1) return 1;
    if(x == -1 && x%2 == 0) return 1;
    if(x == -1 && x%2 != 0) return -1;

    //when n is negative
    if(n<0)
    {
        x = 1/x;
        binaryForm = -binaryForm;
    }
    while(binaryForm>0)
    {
        if(binaryForm%2 == 1)
        {
            ans *= x;
        }
        x*=x;
        binaryForm /= 2;
    }
    return ans;
}
int main()
{
    int x, n;
    cout<<"Enter the x value: ";
    cin>>x;
    cout<<"Enter the power value: ";
    cin>>n;
    cout<<"The value of "<<x<<" to the power"<<n<<" is: "<<Pow(x,n);
}
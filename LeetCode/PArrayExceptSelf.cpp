#include <iostream>
using namespace std;

int* PArrayExceptSelf(int nums[], int n)
{
    //the lifetime of static variable is throughout the program
    static int ans[30];
    //prefix;
    ans[0] = 1;
    for(int i=1;i<n;i++)
    {
        ans[i] = ans[i-1] * nums[i-1];
    }
    //suffix 
    int suffix =1; 

    for(int i=n-2;i>=0;i--)
    {
        suffix = suffix * nums[i+1];
        ans[i] *= suffix;
    }
    return ans;
}
int main()
{
    int n;
    cout<<"Enter the array size: ";
    cin>>n;
    int arr[30];
    cout<<"Enter "<<n<<" elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int * ans = PArrayExceptSelf(arr,n);
    cout<<"Product of array except self: ";
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
}
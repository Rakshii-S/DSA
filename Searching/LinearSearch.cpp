#include <iostream>
using namespace std;

int LinearSearch(int a[], int n, int t)
{
    for(int i=0;i<n;i++)
    {
        if(a[i] == t)
        {
             return i+1;
        }
    }
    return -1;
}
int main()
{
    int n, arr[30], target, ans;
    cout<<"Enter the size: ";
    cin>>n;
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the search element: ";
    cin>>target;
    ans  = LinearSearch(arr,n,target);
    if( ans == -1)
    {
        cout<<"Element not found.";
    }else{
        cout<<"Element found at position "<<ans;
    }
}
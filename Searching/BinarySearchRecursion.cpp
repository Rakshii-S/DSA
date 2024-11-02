#include <iostream>
using namespace std;

int BinarySearch(int arr[], int n, int target, int st, int en)
{
    int mid;
    if(st<=en)
    {
        mid = st + (en-st)/2;
        if(target< arr[mid])
        {
            return BinarySearch(arr,n,target,st,mid-1);
        }
        else if(target > arr[mid])
        {
            return BinarySearch(arr,n,target,mid+1,en);
        }else{
            return mid+1;
        }
    }
    return -1;
}
int main()
{
    int n, target, arr[30], ans;
    cout<<"Enter the size: ";
    cin>>n;
    cout<<"Enter "<<n<<" elements to the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the target value: ";
    cin>>target;
    int start = 0, end = n-1;
    ans= BinarySearch(arr,n,target,start,end);
    if(ans == -1)
    {
        cout<<"Target element not found.";
    }else{
        cout<<"Target element found at position "<<ans<<".";
    }
}
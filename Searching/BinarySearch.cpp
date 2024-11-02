#include <iostream>
using namespace std;

int BinarySearch(int arr[], int n, int target)
{
    int st = 0, en = n-1, mid;
    while(st<=en)
    {
        mid = st + (en-st)/2;
        if(target< arr[mid])
        {
            en = mid-1;
        }
        else if(target > arr[mid])
        {
            st = mid+1;
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
    ans= BinarySearch(arr,n,target);
    if(ans == -1)
    {
        cout<<"Target element not found.";
    }else{
        cout<<"Target element found at position "<<ans<<".";
    }
}
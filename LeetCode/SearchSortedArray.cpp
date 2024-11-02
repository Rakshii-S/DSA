#include <iostream>
using namespace std;

int SearchSortedArray(int arr[], int n, int t)
{
    int st=0, en=n-1, mid;
    while(st<=en)
    {
        mid = st + (en-st)/2;
        if(arr[mid] == t)
            return mid+1;
        if(arr[st] < arr[mid]) //left half is sorted
        {
            if(arr[st]<=t && t<= arr[mid])
                en = mid-1;
            else
                st = mid+1;
        }
        else //right half is sorted
        {
            if(arr[mid]<=t && t<= arr[en])
                st = mid+1;
            else
                en = mid-1;
        }
    }
    return -1;
}

int main()
{
    int n, arr[30],t;
    cout<<"Enter the size: ";
    cin>>n;
    cout<<"Enter "<<n<<" elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the target: ";
    cin>>t;
    int ans = SearchSortedArray(arr,n,t);
    if(ans == -1)
        cout<<"Target value not found.";
    else 
        cout<<"Target value found at position "<<ans; 
}

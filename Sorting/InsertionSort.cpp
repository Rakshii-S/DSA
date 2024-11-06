#include <iostream>
using namespace std;

int InsertionSort(int arr[], int n)
{
    int curr, prev;
    for(int i=1;i<n;i++)
    {
        curr = arr[i];
        prev = i-1;
        while(prev>=0 && arr[prev]>curr)
        {
            arr[prev+1] =arr[prev];
            prev--;
        }
        arr[prev+1] = curr;
    }
}
int main()
{
    int n,arr[30];
    cout<<"Enter the range: ";
    cin>>n;
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    InsertionSort(arr,n);
    cout<<"Array after performing insertion sort: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
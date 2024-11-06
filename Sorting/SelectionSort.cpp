#include <iostream>
using namespace std;

int SelectionSort(int arr[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        int smallIndex = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[smallIndex])
                smallIndex = j;
        }
        swap(arr[i], arr[smallIndex]);
    }
}
int main()
{
    int n, arr[30]; 
    cout<<"Enter the range: ";
    cin>>n;
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    SelectionSort(arr,n);
    cout<<"Array after performing selection sort: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
#include <iostream>
using namespace std;

int BubbleSort(int arr[], int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        bool isSwap = false;
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                isSwap = true;
            }
        }
        if(isSwap == false)//array is already sorted
        {
            return 0;
        }
    }
}
int main()
{
    int n, arr[30];
    cout<<"Enter the range: ";
    cin>>n;
    cout<<"Enter "<<n<<" elements to the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Array after performing bubble sort: ";
    BubbleSort(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
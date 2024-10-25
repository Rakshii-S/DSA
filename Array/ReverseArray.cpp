#include <iostream>
using namespace std;

int ReverseArray(int n, int arr[])
{
    int start=0, end =n-1;
    while(start<end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
    return 0;
}
int main()
{
    int n, arr[30];
    cout<<"Enter the size: ";
    cin>>n;
    cout<<"Enter "<<n<<" elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    } 
    ReverseArray(n,arr);
    cout<<"Reversed Array elements: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
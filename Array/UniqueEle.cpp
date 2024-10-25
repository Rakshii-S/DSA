#include <iostream>
#include <climits>
using namespace std;

int UniqueEle(int n, int arr[])
{
    int count = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i] == arr[j])
            {
                count++;
            }
        }
        if(count == 1)
        {
            cout<<arr[i]<<" ";
        }
        count = 0;
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
    cout<<"Unique elements are: ";
    UniqueEle(n,arr);
}
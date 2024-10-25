#include <iostream>
#include <climits>
using namespace std;

int SwapMaxNMin(int n, int arr[])
{
    int min=INT_MAX, max=INT_MIN, maxIndex, minIndex;
    for(int i=0;i<n;i++)
    {
       if(arr[i]>max)
       {
            max= arr[i];
            maxIndex =i;
       }
       if(arr[i]< min)
       {
            min = arr[i];
            minIndex = i;
       }
    }
    swap(arr[minIndex], arr[maxIndex]);
    cout<<"Minimum is: "<<min<<endl;
    cout<<"Maximum is: "<<max<<endl;
    cout<<"After swapping max and min: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
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
    SwapMaxNMin(n,arr);
}
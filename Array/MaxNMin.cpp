#include <iostream>
#include <climits>
using namespace std;

int MaxNMin(int n, int arr[])
{
    int minimum=INT_MAX, maximum=INT_MIN;
    for(int i=0;i<n;i++)
    {
       if(arr[i]>maximum)
       {
            maximum = arr[i];
       }
       if(arr[i]< minimum)
       {
            minimum = arr[i];
       }
    }
    cout<<"Minimum is: "<<minimum<<endl;
    cout<<"Maximum is: "<<maximum;
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
    MaxNMin(n,arr);
}
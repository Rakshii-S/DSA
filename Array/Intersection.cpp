#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int Intersection(int n, int a1[], int a2[])
{
    sort(a1,a1+n);
    sort(a2,a2+n);
    int i=0, j=0;
    while(i<n && j<n)
    {
        if(i>0 && a1[i] == a1[i-1])
        {
            i++;
            continue;
        }
        if( j>0 && a2[j] == a2[j-1]){
            j++;
            continue;
        }
        if(a1[i]<a2[j])
        {
            i++;
        }else if(a1[i]>a2[j])
        {
            j++;
        }else{
            cout<<a1[i]<<" ";
            i++;
            j++;
        }
    }
    return 0;
}

int main()
{
    int n, arr1[30],arr2[30];
    cout<<"Enter the size: ";
    cin>>n;
    cout<<"Enter "<<n<<" elements for array 1: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
    } 
    cout<<"Enter "<<n<<" elements for array 2: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr2[i];
    } 
    cout<<"Intersection of two arrays: ";
    Intersection(n,arr1,arr2);
}
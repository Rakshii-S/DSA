#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int> &arr, int st, int mid, int en, long &cnt)
{
    int i = st, j = mid+1;
    vector<int>temp;
    while(i<=mid && j<=en)
    {
        if(arr[i]<=arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            cnt += (mid-i+1);
            j++;
        }
    }
    while(i<=mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=en)
    {
        temp.push_back(arr[j]);
        j++;
    }
    for(int idx = 0;idx<temp.size();idx++)
    {
        arr[idx+st] =  temp[idx];
    }
}
void MergeSort(vector<int> &arr, int st, int en, long &cnt)
{
    if(st<en)
    {
        int mid = st + (en-st)/2;
        MergeSort(arr, st, mid,cnt);
        MergeSort(arr,mid+1,en,cnt);
        Merge(arr, st,mid,en,cnt);
    }
}
int main()
{
    int n;
    long cnt=0;
    cout<<"Enter the count of values: ";
    cin>>n;
    vector<int> arr(n,0);
    cout<<"Enter "<<n<<" values: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    MergeSort(arr,0,n-1,cnt);
    cout<<"The count inversions is: "<<cnt;
}
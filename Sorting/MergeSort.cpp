#include <iostream>
#include <vector>

using namespace std;

void MergeSort(vector<int> &num, int st1, int mid, int en)
{
    int i = st1, j = mid+1;
    vector<int> temp;
    while(i<=mid && j <=en)
    {
        if(num[i]<=num[j])
        {
            temp.push_back(num[i]);
            i++;
        }else{
            temp.push_back(num[j]);
            j++;
        }
    }
    while(i<=mid)
    {
        temp.push_back(num[i]);
        i++;
    }
    while(j<=en)
    {
        temp.push_back(num[j]);
        j++;
    }
    for(int idx = 0;idx<temp.size();idx++)
    {
        num[idx+st1] = temp[idx];
    }
}
void DividetheArray(vector<int> &num, int st, int en)
{
    int mid;
    if(st<en)
    {
        mid = st + (en-st)/2;
        DividetheArray(num, st, mid);
        DividetheArray(num, mid+1, en);
        MergeSort(num,st,mid,en);
    }
}
int main()
{
    int n;
    cout<<"Enter the count of numbers: ";
    cin>>n;
    vector<int> num(n,0);
    cout<<"Enter the values: ";
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    int st = 0, en = n-1;
    DividetheArray(num,st,en);

    for(int i=0;i<n;i++){
        cout<<num[i]<<" ";
    }
}
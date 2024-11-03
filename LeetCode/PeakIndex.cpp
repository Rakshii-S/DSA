#include <iostream>
#include <vector>
using namespace std;

int PeakIndex(vector<int> &nums, int n)
{
    int st = 1, en = n-2, mid;
    while(st<=en)
    {
        mid = st + (en-st)/2;
        if(nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1])
        {
            return mid+1;
        }
        if(nums[mid-1]<nums[mid])//increment
        {
            st = mid+1;
        }else{
            en = mid-1;
        }
    }
}
int main()
{
    int n;
    cout<<"Enter the range: ";
    cin>>n;
    vector<int> vec(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
    }
    cout<<"Peak index in a mountain aray: "<<PeakIndex(vec,n);
}
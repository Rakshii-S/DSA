#include <iostream>
#include <vector>
using namespace std;

void Merge2SortedArray(vector<int>&A, int m, vector<int>&B, int n)
{
    int idx = m+n-1, i = m-1, j = n-1;
    while(i >= 0 && j >= 0)
    {
        if(A[i] >= B[j])
        {
            A[idx--] = A[i--];
        }else
        {
            A[idx--] = B[j--];
        }
    }
    //when i becomes less than zero
    while(j >= 0)
    {
        A[idx--] = B[j--];
    }
}
int main()
{
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    Merge2SortedArray(nums1, nums1.size()-nums2.size(), nums2, nums2.size());
    for(int i=0;i<nums1.size();i++)
    {
        cout<<nums1[i]<<" ";
    }
}
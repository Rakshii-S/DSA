#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    int n,k;
    cout<<"Enter the range: ";
    cin>>n;
    vector<int> nums(n,0);
    cout<<"Enter the values: ";
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    cout<<"Enter the target value: ";
    cin>>k;

    //calculation
    //prefix sum
    vector<int>PrefixSum(n,0);
    unordered_map<int,int> m;
    PrefixSum[0] = nums[0];
    int count = 0;
    for(int i=1;i<n;i++)
    {
        PrefixSum[i] = PrefixSum[i-1] + nums[i];
    }

    for(int j=0;j<n;j++)
    {
        if(PrefixSum[j] == k) count++;

        int val = PrefixSum[j] - k;
        if(m.find(val) != m.end())
        {
            count+= m[val];
        }

        if(m.find(PrefixSum[j]) == m.end())
        {
            m[PrefixSum[j]] = 0 ;
        }
        m[PrefixSum[j]]++;
    }

    cout<<"The count of subarray sum which is equal to to k is: "<<count;
}
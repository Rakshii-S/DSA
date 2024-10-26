#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int MaximumSubarray(vector<int> &vec, int n)
{
    int maxSum =INT_MIN, currSum =0;
    for(int i=0;i<n;i++)
    {
        currSum += vec[i];
        maxSum = max(maxSum, currSum);
        if(currSum<0)
        {
            currSum =0;  
        }
    }
    return maxSum;
}
int main()
{
    int n;
    cout<<"Enter the size: ";
    cin>>n;
    cout<<"Enter the elements: ";
    vector<int> vec(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
    }
    cout<<"Maximum subarray sum is: "<<MaximumSubarray(vec,n);
}
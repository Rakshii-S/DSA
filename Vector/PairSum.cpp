#include <iostream>
#include <vector>
using namespace std;

vector<int> PairSum(int n, vector<int> &vec, int t)
{
    int start=0 , end =n-1, sum;
    vector<int> ans;
    while(start<end)
    {
        sum = vec[start] +vec[end];
        if(sum>t)
        {
            end--;
        }else if(sum<t)
        {
            start++;
        }else{
            ans.push_back(start+1);
            ans.push_back(end+1);
            return ans;
        }
    }
    ans.push_back(-1);
    return ans;
}
int main()
{
    int n, target;
    cout<<"Enter the size: ";
    cin>>n;
    vector<int> nums(n,0), ans;
    cout<<"Enter "<<n<<" elements in ascending order: ";
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    } 
    cout<<"Enter the target sum: ";
    cin>>target;
    ans = PairSum(n,nums, target);
    if(ans[0] == -1)
    {
        cout<<"There are no such pairs whose sum is equal to the target value.";
    }else{
        cout<<"Pair sum found at positions: "<<ans[0]<<" and "<<ans[1];
    }
}
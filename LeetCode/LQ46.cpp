#include <iostream>
#include <vector>
using namespace std;

void GetPermutations(vector<int> &nums, int idx, vector<vector<int>> &ans)
{
    if(idx == nums.size()-1)
    {
        ans.push_back({nums});
    }

    //here loop is used to find all possible permutations for that particular index
    for(int i=idx;i<nums.size();i++)
    {
        swap(nums[idx], nums[i]);
        GetPermutations(nums, idx+1, ans);
        swap(nums[idx], nums[i]);
    }
}

int main()
{
    int n;
    cout<<"Enter the range: ";
    cin>>n;
    vector<int>nums(n,0);
    cout<<"Enter the values: ";
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    //getting all possible permutations
    int idx = 0;
    vector<vector<int>> ans;
    GetPermutations(nums,idx, ans);

    cout<<"All the possible permutations are: ";
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[0].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
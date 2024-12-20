#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n,targ;
    cout<<"Enter the range: ";
    cin>>n;
    vector<int>nums(n,0);
    cout<<"Enter the values: ";
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    cout<<"Enter the target: ";
    cin>>targ;

    //calculations
    sort(nums.begin(), nums.end());
    vector<vector<int>>ans;
    for(int i=0;i<n;i++)
    {
        if(i>0 && nums[i] == nums[i-1]) continue;
        for(int j=i+1;j<n;)
        {
            int st = j+1, en = n-1;
            while(st<en)
            {
                int sum = nums[i] + nums[j] + nums[st] + nums[en];
                if(sum>targ)
                    en--;
                else if(sum<targ)
                    st++;
                else
                {
                    ans.push_back({nums[i],nums[j], nums[st], nums[en]});
                    st++,en--;
                    while(st<en && nums[st] == nums[st-1]) st++;
                }
            }
            j++;
            while(j<n && nums[j] == nums[j-1]) j++;
        }
    }

    cout<<"Combinations: "<<endl;
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
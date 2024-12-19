#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the range: ";
    cin>>n;
    vector<int> nums(n,0);
    cout<<"Enter "<<n<<" values: ";
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }

    sort(nums.begin(),nums.end());
    //calculations
    vector<vector<int>> ans;
    for(int i=0;i<n;i++)
    {
        if(i>0 && nums[i] == nums[i-1]) 
            continue;
        int st = i+1, en = n-1;
        while(st<en)
        {
            int sum = nums[i]+nums[st]+nums[en];
            if(sum>0)
                en--;
            else if(sum<0)
                st++;
            else
            {
                ans.push_back({nums[i],nums[st],nums[en]});
                st++, en--;
                while(st<en && nums[st] == nums[st-1]) 
                    st++;
            }
        }
    }

    //print
    cout<<"The unique triplets which equals to zero are: ";
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
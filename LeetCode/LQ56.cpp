#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> MergeIntervals(vector<vector<int>> &intervals)
{
    vector<vector<int>> ans;
    for(auto interval: intervals)
    {
        if(ans.empty() || interval[0]>ans.back()[1])
        {
            ans.push_back(interval);
        }
        else{
            vector<int> prev = ans.back();
            ans.pop_back();
            ans.push_back({prev[0], max(prev[1], interval[1])});
        }
    }
    return ans;
}

int main()
{
    int row, col;
    cout<<"Enter the number of rows and columns: ";
    cin>>row>>col;
    vector<vector<int>> itervals(row,vector<int>(col));
    vector<vector<int>> ans;
    cout<<"Enter values for "<<row<<" and  "<<col<<":";
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>itervals[i][j];
        }
    }
    
    ans = MergeIntervals(itervals);
    //output
    cout<<"After performing the process: ";
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[0].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, row, col;
    cout<<"Enter the number of teams: ";
    cin>>n;
    cout<<"Enter the row and col for edges: ";
    cin>>row>>col;
    vector<vector<int>> edges(row,vector<int>(col));
    cout<<"Enter the edges:";
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>edges[i][j];
        }
    }
    //logic
    vector<int> gr(n);
    int count=0, champion=-1;
    for(auto &edge:edges)
    {
        gr[edge[1]]++;
    }

    for(int i=0;i<n;i++)
    {
        if(gr[i] == 0)
        {
            count++;
            champion =i;
        }
    }
    int ans = (count==1)?champion:-1;
    cout<<"The champion is: "<<ans;
}
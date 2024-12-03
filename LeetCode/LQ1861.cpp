#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int row, col;
    cout<<"Enter the row and column: ";
    cin>>row>>col;
    cout<<"Enter the characters(#, *, .): ";
    vector<vector<char>> boxGrid(row,vector<char>(col));
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>boxGrid[i][j];
        }
    }

    //apply gravity
    for(auto &row:boxGrid)
    {
        int empty = row.size()-1;
        for(int j= row.size()-1;j>=0;j--)
        {
            if(row[j] == '*')
            {
                empty = j-1;
            }
            if(row[j] == '#')
            {
                char temp = row[j];
                row[j] = row[empty];
                row[empty] = temp;
                empty--;
            }
        }
    }

    //rotate the box to 90 degree
    vector<vector<char>> res;
    res.resize(col);
    int idx;
    for(int i=boxGrid.size()-1;i>=0;i--)
    {
        idx=0;
        auto &row = boxGrid[i];
        for(char cell:row)
        {
            res[idx].push_back(cell);
            idx++;
        }
    }

    //print output
    cout<<"After rotating the box: ";
    for(auto &row: res)
    {
        for(char cell:row)
        {
            cout<<cell<<" ";
        }
        cout<<endl;
    }

}
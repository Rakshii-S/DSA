#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    int row, col;
    cout<<"Enter the row and column: ";
    cin>>row>>col;
    vector<vector<int>>matrix(row, vector<int> (col));
    cout<<"Enter the matrix values: ";
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>matrix[i][j];
        }
    }

    unordered_map<string, int>patternCount;
    int maxVal = 0;
    for(auto &row:matrix)
    {
        string pattern;
        for(int cell: row)
        {
            char resp = '0' + (row[0] == 0?cell:cell^1);
            pattern.push_back(resp);
        }
        int count = ++patternCount[pattern];
        maxVal = max(maxVal, count);
    }

    cout<<"The maximum number of rows that have all values equal after some number of flips: "<<maxVal;
}
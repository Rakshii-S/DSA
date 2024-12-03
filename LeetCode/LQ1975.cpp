#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int main()
{
    int row, col;
    cout<<"Enter the row and col: ";
    cin>>row>>col;
    vector<vector<int>> matrix(row, vector<int>(col));
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>matrix[i][j];
        }
    }

    //logic
    int minVal=INT_MAX, countNegative = 0;
    long long sum =0;
    for(auto &row:matrix)
    {
        for(int cell: row)
        {
            sum += abs(cell);
            if(cell<0)
            {
                countNegative++;
            }
            minVal = min(minVal, abs(cell));
        }
    }

    if(countNegative%2 == 0)
        cout<<"Maximum matrix sum: "<<sum;
    else
    {
        sum = sum - 2*(minVal);
        cout<<"Maximum matrix sum: "<<sum;
    }
}
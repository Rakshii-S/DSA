#include <iostream>
#include <vector>
using namespace std;

vector<int> SpiralMatrix(vector<vector<int>> &matrix)
{
    vector<int> ans;
    int srow = 0, scol = 0, erow = matrix.size()-1, ecol = matrix[0].size()-1;
     while(srow<=erow && scol<=ecol)
        {
            //top
            for(int j=scol;j<=ecol;j++)
            {
                ans.push_back(matrix[srow][j]);
            }
            //right
            for(int i=srow+1;i<=erow;i++)
            {
                ans.push_back(matrix[i][ecol]);
            }
            //bottom
            for(int j=ecol-1;j>=scol;j--)
            {
                if(srow == erow)
                {
                    break;
                }
                ans.push_back(matrix[erow][j]);
            }
            //left
            for(int i=erow-1;i>=srow+1;i--)
            {
                if(scol == ecol)
                {
                    break;
                }
                ans.push_back(matrix[i][scol]);
            }
            srow++;erow--;scol++;ecol--;
        }
        return ans;
}

int main()
{
    int row, col;
    cout<<"Enter the row and column: ";
    cin>>row>>col;
    vector<vector<int>> matrix(row, vector<int>(col));
    cout<<"Enter the matrix values: ";
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>matrix[i][j];
        }
    }
    vector<int> ans = SpiralMatrix(matrix);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void SetMatrixZeroes(vector<vector<int>> &matrix)
{
    unordered_map<char, pair<int, int>> track;
    int row = matrix.size(), col = matrix[0].size();
    char keyy = 'A';
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(matrix[i][j] == 0)
            {
                track[keyy] = make_pair(i,j);
                keyy++;
            }
        }
    }

    //loop through map and set all the zero value rows and columns to zero!
    for(auto val: track)
    {
        int r = val.second.first, c = val.second.second;
        //change the entire row to zero
        for(int i=0;i<matrix[0].size();i++)
        {
            matrix[r][i] = 0;
        }

        //change the entire column to zero
        for(int i=0;i<matrix.size();i++)
        {
            matrix[i][c] = 0;
        }
    }
    
}
int main()
{
    int row, col;
    cout<<"Enter the number of rows and columns: ";
    cin>>row>>col;
    vector<vector<int>> m(row,vector<int>(col));
    cout<<"Enter values for "<<row<<" and  "<<col<<":";
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>m[i][j];
        }
    }

    SetMatrixZeroes(m);

    cout<<"Matrix after performing the operation: "<<endl;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
}
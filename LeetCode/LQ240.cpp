#include <iostream>
#include <vector>

using namespace std;
bool BinarySearch(vector<vector<int>> &matrix, int target)//O(logn)
{
    int row = 0, col = matrix[0].size()-1;
    while(col>=0 && row<matrix.size())
    {
        if(target == matrix[row][col])
            return true;
        else if(target<matrix[row][col])
            col--;
        else
            row++;
    }
    return false;
}

int main()
{
    int row, col, target;
    cout<<"Enter the row and column: ";
    cin>>row>>col;
    cout<<"Enter the values to the matrix: "<<endl;
    vector<vector<int>> matrix(row, vector<int>(col));
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>matrix[i][j];
        }
    }
    cout<<"Enter the target value: ";
    cin>>target;
    bool ans = BinarySearch(matrix, target);
    if(ans == false)
        cout<<"Not found.";
    else
        cout<<"Found";

}
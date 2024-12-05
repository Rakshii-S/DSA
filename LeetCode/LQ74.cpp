#include <iostream>
#include <vector>

using namespace std;
bool SearchInRow(vector<vector<int>> &matrix, int target, int row)
{
    int n = matrix[0].size();
    int start = 0, end = n-1;
    while(start<=end)
    {
        int mid = start+(end-start)/2;
        if(target == matrix[row][mid])
            return true;
        else if(target>matrix[row][mid])
            start = mid+1;
        else
            end = mid-1;
    }
    return false;
}
bool BinarySearch(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size(), n= matrix[0].size();
    int start = 0, end = m-1;
    while(start<=end)
    {
        int mid = start + (end-start)/2;

        if(target>=matrix[mid][0] && target<=matrix[mid][n-1])
        {
            //apply binary search on this row
            return SearchInRow(matrix, target, mid);

        }else if(target >= matrix[mid][n-1])
        {
            start = mid+1;
        }else{
            end = mid-1;
        }
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
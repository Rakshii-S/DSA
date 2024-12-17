#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main()
{
    int row,col;
    cout<<"Enter the row and column: ";
    cin>>row>>col;
    vector<vector<int>> nums(row, vector<int>(col)); 
    unordered_set<int>val;
    cout<<"Enter values: ";
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
           cin>>nums[i][j];
        }
    }

    //calculations
    int eSum =0, aSum = 0,a,b;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            aSum+=nums[i][j];
            if(val.find(nums[i][j]) != val.end())
            {
                a = nums[i][j]; //repeat
            }
            val.insert(nums[i][j]);
        }
    }
    eSum = (row*row) * (row*row+1)/2;
    b = eSum + a - aSum;//missing
    cout<<a<<" "<<b;
}
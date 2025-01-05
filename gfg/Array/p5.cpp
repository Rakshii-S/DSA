//Move all zeros to end of array

/*Given an array of integers arr[], the task is to move all the zeros to the end of the array while maintaining the relative order of all non-zero elements.

Examples: 

Input: arr[] = [1, 2, 0, 4, 3, 0, 5, 0]
Output: arr[] = [1, 2, 4, 3, 5, 0, 0, 0]
Explanation: There are three 0s that are moved to the end.


Input: arr[] = [10, 20, 30]
Output: arr[] = [10, 20, 30]
Explanation: No change in array as there are no 0s.

Input: arr[] = [0, 0]
Output: arr[] = [0, 0]
Explanation: No change in array as there are all 0s.*/

#include <iostream>
#include <vector>

using namespace std;

void MoveAllZeros(vector<int> &num)
{
    int i=0, j=0, n = num.size();
    while(i<n && j<n)
    {
        if(num[j] == 0 && num[i]==0)
        {
            i++;
            continue;
        }
        if(num[j] == 0 && num[i]!= 0 && i>j)
        {
            swap(num[i], num[j]);
        }
        i++, j++;
    }
}
int main()
{
    int n;
    cout<<"Enter the range: ";
    cin>>n;

    vector<int> num(n,0);
    cout<<"Enter the values: ";
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }

    MoveAllZeros(num);

    //output
    for(int i=0;i<n;i++)
    {
        cout<<num[i]<<" ";
    }
}
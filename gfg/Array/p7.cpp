//Rotate an Array by d – Counterclockwise or Left

/*Given an array of integers arr[] of size n, the task is to rotate the array elements to the left by d positions.

Examples:

Input: arr[] = {1, 2, 3, 4, 5, 6}, d = 2
Output: {3, 4, 5, 6, 1, 2}
Explanation: After first left rotation, arr[] becomes {2, 3, 4, 5, 6, 1} and after the second rotation, arr[] becomes {3, 4, 5, 6, 1, 2}


Input: arr[] = {1, 2, 3}, d = 4
Output: {2, 3, 1}
Explanation: The array is rotated as follows:


After first left rotation, arr[] = {2, 3, 1}
After second left rotation, arr[] = {3, 1, 2}
After third left rotation, arr[] = {1, 2, 3}
After fourth left rotation, arr[] = {2, 3, 1}*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

void RotateArray(vector<int> &num, int d)
{
    //reverse first d elements
    reverse(num.begin(), num.begin() + d);

    //reverse elements after d count
    reverse(num.begin() + d, num.end());

    //reverse the entire array
    reverse(num.begin(), num.end());
}
int main()
{
    int n, d;
    cout<<"Enter the range: ";
    cin>>n;
    vector<int> num(n,0);
    cout<<"Enter the values: ";
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }
    cout<<"Enter the break point (d): ";
    cin>>d;

    RotateArray(num,d);
    cout<<"Value of array after rotating: ";
    for(int i=0;i<n;i++)
    {
        cout<<num[i]<<" ";
    }
    return 0;
}

//TC -> O(n), we are visiting each element twice;
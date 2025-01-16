//Longest Mountain Subarray

/*Given an array arr[] with N elements, the task is to find out the longest sub-array which has the shape of a mountain.

A mountain sub-array consists of elements that are initially in ascending order until a peak element
is reached and beyond the peak element all other elements of the sub-array are in decreasing order.

Examples: 
Input: arr = [2, 2, 2] 
Output: 0 
Explanation: 
No sub-array exists that shows the behavior of a mountain sub-array.

Input: arr = [1, 3, 1, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5] 
Output: 11 
Explanation: 
There are two sub-arrays that can be considered as mountain sub-arrays. The first one is from index 0 – 2 
(3 elements) and next one is from index 2 – 12 (11 elements).  As 11 > 2, our answer is 11.*/

#include <iostream>
#include <vector>
using namespace std;

int LongestMountain(vector<int> &num)
{
    int n = num.size();
    int left=0,right=0,maxC=0;
    bool found=false;
    //cases
    if(n <3) return 0;
    for(int i=1;i<n-1;i++)
    {
        if(num[i-1]<num[i] && num[i]>num[i+1])
        {
            right = i;
            found = true;
        }
        else if(num[i]<num[i+1])
        {
            maxC = max(maxC,right-left+1); 
            left = right;
            found=false;
        }

        if(found == true)
        {
            right++;
        }

        if(found == true && right == n-1)
        {
            maxC = max(maxC,right-left+1); 
        }
    }
    return maxC;
}

int main()
{
    int n;
    cout<<"Enter the count: ";
    cin>>n;
    vector<int> num(n,0);
    cout<<"Enter the value: ";
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }
    int ans =LongestMountain(num);
    if(ans == 1) ans = 0;
    cout<<"Length of longest mountain subarray is: "<<ans;
}
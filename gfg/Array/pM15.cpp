//Minimize the Heights II

/*Given an array arr[] denoting heights of N towers and a positive integer K.
For each tower, you must perform exactly one of the following operations exactly once.

Increase the height of the tower by K
Decrease the height of the tower by K
Find out the minimum possible difference between the height of the shortest and tallest towers after you have modified each tower.

You can find a slight modification of the problem here.
Note: It is compulsory to increase or decrease the height by K for each tower. After the operation, the resultant array should not contain any negative integers.

Input: k = 2, arr[] = {1, 5, 8, 10}
Output: 5
Explanation: The array can be modified as {1+k, 5-k, 8-k, 10-k} = {3, 3, 6, 8}.The difference between the largest and the smallest is 8-3 = 5.
Input: k = 3, arr[] = {3, 9, 12, 16, 20}
Output: 11
Explanation: The array can be modified as {3+k, 9+k, 12-k, 16-k, 20-k} -> {6, 12, 9, 13, 17}.The difference between the largest and the smallest is 17-6 = 11. */

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int MinimizeTheHeight(vector<int> &num, int k)
{
    int maxNum = INT_MIN, minNum = INT_MAX;
    for(int i=0;i<num.size();i++)
    {
        if(num[i]>k)
            num[i] = num[i]-k;
        else
            num[i] = num[i]+k;
    }
    for(int i =0;i<num.size();i++)
    {
        maxNum = max(num[i], maxNum);
        minNum = min(minNum, num[i]);
    }

    for(int i=0;i<num.size();i++)
    {
        cout<<num[i]<<" ";
    }
    cout<<endl<<"The difference between the largest and the smallest is: "<<maxNum - minNum;
}

int main()
{
    int n,k;
    cout<<"Enter the range: ";
    cin>>n;
    vector<int> num(n,0);
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }
    cout<<"Enter the k value: ";
    cin>>k;
    MinimizeTheHeight(num,k);
}
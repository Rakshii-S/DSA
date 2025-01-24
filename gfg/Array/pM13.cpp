//Product of Array Except Self

/*Given an array arr[] of n integers, construct a product array res[] (of the same size) such that res[i] is equal to the product of all the elements of arr[] except arr[i]. 

Example: 

Input: arr[] = [10, 3, 5, 6, 2]
Output: [180, 600, 360, 300, 900]

Explanation: 
For i=0, res[i] = 3 * 5 * 6 * 2 is 180.
For i = 1, res[i] = 10 * 5 * 6 * 2 is 600.
For i = 2, res[i] = 10 * 3 * 6 * 2 is 360.
For i = 3, res[i] = 10 * 3 * 5 * 2 is 300.
For i = 4, res[i] = 10 * 3 * 5 * 6 is 900.

Input: arr[] = [12, 0]
Output: [0, 12]

Explanation: 
For i = 0, res[i] = 0.
For i = 1, res[i] = 12.*/

#include <iostream>
#include <vector>
using namespace std;

void ProductExceptSelf(vector<int> &num)
{
    vector<int>prefix(num.size(),1);
    prefix[0] = 1;
    for(int i=1;i<num.size();i++)
    {
        prefix[i] = prefix[i-1] * num[i-1];
    }
    int suffix = 1;
    for(int i=num.size()-2;i>=0;i--)
    {
        suffix*=num[i+1];
        prefix[i]*=suffix;
    }
    for(int i=0;i<num.size();i++)
    {
        num[i] = prefix[i];
    }
}

int main()
{
    int n;
    cout<<"Enter the range: ";
    cin>>n;
    vector<int> num(n,0);
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }
    ProductExceptSelf(num);
    cout<<"Product of array except self: ";
    for(int i=0;i<num.size();i++)
    {
        cout<<num[i]<<" ";
    }
}
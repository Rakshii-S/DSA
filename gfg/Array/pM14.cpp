//Maximum Product Subarray

/*Given an integer array, the task is to find the maximum product of any subarray.

Examples:

Input: arr[] = {-2, 6, -3, -10, 0, 2}
Output: 180
Explanation: The subarray with maximum product is {6, -3, -10} with product = 6 * (-3) * (-10) = 180


Input: arr[] = {-1, -3, -10, 0, 60}
Output: 60
Explanation: The subarray with maximum product is {60}.*/

#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int MaximumProductSubarray(vector<int> &num)
{
    //sliding window approach
    int end= 0 , start = 0, product = 1, maxProduct = INT_MIN, negativeSignCount = 0;
    while(end<num.size())
    {
        if(num[end] < 0)
            negativeSignCount++;
        
        if(num[end] == 0)
            product = 1;
        else 
            product *= num[end];

        if(start<=end && negativeSignCount >=3)
        {
            if(num[start]<0)
            {
                negativeSignCount--;
            }
            if(num[end] == 0)
                product = 1;
            else 
                product /= num[start];
            start++;
        }
        maxProduct = max(maxProduct, product);
        end++;
    }
    return maxProduct;
}

int main()
{
    int range;
    cout<<"Enter the range of elements: ";
    cin>>range;
    vector<int>num(range,0);
    cout<<"Enter the elements: ";
    for(int i=0;i<range;i++)
    {
        cin>>num[i];
    }
    cout<<"Maximum Product subarray is:    "<<MaximumProductSubarray(num);
}
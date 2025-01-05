//Second Largest Element 

/*Given an array of positive integers arr[] of size n, the task is to find second largest distinct element in the array.

Note: If the second largest element does not exist, return -1.

Examples:

Input: arr[] = [12, 35, 1, 10, 34, 1]
Output: 34
Explanation: The largest element of the array is 35 and the second largest element is 34.


Input: arr[] = [10, 5, 10]
Output: 5
Explanation: The largest element of the array is 10 and the second largest element is 5.


Input: arr[] = [10, 10, 10]
Output: -1
Explanation: The largest element of the array is 10 there is no second largest element.*/

#include <iostream>
#include <vector>

using namespace std;

int SecondLargestEle(vector<int> &num)
{
    int first = -1, second=-1;
    for(int i=0;i<num.size();i++)
    {
        if(num[i]>first)
        {
            second = first;
            first = num[i];
        }else if(num[i]>second && num[i]<first)
        {
            second = num[i];
        }
    }
    return second;
}
int main()
{
    int n;
    cout<<"Enter the range: ";
    cin>>n;
    if(n<2)
    {
        cout<<"Array size should be greater than or equal to 2.";
        return 0;
    }
    vector<int> num(n,0);
    cout<<"Enter the values: ";
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }

    int ans = SecondLargestEle(num);
    if(ans == -1)
        cout<<"Second largest element does not exist.";
    else
        cout<<"The second largest element is: "<<ans;

    return 0;
}
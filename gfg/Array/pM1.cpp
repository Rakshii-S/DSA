//Count ways to make sum of odd and even indexed elements equal by removing an array element

/*Given an array, arr[] of size N, the task is to find the count of array indices such that removing an element from these indices makes the sum of even-indexed and odd-indexed array elements equal.

Examples:


Input: arr[] = { 2, 1, 6, 4 } 
Output: 1 
Explanation: 
Removing arr[1] from the array modifies arr[] to { 2, 6, 4 } such that, arr[0] + arr[2] = arr[1]. 
Therefore, the required output is 1. 


Input: arr[] = { 1, 1, 1 } 
Output: 3 
Explanation: 
Removing arr[0] from the given array modifies arr[] to { 1, 1 } such that arr[0] = arr[1] 
Removing arr[1] from the given array modifies arr[] to { 1, 1 } such that arr[0] = arr[1] 
Removing arr[2] from the given array modifies arr[] to { 1, 1 } such that arr[0] = arr[1] 
Therefore, the required output is 3.*/

#include <iostream>
#include <vector>

using namespace std;

int CountEquals(vector<int> &num)
{
    int n = num.size();
    int evenSum = 0, oddSum = 0, count = 0;
    int prefixEven = 0, prefixOdd = 0;

    //calculate even and odd sum
    for(int i=0;i<n;i++)
    {
        if(i%2 == 0) 
            evenSum += num[i];
        else 
            oddSum += num[i];
    }

    for(int i=0;i<n;i++)
    {
        if(i%2 == 0)
            evenSum -= num[i];
        else 
            oddSum -= num[i];
        
        if(prefixEven+oddSum == prefixOdd+evenSum) count++;

        if(i%2 == 0)
            prefixEven += num[i];
        else
            prefixOdd += num[i];
    }
    return count;
}

int main()
{
    int n;
    cout<<"Enter the range: ";
    cin>>n;
    vector<int> num(n,0);
    cout<<"Enter "<<n<<" elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }

    int ans = CountEquals(num);
    cout<<"The ways to make sum of add and even indexed elements equal by removing an array element is: "<<ans;
}
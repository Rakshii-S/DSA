//Minimum Swaps required to group all 1’s together

/*Given an array of 0’s and 1’s, we need to write a program to find the minimum number of swaps required to group all 1’s present in the array together.

Examples: 

Input : arr[] = {1, 0, 1, 0, 1}
Output : 1
Explanation: Only 1 swap is required to 
group all 1's together. Swapping index 1
and 4 will give arr[] = {1, 1, 1, 0, 0}

Input : arr[] = {1, 0, 1, 0, 1, 1}
Output : 1
A simple solution is to first count total number of 1’s in the array. Suppose
this count is x, now we need to find the subarray of length x of this array with 
maximum number of 1’s. And minimum swaps required will be the number of 0’s in 
the subarray of length x with maximum number of 1’s. 
Time Complexity: O(n2)

An efficient solution is to optimize the brute force technique of finding 
the subarray in above approach using the concept of sliding window technique. 
We can maintain a preCount array to find number of 1’s present in a subarray 
in O(1) time complexity.*/

//slinding window approach
#include <iostream>
#include <vector>
using namespace std;

int MinimumSwaps(vector<int> &num)
{
    int countOfOnes = 0, maxCount = 0, currCount=0;
    int n = num.size();
    for(int i=0;i<n;i++)
    {
        if(num[i] == 1)
            countOfOnes++;
    }
    int i=0,j=0;
    while(j<n)
    {
        if(num[j] == 1) currCount++;
        cout<<num[j]<<" ";
        if((j-i+1) == countOfOnes)
        {
            cout<<endl;
            maxCount = max(maxCount,currCount);
            currCount = 0;
            i++;
            j = i;
        }else{
            j++;
        }
    }
    return (countOfOnes - maxCount);
}

int main()
{
    int n;
    cout<<"Enter the count: ";
    cin>>n;
    vector<int> num(n,0);
    cout<<"Enter the values(1's and 0's): ";
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }
    cout<<"Minimum number of swaps required to group all the 1's together is: "<<MinimumSwaps(num);
    return 0;
}
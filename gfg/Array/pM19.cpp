//Next Permutation

/*Given an array arr[] of size n, the task is to print the lexicographically next greater permutation of the given array. If there does not exist any greater permutation, then find the lexicographically smallest permutation of the given array.

Let us understand the problem better by writing all permutations of [1, 2, 4] in lexicographical order

[1, 2, 4], [1, 4, 2], [2, 1, 4], [2, 4, 1], [4, 1, 2] and [4, 2, 1]

If we give any of the above (except the last) as input, we need to find the next one in sequence. If we give last as input, we need to return the first one.

Examples:
Input: arr = [2, 4, 1, 7, 5, 0]
Output: [2, 4, 5, 0, 1, 7]
Explanation: The next permutation of the given array is 2 4 5 0 1 7


Input: arr = {3, 2, 1]
Output: [1, 2, 3]
Explanation: As arr[] is the last permutation. So, the next permutation is the lowest one.*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void NextPermutation(vector<int> &num)
{
    int pivotIdx = -1;
    for(int i=num.size()-2;i>=0;i--)
    {
        if(num[i] < num[i+1])
        {
            pivotIdx = i;
            break;
        }
    }

    if(pivotIdx == -1)
    {
        reverse(num.begin(), num.end());
        return;
    }

    for(int i=num.size()-1; i>pivotIdx;i--)
    {
        if(num[i]>num[pivotIdx])
        {
            swap(num[i], num[pivotIdx]);
            break;
        }
    }
    reverse(num.begin()+pivotIdx+1, num.end());
    return;
}

int main()
{
    int size;
    cout<<"Enter the size: ";
    cin>>size;
    vector<int>num(size,0);
    cout<<"Enter the elements: ";
    for(int i=0;i<size;i++)
    {
        cin>>num[i];
    }
    NextPermutation(num);
    cout<<"Next Permutation is: ";
    for(int i=0;i<num.size();i++)
    {
        cout<<num[i]<<" ";
    }
    return 0;
}
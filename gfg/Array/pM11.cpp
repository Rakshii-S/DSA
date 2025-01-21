//Split array into three equal sum segments

/*Given an integer array arr[], the task is to divide the array into three non-empty contiguous segments with equal sum. In other words, we need to return an index pair [i, j], such that sum(arr[0…i]) = sum(arr[i+1…j]) = sum(arr[j+1…n-1]).

Note: If it is impossible to divide the array into three non-empty contiguous segments, return [-1, -1].

Examples:

Input: arr[] = [1, 3, 4, 0, 4]
Output: [1, 2]
Explanation: 3 equal sum segments are: arr[0…1], arr[2…2] and arr[3…4] each having sum = 4.


Input: arr[] = [2, 3, 4]
Output: [-1, -1]
Explanation: No three segments exist which has equal sum.


Input: arr[] = [1, -1, 1, -1, 1, -1, 1, -1]
Output: [1, 3]
Explanation: 3 equal sum segments are: arr[0…1], arr[2…3] and arr[4…7] each having sum = 0.*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> FindThePair(vector<int> &num)
{
    int sum = 0, sumofArray = 0, sumToFind = 0;
    vector<int> ans;
    for(int i=0;i<num.size();i++)
    {
        sumofArray += num[i];
    }
    sumToFind = sumofArray/3;

    for(int i=0;i<num.size();i++)
    {
        sum += num[i];
        if(sum == sumToFind)
        {
            ans.push_back(i);
            sum = 0;
        }

        if(sum != sumToFind && i == num.size()-1)
        {
            ans.push_back(-1);
            ans.push_back(-1);
        }
    }
    return ans;
}

int main()
{
    int n;
    cout<<"Enter the range: ";
    cin>>n;
    vector<int> num(n,0);
    cout<<"Enter "<<n<<" elements to the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }
    vector<int> ans = FindThePair(num);
    cout<<"The index pair is: "<<ans[0]<<" "<<ans[1];
    return 0;
}
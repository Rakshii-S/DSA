//Remove duplicates from sorted array
/*Given a sorted array arr[] of size n, the goal is to rearrange the array so that all distinct elements appear at the beginning in sorted order. Additionally, return the length of this distinct sorted subarray.

Note: The elements after the distinct ones can be in any order and hold any value, as they don’t affect the result.

Examples: 

Input: arr[] = [2, 2, 2, 2, 2]
Output: [2]
Explanation: All the elements are 2, So only keep one instance of 2.


Input: arr[] = [1, 2, 2, 3, 4, 4, 4, 5, 5]
Output: [1, 2, 3, 4, 5]

Input: arr[] = [1, 2, 3]
Output: [1, 2, 3]
Explanation : No change as all elements are distinct.*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void RemoveDuplicates(vector<int> &num)
{
    unordered_set<int>m;
    for(int i=0;i<num.size();i++)
    {
        if(m.find(num[i]) != m.end())
        {
            num.erase(num.begin()+i);
            i--;
        }else{
            m.insert(num[i]);
        }
    }
}

int main()
{
    int n;
    cout<<"Enter the count of elements: ";
    cin>>n;
    vector<int> num(n,0);
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }
    RemoveDuplicates(num);
    for(int i=0;i<num.size();i++)
    {
        cout<<num[i]<<" ";
    }
}
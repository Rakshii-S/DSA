//Leaders in an array
/*Given an array arr[] of size n, the task is to find all the Leaders in the array. An element is a Leader if it is greater than or equal to all the elements to its right side.

Note: The rightmost element is always a leader.

Examples:

Input: arr[] = [16, 17, 4, 3, 5, 2]
Output: [17 5 2]
Explanation: 17 is greater than all the elements to its right i.e., [4, 3, 5, 2], therefore 17 is a leader. 5 is greater than all the elements to its right i.e., [2], therefore 5 is a leader. 2 has no element to its right, therefore 2 is a leader.


Input: arr[] = [1, 2, 3, 4, 5, 2]
Output: [5 2]
Explanation: 5 is greater than all the elements to its right i.e., [2], therefore 5 is a leader. 2 has no element to its right, therefore 2 is a leader.

*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> Leaders(vector<int> &num)
{
    vector<int>ans;
    int i = 0, j = 1;
    while(i<num.size() && j<num.size())
    {
        if(num[i]>=num[j])
        {
            j++;
            if(j == num.size())
            {
                ans.push_back(num[i]);
                i++;
                j = i+1;
            }
        }else{
            i++, j=i+1;
        }
    }
    //has last element has no leading scores ahead so we consider it has one of the leader
    ans.push_back(num[num.size()-1]);
    return ans;
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
    vector<int> ans;
    ans = Leaders(num);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}
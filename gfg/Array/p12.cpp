//Remove All Occurrences of an Element in an Array

/*Given an integer array arr[] and an integer ele the task is to the remove all occurrences of ele from arr[] in-place and return the number of elements which are not equal to ele. If there are k number of elements which are not equal to ele then the input array arr[] should be modified such that the first k elements should contain the elements which are not equal to ele and then the remaining elements.

Note: The order of first k elements may be changed.

Examples:

Input: arr[] = [3, 2, 2, 3], ele = 3
Output: 2
Explanation: The answer is 2 because there are 2 elements which are not equal to 3 and arr[] will be modified such that the first 2 elements contain the elements which are not equal to 3 and remaining elements can contain any element. So, modified arr[] = [2, 2, _, _]

Input: arr[] = [0, 1, 3, 0, 2, 2, 4, 2], ele = 2
Output: 5
Explanation: The answer is 5 because there are 5 elements which are not equal to 2 and arr[] will be modified such that the first 5 elements contain the elements which are not equal to 2 and remaining elements can contain any element. So, modified arr[] = [0, 1, 3, 0, 4, _, _, _]*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int RemoveAllOccurrences(vector<int> &num, int ele)
{
    int count = 0;
    for(int i=0;i<num.size();i++)
    {
        if(num[i] != ele)
        {
            count+=1;
        }else{
            num.erase(num.begin()+i);
            i--;
        }
    }
    return count;
}
int main()
{
    int n, k;
    cout<<"Enter the range: ";
    cin>>n;
    vector<int> num(n,0);
    cout<<"Enter the values: ";
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }
    cout<<"Enter the sub element: ";
    cin>>k;
    int ans = RemoveAllOccurrences(num,k);

    cout<<"Count of elements not equal to sub element is: "<<ans<<endl;
    cout<<"Values after removing sub element: ";
    for(int i=0;i<num.size();i++)
    {
        cout<<num[i]<<" ";
    }
}
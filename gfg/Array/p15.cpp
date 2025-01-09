//Insert duplicate of K adjacent to it for it’s every occurrence in array
/*Given an array arr consisting of N integers and an integer K, the task is to insert an adjacent K for every occurrence of it in the original sequence and then truncate the array to the original length using an O(1) auxiliary space.

Examples:  


Input: arr[] = {1, 0, 2, 3, 0, 4, 5, 0}, K = 0 
Output: {1, 0, 0, 2, 3, 0, 0, 4} 
Explanation: 
The given array {1, 0, 2, 3, 0, 4, 5, 0} is modified to {1, 0, 0, 2, 3, 0, 0, 4] after insertion of two 0’s and truncation of extra elements.


Input: arr[] = {7, 5, 8}, K = 8 
Output: {7, 5, 8} 
Explanation: 
After inserting an adjacent 8 into the array, it got truncated to restore the original size of the array.  

*/

#include <iostream>
#include <vector>

using namespace std;

void InsertDup(vector<int> &num, int k)
{
    for(int i=0;i<num.size();i++)
    {
        if(num[i] == k)
        {
            num.insert(num.begin()+(i+1), k);
            i++;
            num.pop_back();
        }
    }
}

int main()
{
    int n, k;
    cout<<"Enter the count of elements: ";
    cin>>n;
    vector<int> num(n,0);
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }
    cout<<"Enter an k element: ";
    cin>>k;
    InsertDup(num,k);
    for(int i=0;i<n;i++)
    {
        cout<<num[i]<<" ";
    }
}
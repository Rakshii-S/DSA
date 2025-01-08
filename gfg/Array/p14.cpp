// Rearrange array elements by sign
/*Given an array arr[] of size n, the task is to rearrange it in alternate positive and negative manner without changing the relative order of positive and negative numbers. In case of extra positive/negative numbers, they appear at the end of the array.

Note: The rearranged array should start with a positive number and 0 (zero) should be considered as a positive number.

Examples: 

Input:  arr[] = {1, 2, 3, -4, -1, 4}
Output: arr[] = {1, -4, 2, -1, 3, 4}


Input:  arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8}
Output: arr[] = {-5, 5, -2, 2, -8, 4, 7, 1, 8, 0}

*/

#include <iostream>
#include <vector>

using namespace std;

void RearrangeEle(vector<int> &num)
{
    vector<int> pos, neg;
    for(int i=0;i<num.size();i++)
    {
        if(num[i]>=0)
        {
            pos.push_back(num[i]);
        }else{
            neg.push_back(num[i]);
        }
    }

    int idx1 = 0, idx2 = 0, idx=0;
    while(idx1<pos.size() && idx2<neg.size())
    {
        if(idx%2 == 0)
        {
            num[idx++] = pos[idx1++];
        }else{
            num[idx++] = neg[idx2++];
        }
    }

    while(idx1<pos.size())
    {
        num[idx++] = pos[idx1++];
    }

    while(idx2<neg.size())
    {
        num[idx++] = neg[idx2++];
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
    RearrangeEle(num);
    for(int i=0;i<num.size();i++)
    {
        cout<<num[i]<<" ";
    }
    return 0;
}
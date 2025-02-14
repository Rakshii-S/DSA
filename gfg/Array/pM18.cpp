//Majority Element II – Elements occurring more than ⌊N/3⌋ times

/*Given an array arr[] consisting of n integers, the task is to find all the array elements which occurs more than floor(n/3) times.
Note: The returned array of majority elements should be sorted.*/

/*Examples:
Input: arr[] = {2, 2, 3, 1, 3, 2, 1, 1}
Output: {1, 2}
Explanation: The frequency of 1 and 2 is 3, which is more than floor n/3 (8/3 = 2).


Input: arr[] = {-5, 3, -5}
Output: {-5}
Explanation: The frequency of -5 is 2, which is more than floor n/3 (3/3 = 1).


Input: arr[] = {3, 2, 2, 4, 1, 4}
Output: { }
Explanation: There is no majority element.*/

/*Approach -> The idea is based on the observation that there can be at most two majority elements, which appear more than n/3 times. so we can use Boyer-Moore’s Voting algorithm. As we iterate the array, We identify potential majority elements by keeping track of two candidates and their respective counts.*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> MajorityEle2(vector<int> &num)
{
    int ele1 = -1, ele2 = -1, count1 = 0, count2 = 0;
    for(int i=0;i<num.size();i++)
    {
        if(ele1 == num[i])
            count1++;
        else if(ele2 == num[i])
            count2++;
        else if(count1 == 0)
        {
            ele1 = num[i];
            count1++;
        }else if(count2 == 0)
        {
            ele2 = num[i];
            count2++;
        }else{
            count1--;
            count2--;
        }
    }
    count1 = 0, count2 = 0;
    vector<int> res;
    for(int val:num)
    {
        if(val == ele1) count1++;
        if(val == ele2) count2++;
    }

    if(count1 > num.size()/3) res.push_back(ele1);
    if(count2 > num.size()/3 && ele1!=ele2) res.push_back(ele2);

    if(res.size() == 2 && res[0]>res[1])
        swap(res[0],res[1]);
    return res;
}

int main()
{
    int size;
    cout<<"Enter the size: ";
    cin>>size;
    vector<int> num(size,0);
    cout<<"Enter "<<size<<" elements: ";
    for(int i=0;i<size;i++)
    {
        cin>>num[i];
    }
    vector<int> ans  = MajorityEle2(num);
    if(ans.empty())
        cout<<"No majority element found.";
    else    
        cout<<"The elements are ";
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
    return 0;
}
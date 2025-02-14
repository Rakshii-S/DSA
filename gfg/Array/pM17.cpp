//Majority Element

//Given an array arr. Find the majority element in the array. If no majority exists, return -1. A majority element in an array is an element that appears strictly more than arr.size() / 2 times in the array.

/*Input : arr[] = {1, 1, 2, 1, 3, 5, 1}
Output : 1
Explanation: Note that 1 appear 4 times which is more than  7 / 2 times 


Input : arr[] = {3, 3, 4, 2, 4, 4, 2, 4}
Output :  -1 
Explanation: There is no element whose frequency is greater than the half of the size of the array size.


Input : arr[] = {3}
Output : 3
Explanation: Appears more than n/2 times*/

#include <iostream>
#include <vector>
using namespace std;

int MajorityEle(vector<int> &num)
{
    int freq = 0, currEle, maxElem = -1;
    for(int i=0;i<num.size();i++)
    {
        if(freq == 0)
            currEle = num[i];
        if(currEle == num[i])
        {
            freq++;
        }else{
            freq--;
        }
        if(freq > num.size()/2)
            maxElem = max(currEle, maxElem);
    }
    return maxElem;
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
    int ans  = MajorityEle(num);
    if(ans == -1)
        cout<<"No majority element found.";
    else    
        cout<<"The element is "<<ans;
    return 0;
    
}
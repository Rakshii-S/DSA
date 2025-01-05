// Reverse an Array in groups of given size

/*Given an array arr[] and an integer K, the task is to reverse every subarray formed by consecutive K elements.

Examples: 

Input: arr[] = [1, 2, 3, 4, 5, 6, 7, 8, 9], K = 3 
Output: 3, 2, 1, 6, 5, 4, 9, 8, 7


Input: arr[] = [1, 2, 3, 4, 5, 6, 7, 8], K = 5 
Output: 5, 4, 3, 2, 1, 8, 7, 6


Input: arr[] = [1, 2, 3, 4, 5, 6], K = 1 
Output: 1, 2, 3, 4, 5, 6


Input: arr[] = [1, 2, 3, 4, 5, 6, 7, 8], K = 10 
Output: 8, 7, 6, 5, 4, 3, 2, 1*/

#include <iostream>
#include <vector>

using namespace std;

int ReverseSubArray(vector<int> &num, int k)
{
    int n = num.size(), st = 0, en= k-1, lastPos = en;
    bool finalLoop = false;

    while(st<=en)
    {
        if(st == en && finalLoop == false)
        {
            st = lastPos+1;
            en = lastPos+k;
            //this is when it reaches the final loop that is when end value exceeds num size we will reset it to num size -1
            if(en > n) 
            {
                en = n-1;
                finalLoop = true;
            }
            lastPos = en;
        }else if(finalLoop == true)
        {
            return 0;
        }
        if(st<en) // because there are cases where st value exceeds en value while reseting the positions as per k number of elements
        {
            swap(num[st], num[en]);
            st++,en--;
        }
    }
}
int main()
{
    int n,k;
    cout<<"Enter the range: ";
    cin>>n;
    vector<int> num(n,0);
    cout<<"Enter the values: ";
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }

    cout<<"Enter the break point ie k: ";
    cin>>k;

    ReverseSubArray(num,k);

    //output
    for(int i=0;i<n;i++)
    {
        cout<<num[i]<<" ";
    }
}
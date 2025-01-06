//Sort an array in wave form

/*Given an unsorted array of integers, sort the array into a wave array. An array arr[0..n-1] is sorted in wave form if:
arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= …..

Input:  arr[] = {10, 5, 6, 3, 2, 20, 100, 80}
Output: arr[] = {10, 5, 6, 2, 20, 3, 100, 80} 
Explanation: 
here you can see {10, 5, 6, 2, 20, 3, 100, 80} first element is larger than the second and the same thing is repeated again and again. large element – small element-large element -small element and so on .it can be small element-larger element – small element-large element -small element too. all you need to maintain is the up-down fashion which represents a wave. there can be multiple answers.


Input: arr[] = {20, 10, 8, 6, 4, 2}
Output: arr[] = {20, 8, 10, 4, 6, 2}*/

#include <iostream>
#include <vector>

using namespace std;

void WaveForm(vector<int> &num)
{
    int n = num.size();
    for(int i=0;i<num.size()-1;i++)
    {
            if((i+1) % 2 == 0)
            {
                if(num[i]<=num[i+1]) 
                    continue;
                else
                    swap(num[i],num[i+1]);
            }else{
                if(num[i]>=num[i+1])
                    continue;
                else
                    swap(num[i],num[i+1]);
            }
    }
}
int main()
{
    int n;
    cout<<"Enter the range: ";
    cin>>n;
    vector<int> num(n,0);
    cout<<"Enter the values: ";
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }

    WaveForm(num);

    cout<<"Value of array after rotating: ";
    for(int i=0;i<n;i++)
    {
        cout<<num[i]<<" ";
    }
    return 0;
}
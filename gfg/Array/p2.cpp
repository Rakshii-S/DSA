//Third Largest Element

/*Given an array of n integers, find the third largest element. All the elements in the array are distinct integers. 
Example : 

Input: arr[] = {1, 14, 2, 16, 10, 20}
Output: The third Largest element is 14

Explanation: Largest element is 20, second largest element is 16 
and third largest element is 14

Input: arr[] = {19, -10, 20, 14, 2, 16, 10}
Output: The third Largest element is 16

Explanation: Largest element is 20, second largest element is 19 
and third largest element is 16 */

#include <iostream>
#include <vector>

using namespace std;

int ThirdLargestEle(vector<int> &num)
{
    int first = -1, second = -1, third = -1;
    for(int i=0;i<num.size();i++)
    {
        if(num[i]>first)
        {
            third = second;
            second = first;
            first = num[i];
        }else if(num[i]>second && num[i]<first)
        {
            third = second;
            second = num[i];
        }else if(num[i]>third && num[i]<first && num[i]<second)
        {
            third = num[i];
        }
    }
    return third;
}
int main()
{
    int n;
    cout<<"Enter the range: ";
    cin>>n;

    if(n<3)
    {
        cout<<"Array size should be greater than or equal to 3.";
        return 0;
    }
    vector<int> num(n,0);
    cout<<"Enter the values: ";
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }

    int ans = ThirdLargestEle(num);
    if(ans == -1)
        cout<<"Third largest element does not exist.";
    else
        cout<<"The third largest element is: "<<ans;
}

//other method is using sort function and slicing -> time complexity will be O(nlogn)
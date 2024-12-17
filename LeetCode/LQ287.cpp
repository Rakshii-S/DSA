#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the range: ";
    cin>>n;
    vector<int>nums(n,0);
    cout<<"Enter the values: ";
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }

    //calculations
    int slow = nums[0], fast = nums[0];
    do 
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }while(slow!=fast);

    slow = nums[0];
    while(slow!=fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    cout<<"Duplicate value is: "<<slow;
}
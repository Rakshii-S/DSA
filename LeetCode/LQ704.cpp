#include <iostream>
#include <vector>
using namespace std;

int BinarySearch(int st , int en, vector<int> nums, int target)
{
    if(st<=en)
    {
        int mid = st+(en-st)/2;
        if(nums[mid] == target) 
            return mid;
        else if(nums[mid]>target) 
            return BinarySearch(st, mid-1, nums, target);
        else
            return BinarySearch(mid+1, en, nums, target);
    }
    return -1;
}
int main()
{
    vector<int> nums = {4,7,8,9,10};
    int target = 7, st = 0, en = nums.size()-1;
    int ans = BinarySearch(st,en,nums, target);
    if(ans == -1)
        cout<<"Not found.";
    else
        cout<<"Found at index "<<ans;
}
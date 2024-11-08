#include <iostream>
#include <vector>
using namespace std;

int DNFAlgorithm(vector<int> &nums, int n)
{
    int low = 0, mid = 0, high = n-1;
    while(mid <= high)
    {
        if(nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            mid++;
            low++;
        }else if(nums[mid] == 1)
        {
            mid++;
        }else{
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}
int main()
{
    int n;
    cout<<"Enter the range: ";
    cin>>n;
    vector<int> nums(n,0);
    cout<<"Enter "<<n<<" elements to the array (only 0s, 1s, 2s):";
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    DNFAlgorithm(nums,n);
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
}
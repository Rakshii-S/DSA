#include <iostream>
#include <vector>
using namespace std;

int NextPermutation(vector<int> &nums, int n)
{
    int pivot = -1, i, j;
    //find pivot
    for(int i=n-2;i>=0;i--)
    {
        if(nums[i]<nums[i+1])
        {
            pivot = i;
            break;
        }
    }
    //if there is no pivot element which means the entire array is in descending order then we reverse it
    i=0, j=n-1;
    if(pivot == -1)
    {
        reverse(nums.begin(), nums.end());
        return 0;
    }

    //find the right most element
    for(i=n-1;i>pivot;i--)
    {
        if(nums[i]>nums[pivot])
        {
            swap(nums[i], nums[pivot]);
            break;
        }
    }

    //reverse (pivot+1) to n-1
    i=pivot+1,j=n-1;
    while(i<=j)
    {
        swap(nums[i], nums[j]);
        i++;
        j--;
    }
    return 0;
}
int main()
{
   int n;
   cout<<"Enter the range: ";
   cin>>n;
   vector<int> nums(n,0);
   cout<<"Enter "<<n<<" elements: ";
   for(int i=0;i<n;i++)
   {
    cin>>nums[i];
   }
    NextPermutation(nums,n);
    cout<<"The next permutation of the given array is: ";
    for(int i=0;i<n;i++)
    {
        cout<<nums[i]<<" ";
    }
}
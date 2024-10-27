#include <iostream>
using namespace std;

int MajorityEle(int n, int nums[])
{
    int freq =0, ans = 0;
    for(int i=0;i<n;i++)
    {
        if(freq == 0)
        {
            ans =nums[i];
        }
        if(ans == nums[i])
        {
            freq++;
        }else{
            freq--;
        }
    }
    return ans;
}
int main()
{
    int n, arr[30];
    cout<<"Enter the size: ";
    cin>>n;
    cout<<"Enter "<<n<<" elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Majority element is: "<<MajorityEle(n,arr);
}
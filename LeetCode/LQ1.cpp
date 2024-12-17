#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    int n,s, first, second;
    cout<<"Enter the range: ";
    cin>>n;
    vector<int> nums(n,0);
    unordered_map<int,int>val;
    cout<<"Enter "<<n<<" values: ";
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    cout<<"Enter the target sum: ";
    cin>>s;
    for(int i=0;i<n;i++)
    {
        first = nums[i];
        second = s  - first;
        if(val.find(second) != val.end())
        {
            cout<<"Two values that make the sum are found in index: ";
            cout<<val[second]<<" and "<<i;
            return 0;
        }
        val[first] = i;
    }
    cout<<"No values found.";
}
#include <iostream>
#include <vector>
using namespace std;

int SingleEle(vector<int> &vec, int n)
{
    int ans =0;
    for(int val:vec)
    {
        ans ^= val;
    }
    return ans;
}
int main()
{
    int n;
    cout<<"Enter the size: ";
    cin>>n;
    cout<<"Enter the elements: ";
    vector<int> vec(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
    }
    cout<<"The single element is: "<<SingleEle(vec,n);
}

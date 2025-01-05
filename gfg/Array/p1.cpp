//Second Largest Element 
#include <iostream>
#include <vector>

using namespace std;

int SecondLargestEle(vector<int> &num)
{
    int first = -1, second=-1;
    for(int i=0;i<num.size();i++)
    {
        if(num[i]>first)
        {
            second = first;
            first = num[i];
        }else if(num[i]>second && num[i]<first)
        {
            second = num[i];
        }
    }
    return second;
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

    int ans = SecondLargestEle(num);
    if(ans == -1)
        cout<<"Second largest element does not exist.";
    else
        cout<<"The second largest element is: "<<ans;
}
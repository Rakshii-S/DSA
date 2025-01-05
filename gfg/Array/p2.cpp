//Third Largest Element
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
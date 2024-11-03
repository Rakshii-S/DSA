#include <iostream>
#include <vector>
using namespace std;

int SingleSortedEle(vector<int> &vec, int n)
{
    int st=1 ,en=n-2, mid;
    while(st<=en)
    {
        mid = st + (en-st)/2;
        if( mid == 0  && vec[0]!= vec[1])
            return vec[mid];
        if(mid == n-1 && vec[n-1]!=vec[n-2])
            return vec[mid];
        if(vec[mid-1] != vec[mid] && vec[mid] != vec[mid+1])
            return vec[mid];
        if(mid%2 == 0)//even 
        {
            if(vec[mid-1]== vec[mid])
            {
                en = mid-1;
            }else{
                st = mid+1;
            }
        }else //odd
        {
            if(vec[mid-1] == vec[mid])
            {
                st = mid+1;
            }else{
                en = mid-1;
            }
        }
    }
    return -1;
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
    cout<<"The single element in a sorted array is: "<<SingleSortedEle(vec,n);
}
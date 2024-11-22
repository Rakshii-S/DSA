#include <iostream>
#include <vector>
using namespace std;

int Display(vector<int> &nums)
{
    for(int i=0;i<nums.size(); i++)
    {
        cout<<nums[i]<<" ";
    }
}

int Decrypt(vector<int> &vals, int k)
{
    int n = vals.size();
    vector<int> results(n,0);
    int start = 1, end = k, sum =0;

    if(k==0)
    {
        Display(results);
        return 0;
    }

    if(k<0)
    {
        start = n-abs(k);
        end = n-1;
    }
    //find sum 
    for(int i=start;i<=end;i++)
    {
        sum += vals[i];
    }

    for(int i=0;i<n;i++)
    {
        results[i] = sum;
        sum -= vals[start%n];
        sum += vals[(end+1)%n];
        start++, end++;
    }
    Display(results);
}

int main()
{
    vector<int> vec1={2,4,9,3};
    vector<int> vec2={5,7,1,4};
    vector<int> vec3={3,2,9,1};

    //negative
    cout<<"The set of values ";
    Display(vec1);
    cout<<" when the k is less than 0 (k<0) ";
    Decrypt(vec1,-2);

    //positive
    cout<<"\n\nThe set of values ";
    Display(vec2);
    cout<<" when the k is greater than 0 (k>0) ";
    Decrypt(vec2,3);

    //zero
    cout<<"\n\nThe set of values ";
    Display(vec3);
    cout<<" when the k is equal to 0 (k == 0) ";
    Decrypt(vec3,0);
}
//Three Great Candidates
//Maximum product of a triplet(subsequence of size 3) in array
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cout<<"Enter the range: ";
    cin>>n;

    if(n<3)
    {
        cout<<"Array size should be greater than or equal to 3.";
        return 0;
    }
    vector<int> num(n,0);
    cout<<"Enter the values: ";
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }
}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int IsPossible(int minDist, vector<int> &dist, int n, int c)
{
    int cow = 1, LastStallPos=dist[0];
    for(int i=0;i<n;i++)
    {
        if(dist[i]-LastStallPos>=minDist)
        {
            cow++;
            LastStallPos =dist[i];
        }
        if(cow == c)
        {
            return true;
        }
    }
    return false;
}
int AggressiveCow(vector<int> &dist, int n, int c)
{   
    int st=1, en = dist[n-1]-dist[0], mid, ans=-1;
    while(st<=en)
    {
        mid = st + (en- st)/2;
        if(IsPossible(mid,dist,n,c))
        {
            st = mid+1;
            ans = mid;
        }else{
            en = mid-1;
        }
    }
    return ans;
}
int main()
{
    int n, c;
    cout<<"Enter the number of stalls: ";
    cin>>n;
    cout<<"Enter the number of cows: ";
    cin>>c;
    vector<int> dist(n,0);
    cout<<"Enter the distance between each stall: ";
    for(int i=0;i<n;i++)
    {
        cin>>dist[i];
    }
    sort(dist.begin(), dist.end());
    int ans = AggressiveCow(dist,n,c);
    cout<<"The maximum distance among minimum distance is: "<<ans;
}
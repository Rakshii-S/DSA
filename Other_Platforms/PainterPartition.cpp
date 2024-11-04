#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int IsValid(int maxTime, vector<int> &len, int n, int p)
{
    int painter = 1, time=0;
    for(int i=0;i<n;i++){
        if(time+len[i]<=maxTime)
        {
            time+=len[i];
        }else{
            time = len[i];
            painter++;
        }
    }
    return painter>p? false:true;
}
int PainterPartition(vector<int> &len, int n, int p)
{
    int sum = 0, maxArr=INT_MIN;
    for(int i=0;i<n;i++)
    {
        sum+= len[i];
        maxArr = max(maxArr, len[i]);
    }
    int st = maxArr, en =sum, mid, ans=-1;
    while(st<=en)
    {
        mid = st + (en- st)/2;
        if(IsValid(mid, len, n, p))
        {
            en = mid-1;
            ans= mid;
        }
        else{
            st =mid+1;
        }
    }
    return ans;
}

int main()
{
    int n, p;
    cout<<"Enter the number of boards: ";
    cin>>n;
    cout<<"Enter the number of painters: ";
    cin>>p;
    vector<int> length(n,0);
    cout<<"Enter the length of each board: ";
    for(int i=0;i<n;i++){
        cin>>length[i];
    }
    int ans = PainterPartition(length,n,p);
    if( ans == -1){
        cout<<"Painters partition problem is not possible.";
    }else{
        cout<<"The minimum possible time among maximum time to paint all boards is: "<<ans;
    }
}
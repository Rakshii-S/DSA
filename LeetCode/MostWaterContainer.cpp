#include <iostream>
#include <vector>
using namespace std;

int MostWaterContainer(vector<int> h, int n)
{
    int lh=0, rh =n-1, ans =0, width, height, area;
    while(lh<rh)
    {
        width = rh - lh;
        height = min(h[lh], h[rh]);
        area = width * height;
        ans =max(ans, area);
        h[lh]<h[rh]? lh++:rh--;
    }
    return ans;
}
int main()
{
    int n;
    cout<<"Enter the number of heights: ";
    cin>>n;
    vector<int> heights(n,0);
    cout<<"Enter the heights: ";
    for(int i=0;i<n;i++)
    {
        cin>>heights[i];
    }
    cout<<"Maximum amount of water a container can store is: "<<MostWaterContainer(heights,n);
}
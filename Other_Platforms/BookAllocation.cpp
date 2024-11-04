#include <iostream>
#include <vector>
using namespace std;

int IsValid(int maxPages, vector<int> &pages, int n, int m)
{
    int stu = 1, p =0;
    for(int i=0;i<n;i++)
    {
        if(pages[i]> maxPages)
            return false;
        if(p+pages[i] <= maxPages)
        {
            p += pages[i];
        }
        else{
            stu++;
            p = pages[i];
        }
    }
    return stu>m? false: true;
}
int BookAllocation(int n, int m, vector<int> &pages)
{
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        sum+=pages[i];
    }
    int st = 0, en =sum, mid, ans=-1;
    while(st<=en)
    {
        mid = st +(en-st)/2;
        if(IsValid(mid,pages,n,m))
        {
            en = mid-1;
            ans = mid;
        }else
        {
            st = mid+1;
        }
    }
    return ans;
}
int main()
{
    int n, m;
    cout<<"Enter the count of books: ";
    cin>>n;
    cout<<"Enter the number of students: ";
    cin>>m;
    vector<int> pages(n,0);
    cout<<"Enter the count of pages in each book: ";
    for(int i=0;i<n;i++)
    {
        cin>>pages[i];
    }
    int ans = BookAllocation(n,m,pages);
    if(ans == -1)
    {
        cout<<"Book allocation to all the students is not possible.";
    }else{
        cout<<"Minimum pages among the maximum pages is: "<<ans;
    }
}